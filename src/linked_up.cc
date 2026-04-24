#include "linked_up.hpp"

LinkedUp::LinkedUp(const std::string& people_file,
                   const std::string& connections_file) {
  std::ifstream people(people_file);
  std::ifstream connections(connections_file);
  // TODO
}

void LinkedUp::AddPerson(const std::string& name) {
  (void)name;
  // TODO
}
void LinkedUp::AddConnection(const std::string& person_one,
                             const std::string& person_two) {
  (void)person_one;
  (void)person_two;
  // TODO
}
std::vector<std::vector<std::string>> LinkedUp::GetCliques() {
  // TODO
  return {};
}
int LinkedUp::FindShortestLinkageLength(const std::string& person_one,
                                        const std::string& person_two) {
  (void)person_one;
  (void)person_two;
  // TODO
  return -1;
}
std::vector<std::string> LinkedUp::FindShortestLinkagePath(
    const std::string& person_one, const std::string& person_two) {
  (void)person_one;
  (void)person_two;
  // TODO
  return {};
}
std::vector<std::string> LinkedUp::FindNthDegreeConnections(
    const std::string& person, int degree) {
  (void)person;
  (void)degree;
  // TODO
  return {};
}
std::map<std::string, std::vector<std::string>>& LinkedUp::GetNetwork() {
  return network_;
}
std::vector<std::string> LinkedUp::Split(const std::string& str,
                                         char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream token_stream(str);
  while (std::getline(token_stream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}
