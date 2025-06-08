#include <iostream>
#include <locale>
#include <clocale>

#include "LineSegment.h"

void print_menu() {
    std::cout << "\n���� �������� � ���������:\n";
    std::cout << "1. ������� �������\n";
    std::cout << "2. ����� ����������� ��������\n";
    std::cout << "3. ��������� ������� �������� (!)\n";
    std::cout << "4. �������� � int (�������)\n";
    std::cout << "5. �������� � double (�����)\n";
    std::cout << "6. ������� � ����� ������\n";
    std::cout << "7. �������� ������� (�������� >)\n";
    std::cout << "8. �����\n";
    std::cout << "�������� ��������: ";
}

int main() {
    // ��������� �����������
    setlocale(LC_ALL, "Russian");


    LineSegment* segment1 = nullptr;
    LineSegment* segment2 = nullptr;
    int choice;

    try {
        do {
            print_menu();
            choice = static_cast<int>(get_user_input(""));

            switch (choice) {
            case 1: {
                double start = get_user_input("������� ������ ������� �������: ");
                double end = get_user_input("������� ����� ������� �������: ");
                delete segment1;
                segment1 = new LineSegment(start, end);

                start = get_user_input("������� ������ ������� �������: ");
                end = get_user_input("������� ����� ������� �������: ");
                delete segment2;
                segment2 = new LineSegment(start, end);

                std::cout << "������ �������: " << *segment1 << std::endl;
                std::cout << "������ �������: " << *segment2 << std::endl;
                break;
            }

            case 2: {
                if (!segment1 || !segment2) {
                    std::cout << "������� �������� �������!" << std::endl;
                    break;
                }

                LineSegment* intersection = segment1->intersect(*segment2);
                if (intersection) {
                    std::cout << "�����������: " << *intersection << std::endl;
                    delete intersection;
                }
                else {
                    std::cout << "������� �� ������������." << std::endl;
                }
                break;
            }

            case 3: {
                if (!segment1) {
                    std::cout << "������� �������� �������!" << std::endl;
                    break;
                }

                LineSegment updated_segment = !(*segment1);
                std::cout << "����� ������� �������� (!): ";
                updated_segment.display();
                break;
            }

            case 4: {
                if (!segment1) {
                    std::cout << "������� �������� �������!" << std::endl;
                    break;
                }

                int int_value = *segment1;
                std::cout << "������� ���������� � int: " << int_value << std::endl;
                break;
            }

            case 5: {
                if (!segment1) {
                    std::cout << "������� �������� �������!" << std::endl;
                    break;
                }

                double double_value = static_cast<double>(*segment1);
                std::cout << "����� ���������� � double: " << double_value << std::endl;
                break;
            }

            case 6: {
                if (!segment1) {
                    std::cout << "������� �������� �������!" << std::endl;
                    break;
                }

                int offset = static_cast<int>(get_user_input("������� ����� ����� ��� ��������: "));
                LineSegment new_segment = *segment1 + offset;
                std::cout << "����� �������� � " << offset << ": ";
                new_segment.display();
                break;
            }

            case 7: {
                if (!segment1 || !segment2) {
                    std::cout << "������� �������� ��� �������!" << std::endl;
                    break;
                }

                if (*segment1 > *segment2) {
                    std::cout << "������ ������� �������� 2." << std::endl;
                }
                else {
                    std::cout << "������ ������� �� �������� 2." << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "����� �� ���������." << std::endl;
                break;
            }

            default: {
                std::cout << "�������� �����. ���������� �����." << std::endl;
                break;
            }
            }
        } while (choice != 8);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    delete segment1;
    delete segment2;

    return 0;
}