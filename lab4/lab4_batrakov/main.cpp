#include "header/includes.h"
#include "header/checkcin.h"
#include "header/tests.h"

void exec_tasks_destrib(int _user_choose) {
    switch (_user_choose) {
        case TASKS::TASK1:
            test::test1();
            break;
        case TASKS::TASK2:
            test::test2();
            break;
        case TASKS::TASK3:
            test::test3();
            break;
        case TASKS::TASK4:
            test::test4();
            break;
    }
}

int main() {
    int user_choose = 0;

    do {
        user_choose = checkcin<int>("[1] Добавление прозвольного кол-ва минут\n"
                                    "[2] Вычитание прозвольного кол-ва минут\n"
                                    "[3] Прибавление минуты минуты\n"
                                    "[4] Вычитание минуты\n"
                                    "[0] Завершение программы\n"
                                    "(ВВОД): ");

        if (user_choose > TASKS::STOP ||
                user_choose < TASKS::STOP) {
            std::cout << "Неверный выбор задачи. Повторите попытку\n";
        } else {
            exec_tasks_destrib(user_choose);
        }

    } while (user_choose != TASKS::STOP);

    return 0;
}
