#include "LineSegment.h"
#include <iostream>
#include <limits>

/*
������� ��� ����������� ����� �����
��������� ����������� ��� �����
���������� ��������� �����
*/
double input_number(const std::string& prompt)
{
    double number;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> number)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������. ������� �����\n";
    }
    return number;
}


void show_menu()
{
    std::cout << "\n����:\n";
    std::cout << "1. ������� ������� �\n";
    std::cout << "2. ������� ������� �\n";
    std::cout << "3. ������� �������\n";
    std::cout << "4. ����� ����������� (����������� �����)\n";
    std::cout << "5. ����� ����������� (����� �������)\n";
    std::cout << "6. ��������� ������� �������� !\n";
    std::cout << "7. �������� � int\n";
    std::cout << "8. �������� � double\n";
    std::cout << "9. ������� � ����� ������\n";
    std::cout << "10. ��������� ��������� ��������\n";
    std::cout << "11. �������� ���������� �������\n";
    std::cout << "0. �����\n";
    std::cout << "�������� ����� ��������: ";
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    LineSegment segment1;
    LineSegment segment2;
    int choice;

    do
    {
        show_menu();
        choice = static_cast<int>(input_number(""));

        switch (choice)
        {
        case 1:
        {
            double start = input_number("������� ������ ������� �������: ");
            double end = input_number("������� ����� ������� �������: ");
            segment1 = LineSegment(start, end);
            break;
        }
        case 2:
        {
            double start = input_number("������� ������ ������� �������: ");
            double end = input_number("������� ����� ������� �������: ");
            segment2 = LineSegment(start, end);
            break;
        }
        case 3:
            std::cout << "������ �������: " << segment1 << "\n������ �������: " << segment2 << std::endl;
            break;
        case 4:
        {
            LineSegment* intersection = LineSegment::intersection(segment1, segment2);
            if (intersection)
            {
                std::cout << "�����������: " << *intersection << std::endl;
                delete intersection;
            }
            else
            {
                std::cout << "������� �� ������������" << std::endl;
            }
            break;
        }
        case 5:
        {
            LineSegment* intersection = segment1.intersect(segment2);
            if (intersection)
            {
                std::cout << "�����������: " << *intersection << std::endl;
                delete intersection;
            }
            else
            {
                std::cout << "������� �� ������������" << std::endl;
            }
            break;
        }
        case 6:
        {
            LineSegment result = !segment1;
            std::cout << "��������� ���������� ! � ������� �������: " << result << std::endl;
            break;
        }
        case 7:
            std::cout << "����� ����� ���������� y ������� �������: " << static_cast<int>(segment2) << std::endl;
            break;
        case 8:
            std::cout << "���������� x ������� �������: " << static_cast<double>(segment1) << std::endl;
            break;
        case 9:
        {
            int offset = static_cast<int>(input_number("������� ����� ����� ��� ��������: "));
            LineSegment result = segment1 + offset;
            std::cout << "��������� ��������: " << result << std::endl;
            break;
        }
        case 10:
            if (segment1 > segment2)
                std::cout << "������ ������� �������� ������ �������" << std::endl;
            else
                std::cout << "������ ������� �� �������� ������ �������" << std::endl;
            break;
        case 11:
        {
            double start = input_number("������� ����� ������ �������: ");
            segment1.set_start(start);
            double end = input_number("������� ����� ����� �������: ");
            segment1.set_end(end);
            std::cout << "����������� �������: " << segment1 << std::endl;
            break;
        }
        case 0:
            std::cout << "�����" << std::endl;
            break;
        default:
            std::cout << "������: ������� ����� �� 0 �� 11" << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}