#include "../header/task3.hpp"
#include "print.cpp"


void task3::sample1()
{

    std::cout << "Введите три оценки для студента Васи: \n";
    Student* vasya = new Student("Вася", {
        checkcin<int>("(ОЦЕНКА 1): "),
        checkcin<int>("(ОЦЕНКА 2): "),
        checkcin<int>("(ОЦЕНКА 3): ")
    }
                                );

    Student* petr = new Student("Петя");
    std::cout << "\nКопипирование оценок Васи в Петю...\n";
    petr->set_marks_ptr(vasya->get_marks_ptr());

    std::cout << "\nИзменение оценок у Пети...\n";
    petr->operator[](0) = checkcin<int>("(ВВОД): ");

    print_collection<Student*>("Студент", {vasya, petr});

    std::cout << "\nСоздание студента Андрея...\n";

    Student* andrey = new Student("Андрей");
    andrey->set_marks(vasya->get_marks_begin(), vasya->get_marks_end());

    std::cout << "\nИзменение оценок у Васи...\n";
    vasya->operator[](0) = checkcin<int>("(ВВОД): ");

    print_collection<Student*>("Студент", {vasya, petr, andrey});
}