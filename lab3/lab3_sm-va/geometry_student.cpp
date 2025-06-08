#include "geometry_student.h"

Point::Point(double x, double y) : _x(x), _y(y) {}

std::string Point::print() const {
    std::ostringstream oss;
    auto format_number = [](double num) {
        std::ostringstream num_stream;
        if (num == floor(num)) {
            num_stream << static_cast<int>(num);
        }
        else {
            num_stream << std::fixed << std::setprecision(2) << num;
            std::string s = num_stream.str();
            s.erase(s.find_last_not_of('0') + 1, std::string::npos);
            if (s.back() == '.') {
                s.pop_back();
            }
            return s;
        }
        return num_stream.str();
        };
    oss << "{" << format_number(_x) << ";" << format_number(_y) << "}";
    return oss.str();
}

double Point::get_x() const { return _x; }
double Point::get_y() const { return _y; }


Line::Line(const Point& start, const Point& end) : _start(start), _end(end) {}

std::string Line::print() const {
    return "Линия от " + _start.print() + " до " + _end.print();
}

void Line::set_start(const Point& new_start) { _start = new_start; }
void Line::set_end(const Point& new_end) { _end = new_end; }
Point Line::get_start() const { return _start; }
Point Line::get_end() const { return _end; }


Student::Student(const std::string& name, const std::vector<int>& grades)
    : _name(name), _grades(grades) {
}

std::string Student::print() const {
    std::string result = _name + ": [";
    for (size_t i = 0; i < _grades.size(); ++i) {
        result += std::to_string(_grades[i]);
        if (i < _grades.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

double Student::average() const {
    if (_grades.empty()) return 0;
    double sum = 0;
    for (int grade : _grades) sum += grade;
    return sum / _grades.size();
}

bool Student::is_excellence() const {
    return average() == 5.0;
}

void Student::set_grades(const std::vector<int>& new_grades) {
    _grades = new_grades;
}

std::vector<int> Student::get_grades() const {
    return _grades;
}

int input_integer() {
    int number;
    while (true) {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return number;
        }
    }
}

Point input_point(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        std::istringstream iss(input);
        double x, y;
        if (iss >> x >> y) {
            std::string remaining;
            if (iss >> remaining) {
                std::cout << "Некорректный ввод. Пожалуйста, введите два числа через пробел.\n";
            }
            else {
                return Point(x, y);
            }
        }
        else {
            std::cout << "Некорректный ввод. Пожалуйста, введите два числа через пробел.\n";
        }
    }
}

bool is_valid_grade(int grade) {
    return grade >= 2 && grade <= 5;
}

bool is_valid_grades_input(const std::string& input) {
    std::regex pattern(R"(^(\d+\s*)+$)");
    return std::regex_match(input, pattern);
}

std::vector<int> input_grades(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        if (!is_valid_grades_input(input)) {
            std::cout << "Некорректный ввод. Пожалуйста, введите только числа через пробел.\n";
            continue;
        }

        std::istringstream iss(input);
        std::vector<int> grades;
        int grade;
        while (iss >> grade) {
            if (!is_valid_grade(grade)) {
                std::cout << "Некорректная оценка. Оценки должны быть от 2 до 5.\n";
                grades.clear();
                break;
            }
            grades.push_back(grade);
        }
        if (!grades.empty()) return grades;
    }
}

bool is_valid_name(const std::string& name) {
    return name == "vasya" || name == "petya" || name == "maksim";
}

std::string input_student_name(const std::string& prompt, const std::vector<std::string>& used_names) {
    while (true) {
        std::cout << prompt;
        std::string name;
        std::getline(std::cin, name);

        if (!is_valid_name(name)) {
            std::cout << "Некорректное имя. Допустимые имена: vasya, petya, maksim\n";
            continue;
        }

        if (std::find(used_names.begin(), used_names.end(), name) != used_names.end()) {
            std::cout << "Имя '" << name << "' уже используется. Выберите другое имя.\n";
            continue;
        }

        return name;
    }
}

void show_menu() {
    std::cout << "\nВыберите задачу (1-6):\n";
    std::cout << "1. Точка\n";
    std::cout << "2. Прямая\n";
    std::cout << "3. Студент\n";
    std::cout << "4. Создаем точки\n";
    std::cout << "5. Создаем Студента\n";
    std::cout << "6. Студент отличник\n";
    std::cout << "0. Выйти\n";
    std::cout << "Выбор: ";
}

