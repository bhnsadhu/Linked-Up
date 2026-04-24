#include <iostream>

#include "linked_up.hpp"
#include "utilities.hpp"
int main() {
  LinkedUp network("sample/person.csv", "sample/relationship.csv");

  // Print network overview
  std::cout << "Network Overview:\n" << network << std::endl;

  // Find and print cliques
  std::cout << "\nCliques:\n";
  auto cliques = network.GetCliques();
  for (const auto& clique : cliques) {
    for (const auto& member : clique) {
      std::cout << member << " ";
    }
    std::cout << std::endl;
  }
  // Find shortest linkage
  std::string person1 = "Bob", person2 = "Linda";
  std::cout << "\nShortest Linkage from " << person1 << " to " << person2
            << ":\n";
  std::cout << "Distance: "
            << network.FindShortestLinkageLength(person1, person2) << std::endl;

  // Print shortest path
  std::cout << "Path: ";
  auto path = network.FindShortestLinkagePath(person1, person2);
  for (const auto& connection : path) {
    std::cout << connection << " ";
  }
  std::cout << std::endl;

  // Find connections at specific range
  auto connections = network.FindNthDegreeConnections("Bob", 2);
  for (const auto& c : connections) {
    std::cout << c << " ";
  }
  std::cout << std::endl;

  return 0;
}
