#pragma once
#ifndef NAME_H
#define NAME_H

#include <string>

class Name {
private:
    std::string _surname;
    std::string _first_name;
    std::string _patronymic;

public:
    Name();
    explicit Name(std::string _f_name);
    Name(std::string _f_name, std::string _s_name);
    Name(std::string _f_name, std::string _s_name, std::string _p_name);

    std::string to_string() const;
    void print() const;
    static Name input_from_keyboard();
};

#endif // NAME_H
