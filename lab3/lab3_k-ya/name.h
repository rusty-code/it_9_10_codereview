#ifndef NAME_H
#define NAME_H

#include <string>

class Name {
private:
    std::string _last_name;
    std::string _first_name;
    std::string _middle_name;

public:
    Name(const std::string& last = "", const std::string& first = "", const std::string& middle = "");
    std::string to_string() const;
    std::string get_last_name() const;
    std::string get_first_name() const;
    std::string get_middle_name() const;
};

#endif