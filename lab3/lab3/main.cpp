#include "checkcin/checkcin.h"
#include "header/includes.h"
#include "header/task1.h"
#include "header/task2.hpp"
#include "header/task3.hpp"
#include "header/task4.hpp"
#include "header/task5.hpp"


void exec_progs_destrib(int _choosed_prog) {
    switch (_choosed_prog) {
    case TASKS_CHOOSER::TASK_1:
        task1::sample1(3);
        break;
    case TASKS_CHOOSER::TASK_2:
        task2::sample1(2);
        break;
    case TASKS_CHOOSER::TASK_3:
        task3::sample1();
        break;
    case TASKS_CHOOSER::TASK_4:
        task4::sample1();
        break;
    case TASKS_CHOOSER::TASK_5:
        task4::sample2();
        break;
    case TASKS_CHOOSER::TASK_6:
        task5::sample1();
        break;
    }
}

int main() {
    int user_choose = 0;

    do {
        user_choose = checkcin<int>("[1] Точка координат\n"
                                    "[2] Прямая\n"
                                    "[3] Студент\n"
                                    "[4] Создаём точку\n"
                                    "[5] Создаём линию\n"
                                    "[6] Длина линии\n"
                                    "[0] Завершение программы\n"
                                    "(ВВОД): ",
                                    "Ошибка ввода. Повторите попытку...");
        if (user_choose > TASKS_CHOOSER::TASK_6 or
                user_choose < TASKS_CHOOSER::STOP) {
            std::cout << "Неверный выбор задачи. Повторите попытку\n";
        } else {
            exec_progs_destrib(user_choose);
        }

    } while (user_choose != TASKS_CHOOSER::STOP);

    return 0;
}
