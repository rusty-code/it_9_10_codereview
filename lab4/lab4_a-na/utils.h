#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>

int input_int(const std::string& prompt, int min = INT_MIN, int max = INT_MAX);
std::string input_string(const std::string& prompt, bool allow_empty = false);
std::string input_name(const std::string& prompt);

#endif // UTILS_H