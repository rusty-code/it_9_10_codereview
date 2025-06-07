#include <string>
#include "name.h"

Name::Name(const std::string& last, const std::string& first, const std::string& middle)
    : _last_name(last), _first_name(first), _middle_name(middle) {
}

std::string Name::to_string() const {
    std::string result;
    if (!_last_name.empty()) {
        result += _last_name;
    }
    if (!_first_name.empty()) {
        if (!result.empty()) result += " ";
        result += _first_name;
    }
    if (!_middle_name.empty()) {
        if (!result.empty()) result += " ";
        result += _middle_name;
    }
    return result;
}

std::string Name::get_last_name() const {
    return _last_name;
}

std::string Name::get_first_name() const {
    return _first_name;
}

std::string Name::get_middle_name() const {
    return _middle_name;
}