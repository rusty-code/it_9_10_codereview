#include "../header/tests.h"


void test::test1() {
    Time tm(
        checkcin<unsigned int>("Введите кол-во часов"), 
        checkcin<unsigned int>("Введите кол-во минут")
    );

    unsigned int minutes = checkcin<unsigned int>("Прибавляемое кол-во минут: ");
    std::cout << tm << " + " << minutes << " = " << (tm + minutes) << std::endl;
}


void test::test2()
{
    std::cout << "\nTest2\n";
    Time tm(0, 0);

    std::cout << "++ and --\n";
    std::cout << tm << "++: " << (++tm) << std::endl;

    tm.set_hours(0);
    tm.set_minutes(59);

    std::cout << tm << "++: " << (++tm) << std::endl;

    tm.set_hours(1);
    tm.set_minutes(0);

    std::cout << tm << "--: " << (--tm) << std::endl;

    tm.set_hours(0);
    tm.set_minutes(1);

    std::cout << tm << "--: " << (--tm) << std::endl;

}

void test::test3()
{
    std::cout << "\nTest3\n";
    Time tm(12, 10);

    std::cout << "short int and bool\n";
    std::cout << tm << "shot int: " << short(tm) << std::endl;

    tm.set_hours(0);
    tm.set_minutes(59);

    std::cout << tm << "shot int: " << short(tm) << std::endl;

    tm.set_hours(1);
    tm.set_minutes(0);

    std::cout << tm << "bool: " << bool(tm) << std::endl;

    tm.set_hours(0);
    tm.set_minutes(0);

    std::cout << tm << "bool: " << bool(tm) << std::endl;

}

void test::test4()
{
    std::cout << "\nTest4\n";
    Time tm(1, 56);
    std::cout << "+ and -\n";

    std::cout << tm << " - " << Time(0, 50) << " = " << (tm - Time(0, 50)) << std::endl;

    tm.set_hours(1);
    tm.set_minutes(0);

    std::cout << tm << " - " << Time(0, 50) << " = " << (tm - Time(0, 50)) << std::endl;

    tm.set_hours(0);
    tm.set_minutes(59);   

    std::cout << tm << " - " << Time(1, 50) << " = " << (tm - Time(1, 50)) << std::endl;

    tm.set_hours(0);
    tm.set_minutes(30);   

    std::cout << tm << " - " << Time(0, 50) << " = " << (tm - Time(0, 50)) << std::endl;
}