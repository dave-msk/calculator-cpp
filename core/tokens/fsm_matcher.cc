#include <unordered_map>
#include "yaml-cpp/yaml.h"
#include "core/tokens/fsm_matcher.h"


namespace calculator {
namespace tokens {

FSMMatcher<u_char> CreateNumberMatcher(const std::string &filename) {
  YAML::Node config = YAML::LoadFile(filename);
  std::unordered_map<std::string, u_char> map;

  // Construct root state
  const YAML::Node &root_node = config["root"];
  map[std::string{"root"}] = 0;
  fsm::State<u_char, char> root{0, false};
  for (auto it = root_node.begin(); it != root_node.end(); ++it) {
    const std::string &target = it->first.as<std::string>();
    const u_char id = map[target] = (u_char) map.size();
    const std::string &ops = it->second.as<std::string>();
    for (const char &c : ops) root.AddTransition(c, id);
  }

  // Construct graph
  fsm::Graph<u_char, char> graph{root};
  const YAML::Node &states = config["states"];
  for (auto state_it = states.begin(); state_it != states.end(); ++state_it) {
    const YAML::Node &state_node = state_it->second;
    const std::string &src = state_it->first.as<std::string>();

    if (map.find(src) == map.end()) map[src] = (u_char) map.size();
    const u_char id = map[src];
    bool is_terminal = state_node["terminal"].as<bool>();
    fsm::State<u_char, char> state{id, is_terminal};

    const YAML::Node &transitions = state_node["transitions"];
    for (auto tr_it = transitions.begin();
         tr_it != transitions.end();
         ++tr_it) {
      const std::string &target = tr_it->first.as<std::string>();
      if (map.find(target) == map.end()) map[target] = (u_char) map.size();
      const u_char t_id = map[target];
      const std::string &ops = tr_it->second.as<std::string>();

      for (const char &c : ops) state.AddTransition(c, t_id);
    }
    graph << state;
  }
  return FSMMatcher<u_char>{std::move(graph)};
}

}  // namespace tokens
}  // namespace calculator