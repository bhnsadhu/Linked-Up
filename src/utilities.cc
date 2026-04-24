#include "utilities.hpp"

std::ostream& operator<<(std::ostream& os, const LinkedUp& network) {
  std::set<std::string> visited;
  std::queue<std::string> to_visit;
  int i = 0;
  for (auto const& [person, friends] : network.network_) {
    bool entered = false;
    if (!visited.contains(person)) {
      to_visit.push(person);
      os << "(Connected Component #" << ++i << "):"
         << "\n\n";
    }
    std::set<std::string> queued;
    while (!to_visit.empty()) {
      entered = true;
      std::string current_person = to_visit.front();
      if (visited.contains(current_person)) {
        to_visit.pop();
        continue;
      }
      visited.insert(current_person);
      to_visit.pop();
      std::vector<std::string> neighbors;
      os << current_person;
      for (const auto& relation : network.network_.at(current_person)) {
        if (!visited.contains(relation)) {
          to_visit.push(relation);
          queued.insert(relation);
        }
        neighbors.push_back(relation);
      }
      std::string white_space = current_person;
      white_space.replace(0, white_space.size(), white_space.size(), ' ');
      for (unsigned int i = 0; i < neighbors.size(); ++i) {
        if (i != 0) os << white_space << "|\n" << white_space;
        os << " --------- " << neighbors.at(i) << "\n";
      }
      os << std::endl;
    }
    if (entered) os << "######################\n\n";
  }
  return os;
}