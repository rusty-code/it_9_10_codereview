#include "geometry_student.h"

int main() {
    while (true) {
        show_menu();
        int choice = input_integer();

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            std::vector<Point> points;

            while (points.size() < 3) {
                Point new_point = input_point(
                    "Введите координаты точки " + std::to_string(points.size() + 1) +
                    " (x,y) через пробел: "
                );

                bool unique = true;
                for (const auto& point : points) {
                    if (point.get_x() == new_point.get_x() &&
                        point.get_y() == new_point.get_y()) {
                        unique = false;
                        break;
                    }
                }

                if (!unique) {
                    std::cout << "Точки должны быть с разными координатами. Повторите попытку.\n";
                    continue;
                }

                points.emplace_back(new_point);
            }

            std::cout << "Введенные точки:\n";
            for (const auto& point : points) {
                std::cout << point.print() << "\n";
            }
            break;
        }

        case 2: {
            std::cout << "Создание линий на двумерной плоскости\n";

            auto create_line = [](const std::string& line_number) {
                while (true) {
                    std::cout << "Введите координаты для линии " << line_number << "(через пробел):\n";
                    Point start = input_point("Начальная точка (x,y): ");
                    Point end = input_point("Конечная точка (x,y): ");

                    if (start.get_x() == end.get_x() && start.get_y() == end.get_y()) {
                        std::cout << "Начальная и конечная точки не могут совпадать. Попробуйте снова.\n";
                    }
                    else {
                        return Line(start, end);
                    }
                }
                };
            
            //  Отсутвие ввода
            Line line1 = create_line("1");
            Line line2 = create_line("2");
            Line line3 = create_line("3");

            std::cout << "\nСозданные линии:\n";
            std::cout << line1.print() << "\n";
            std::cout << line2.print() << "\n";
            std::cout << line3.print() << "\n";

            std::cout << "\nИзменение координат линий\n";
            std::cout << "Новые координаты для линии 1:\n";
            while (true) {
                Point new_start1 = input_point("Новая начальная точка (x,y): ");
                Point new_end1 = input_point("Новая конечная точка (x,y): ");

                if (new_start1.get_x() == new_end1.get_x() &&
                    new_start1.get_y() == new_end1.get_y()) {
                    std::cout << "Начальная и конечная точки не могут совпадать. Попробуйте снова.\n";
                }
                else {
                    line1.set_start(new_start1);
                    line1.set_end(new_end1);
                    break;
                }
            }

            std::cout << "Новые координаты для линии 2:\n";
            while (true) {
                Point new_start2 = input_point("Новая начальная точка (x,y): ");
                Point new_end2 = input_point("Новая конечная точка (x,y): ");

                if (new_start2.get_x() == new_end2.get_x() &&
                    new_start2.get_y() == new_end2.get_y()) {
                    std::cout << "Начальная и конечная точки не могут совпадать. Попробуйте снова.\n";
                }
                else {
                    line2.set_start(new_start2);
                    line2.set_end(new_end2);
                    break;
                }
            }

            line3.set_start(line1.get_start());
            line3.set_end(line2.get_end());

            std::cout << "\nПосле изменения координат линий:\n";
            std::cout << line1.print() << "\n";
            std::cout << line2.print() << "\n";
            std::cout << line3.print() << "\n";

            std::cout << "\nДополнительное изменение первой линии\n";
            while (true) {
                Point final_start1 = input_point("Финальная начальная точка (x,y): ");
                Point final_end1 = line1.get_end();

                if (final_start1.get_x() == final_end1.get_x() &&
                    final_start1.get_y() == final_end1.get_y()) {
                    std::cout << "Начальная и конечная точки не могут совпадать. Попробуйте снова.\n";
                }
                else {
                    line1.set_start(final_start1);
                    break;
                }
            }

            std::cout << "\nПосле изменения координат первой линии:\n";
            std::cout << line1.print() << "\n";
            std::cout << line2.print() << "\n";
            std::cout << line3.print() << "\n";
            break;
        }

        case 3: {
            std::cout << "Работа со студентами\n";
            std::vector<std::string> used_names;

            std::string name1 = input_student_name(
                "Введите имя первого студента (vasya, petya, maksim): ", used_names);
            used_names.push_back(name1);

            std::vector<int> grades1 = input_grades(
                "Введите оценки для " + name1 + " (через пробел, от 2 до 5): "
            );
            Student student1(name1, grades1);

            std::string name2 = input_student_name(
                "Введите имя второго студента (vasya, petya, maksim): ", used_names);
            used_names.push_back(name2);
            Student student2(name2, student1.get_grades());

            std::cout << "\nИсходные данные студентов:\n";
            std::cout << student1.print() << "\n";
            std::cout << student2.print() << "\n";

            std::cout << "\nИзменение оценок второго студента\n";
            std::vector<int> new_grades2 = input_grades(
                "Введите новые оценки для " + name2 + " (через пробел, от 2 до 5): "
            );
            student2.set_grades(new_grades2);

            std::string name3 = input_student_name(
                "Введите имя третьего студента (vasya, petya, maksim): ", used_names);
            used_names.push_back(name3);
            Student student3(name3, student1.get_grades());

            std::cout << "\nТекущие данные студентов:\n";
            std::cout << student1.print() << "\n";
            std::cout << student2.print() << "\n";
            std::cout << "Создан студент " << student3.print() << "\n";

            std::cout << "\nИзменение оценок первого студента\n";
            std::vector<int> new_grades1 = input_grades(
                "Введите новые оценки для " + name1 + " (через пробел, от 2 до 5): "
            );
            student1.set_grades(new_grades1);

            std::cout << "\nФинальные данные студентов:\n";
            std::cout << student1.print() << "\n";
            std::cout << student2.print() << "\n";
            std::cout << student3.print() << "\n";
            break;
        }

        case 4: {
            std::cout << "Введите координаты 3 точек\n";
            std::vector<Point> unique_points;

            while (unique_points.size() < 3) {
                Point new_point = input_point(
                    "Введите координаты точки " + std::to_string(unique_points.size() + 1) +
                    " (x,y): "
                );

                bool unique = true;
                for (const auto& point : unique_points) {
                    if (point.get_x() == new_point.get_x() &&
                        point.get_y() == new_point.get_y()) {
                        unique = false;
                        break;
                    }
                }

                if (!unique) {
                    std::cout << "Точки должны быть с разными координатами. Повторите попытку.\n";
                    continue;
                }

                unique_points.emplace_back(new_point);
            }

            std::cout << "Введенные точки:\n";
            for (const auto& point : unique_points) {
                std::cout << point.print() << "\n";
            }
            break;
        }

        case 5: {
            std::vector<std::string> used_names;

            std::string name1 = input_student_name(
                "Введите имя первого студента (vasya, petya, maksim): ", used_names);
            used_names.push_back(name1);

            std::vector<int> grades1 = input_grades(
                "Введите оценки для " + name1 + " (через пробел, от 2 до 5): "
            );
            Student student1(name1, grades1);
            std::cout << student1.print() << "\n";

            std::string name2 = input_student_name(
                "Введите имя второго студента (vasya, petya, maksim): ", used_names);
            used_names.push_back(name2);
            Student student2(name2);
            std::cout << student2.print() << "\n";
            break;
        }

        case 6: {
            std::vector<std::string> used_names;

            std::string name1 = input_student_name(
                "Введите имя первого студента (vasya, petya, maksim): ", used_names);
            used_names.push_back(name1);

            std::vector<int> grades1 = input_grades(
                "Введите оценки для " + name1 + " (через пробел, от 2 до 5): "
            );
            Student student1(name1, grades1);

            std::string name2 = input_student_name(
                "Введите имя второго студента (vasya, petya, maksim): ", used_names);
            used_names.push_back(name2);
            std::vector<int> grades2 = input_grades(
                "Введите оценки для " + name2 + " (через пробел, от 2 до 5): "
            );
            Student student2(name2, grades2);

            std::cout << "\nИнформация о студентах:\n";
            std::cout << student1.print() << " Средний балл: " << std::fixed
                << std::setprecision(2) << student1.average()
                << ", Отличник: " << (student1.is_excellence() ? "Да" : "Нет") << "\n";
            std::cout << student2.print() << " Средний балл: " << std::fixed
                << std::setprecision(2) << student2.average()
                << ", Отличник: " << (student2.is_excellence() ? "Да" : "Нет") << "\n";
            break;
        }

        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }
    return 0;
}