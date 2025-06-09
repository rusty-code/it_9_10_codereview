#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <string>

int input_int(const std::string& _prompt, int _min = INT_MIN, int _max = INT_MAX);
std::string input_string(const std::string& _prompt, bool _allow_empty = false);
std::string input_name(const std::string& _prompt);

#endif // UTILS_H
