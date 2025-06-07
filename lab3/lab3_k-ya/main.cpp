#include <Windows.h>
#include <exception>
#include <iostream>

#include "menu.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        int main_choice;
        do {
            display_main_menu();
            std::cin >> main_choice;

            switch (main_choice) {
            case 1:
                manage_houses();
                break;
            case 2:
                work_with_fractions();
                break;
            case 3:
                manage_employees();
                break;
            case 4:
                work_with_names();
                break;
            case 0:
                std::cout << "Выход из программы...\n";
                break;
            default:
                std::cout << "Неверный выбор!\n";
            }
        } while (main_choice != 0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}