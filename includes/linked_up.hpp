#ifndef LINKED_UP_HPP
#define LINKED_UP_HPP
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class LinkedUp {
public:
  LinkedUp() = default;
  LinkedUp(const std::string& people_file, const std::string& connections_file);
  void AddPerson(const std::string& name);
  void AddConnection(const std::string& person_one,
                     const std::string& person_two);
  std::vector<std::vector<std::string>> GetCliques();
  int FindShortestLinkageLength(const std::string& person_one,
                                const std::string& person_two);
  std::vector<std::string> FindShortestLinkagePath(
      const std::string& person_one, const std::string& person_two);
  std::vector<std::string> FindNthDegreeConnections(const std::string& person,
                                                    int degree);

  friend std::ostream& operator<<(std::ostream& os, const LinkedUp& network);

  std::map<std::string, std::vector<std::string>>& GetNetwork();

private:
  std::vector<std::string> Split(const std::string& str, char delimiter);
  std::map<std::string, std::vector<std::string>> network_;
};

#endif
