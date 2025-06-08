#include "Point.h"

bool is_number(const std::string& s) {
	if (s.empty()) return false;
	size_t start = 0;
	if (s[0] == '-') start = 1;

	bool has_decimal = false;
	for (size_t i = start; i < s.size(); ++i) {
		if (s[i] == '.') {
			if (has_decimal) return false;
			has_decimal = true;
		}
		else if (!std::isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

double get_valid_coordinate(const std::string& prompt) {
	std::string input;
	double value;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);

		input.erase(0, input.find_first_not_of(" \t"));
		input.erase(input.find_last_not_of(" \t") + 1);

		if (is_number(input)) {
			std::istringstream iss(input);
			iss >> value;
			return value;
		}
		std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
	}
}

void calculate_distance(Point p1, Point p2) {
	double dist = std::sqrt(std::pow(p2.get_x_pos() - p1.get_x_pos(), 2) +
		std::pow(p2.get_y_pos() - p1.get_y_pos(), 2));
	std::cout << "\nРасстояние между точками: " << dist;
}

void task_1() {
	std::cout << "Расчет расстояния между двумя точками" << std::endl;

	double p1_x = get_valid_coordinate("Введите координату X: ");
	double p1_y = get_valid_coordinate("Введите координату Y: ");
	Point p1(p1_x, p1_y);
	std::cout << p1;

	double p2_x = get_valid_coordinate("\nВведите координату X: ");
	double p2_y = get_valid_coordinate("Введите координату Y: ");
	Point p2(p2_x, p2_y);
	std::cout << p2;

	calculate_distance(p1, p2);
}

void task_2() {
	std::cout << "\nОперации с точкой" << std::endl;

	double p3_x = get_valid_coordinate("Введите координату X: ");
	double p3_y = get_valid_coordinate("Введите координату Y: ");
	Point p3(p3_x, p3_y);
	std::cout << p3;

	std::cout << "\nУнарные операции:\n";
	int operation;
	while (true) {
		std::cout << "Выберите операцию (1 - уменьшение, 2 - смена мест): ";
		std::string input;
		std::getline(std::cin, input);

		if (input == "1" || input == "2") {
			operation = std::stoi(input);
			break;
		}
		std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
	}

	Point current_point = p3;

	if (operation == 1) {
		--current_point;
		std::cout << "После уменьшения на 1: " << current_point << std::endl;
	}
	else if (operation == 2) {
		current_point = &current_point;
		std::cout << "После смены мест координат: " << current_point << std::endl;
	}

	std::cout << "\nОперации приведения типа:\n";
	std::cout << "Неявное преобразование int(x) -> " << static_cast<int>(current_point) << std::endl;
	std::cout << "Явное преобразование double(y) -> " << static_cast<double>(current_point) << std::endl;

	std::cout << "\nБинарные операции:\n";
	unsigned int num;
	while (true) {
		std::cout << "Введите число для уменьшения координаты X: ";
		std::string input;
		std::getline(std::cin, input);

		bool valid = true;
		for (char c : input) {
			if (!std::isdigit(c)) {
				valid = false;
				break;
			}
		}

		if (valid && !input.empty()) {
			num = std::stoul(input);
			break;
		}
		std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
	}
	Point p3_add = current_point - num;
	std::cout << "Точка после уменьшения X на " << num << ": " << p3_add << std::endl;

	std::cout << "\nВведите точку для расчета расстояния:\n";
	double p4_x = get_valid_coordinate("Введите координату X: ");
	double p4_y = get_valid_coordinate("Введите координату Y: ");
	Point p4(p4_x, p4_y);

	std::cout << "Расстояние между " << p3_add << " и " << p4
		<< " = " << (p3_add + p4) << std::endl;
}
