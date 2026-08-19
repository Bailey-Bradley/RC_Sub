#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(std::string command_string) {
  std::istringstream stream(command_string);
  std::vector<std::string> arguments;

  std::string argument;
  while (stream >> argument) {
    arguments.push_back(argument);
  }

  return arguments;
}

bool startsWith(const std::string& str1, const std::string& str2) {
  int compare_len = str1.length() < str2.length() ? str1.length() : str2.length();

  return !str1.compare(0, compare_len, str2, 0, compare_len);
}