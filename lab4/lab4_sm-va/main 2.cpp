#include "Point.h"

int main() {
   int choice;

	while (true) {
		std::cout << "\nВыбор задания:" << std::endl;
		std::cout << "1 - Расчет расстояния между двумя точками" << std::endl;
		std::cout << "2 - Операции с точкой" << std::endl;
		std::cout << "0 - Выход" << std::endl;
		std::cout << "Выберите задание: ";

		std::string input;
		std::getline(std::cin, input);

		if (input == "0" || input == "1" || input == "2") {
			choice = std::stoi(input);

			switch (choice) {
			case 1:
				task_1();
				break;
			case 2:
				task_2();
				break;
			case 0:
				std::cout << "Выход из программы." << std::endl;
				return 0;
			}
		}
		else {
			std::cout << "Неверный выбор. Пожалуйста, введите 0, 1 или 2." << std::endl;
		}
	}

	return 0;
}
