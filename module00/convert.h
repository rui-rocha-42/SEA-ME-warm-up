//
// Created by CTW03389 on 07/11/2024.
//

#ifndef CONVERT_H
#define CONVERT_H

#include <vector>

bool validate_command(const std::string&);
std::string uppercase_string(const std::string&);
std::string lowercase_string(const std::string&);

// Available commands
const std::vector<std::string> commands = { "up", "down" };

#endif //CONVERT_H
