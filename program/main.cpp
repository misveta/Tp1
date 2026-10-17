#include <iostream>
#include "obfigure.h"
#include <stdexcept>
#include "Keeper.h"
#include "plfigure.h"
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Keeper keeper;
    int choice;

    do {
        cout << "\nМЕНЮ\n";
        cout << "1. Добавить плоскую фигуру\n";
        cout << "2. Добавить объемную фигуру\n";
        cout << "3. Удалить фигуру\n";
        cout << "4. Вывести все фигуры\n";
        cout << "5. Нарисовать все фигуры\n";
        cout << "6. Редактировать фигуру\n";
        cout << "7. Сохранить фигуры в файл\n";
        cout << "8. Загрузить фигуры из файла\n";
        cout << "9. Показать количество фигур\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";

        if (!(cin >> choice)) {
            cin.clear();
            
            cout << "Ошибка: введите номер пункта меню!\n";
            continue;
        }

        try {
            switch (choice) {
            case 1: {
                int type;
                double a, b = 1;

                cout << "\nВыберите фигуру:\n";
                cout << "1. Квадрат\n";
                cout << "2. Треугольник\n";
                cout << "3. Трапеция\n";
                cout << "4. Параллелограмм\n";
                cout << "5. Прямоугольник\n";
                cout << "6. Круг\n";
            
                cout << "Ваш выбор: ";

                if (!(cin >> type) || (type != 1 && type != 2 && type != 3 && type != 4 && type != 5 && type != 6)) {
                    cin.clear();
                    
                    cout << "Ошибка: неизвестный тип фигуры!\n";
                    break;
                }

                cout << "Введите размер A: ";
                if (!(cin >> a)) {
                    cin.clear();
                   
                    cout << "Ошибка: необходимо ввести число!\n";
                    break;
                }

                if (type >= 2 && type!= 6) {
                    cout << "Введите высоту B: ";
                    if (!(cin >> b)) {
                        cin.clear();
                        
                        cout << "Ошибка: необходимо ввести число!\n";
                        break;
                    }
                }

                keeper.add(new plfigure(type, a, b));
                cout << "Фигура успешно добавлена!\n";
                break;
            }

            case 3: {
                if (keeper.getSize() == 0) {
                    cout << "Список фигур пуст!\n";
                    break;
                }

                keeper.printAll();

                int index;
                cout << "Введите номер фигуры для удаления: ";

                if (!(cin >> index)) {
                    cin.clear();
                    
                    cout << "Ошибка: введите целое число!\n";
                    break;
                }

                keeper.remove(index - 1);
                cout << "Фигура удалена!\n";
                break;
            }

            case 4:
                keeper.printAll();
                break;

            case 5:
                keeper.drawAll();
                break;

            case 6: {
                if (keeper.getSize() == 0) {
                    cout << "Список фигур пуст!\n";
                    break;
                }

                keeper.printAll();

                int index;
                cout << "Введите номер фигуры для редактирования: ";

                if (!(cin >> index)) {
                    cin.clear();
                    
                    cout << "Ошибка: введите целое число!\n";
                    break;
                }

                keeper.edit(index - 1);
                cout << "Фигура изменена!\n";
                break;
            }

            case 7: {
                char filename[256];

                cout << "Введите имя файла для сохранения: ";
                cin >> filename;

                keeper.saveAll(filename);
                break;
            }

            case 8: {
                char filename[256];

                cout << "Введите имя файла для загрузки: ";
                cin >> filename;

                keeper.loadAll(filename);
                cout << "Фигур в основном хранилище: "
                    << keeper.getSize() << '\n';

                keeper.printAll();
                break;
            }

            case 9:
                cout << "Количество фигур: "
                    << keeper.getSize() << '\n';
                break;
            case 2: {
                int type;
                double a, b = 1;

                cout << "\nВыберите фигуру:\n";
                cout << "1. Куб\n";
                cout << "2. Параллелепипед\n";
                cout << "3. Пирамида\n";
                cout << "4. Цилиндр\n";
                cout << "5. Конус\n";
                cout << "6. Сфера\n";

                cout << "Ваш выбор: ";

                if (!(cin >> type) || (type != 1 && type != 2 && type != 3 && type != 4 && type != 5 && type != 6)) {
                    cin.clear();

                    cout << "Ошибка: неизвестный тип фигуры!\n";
                    break;
                }

                cout << "Введите размер A: ";
                if (!(cin >> a)) {
                    cin.clear();

                    cout << "Ошибка: необходимо ввести число!\n";
                    break;
                }

                if (type >= 2 && type != 6) {
                    cout << "Введите высоту B: ";
                    if (!(cin >> b)) {
                        cin.clear();

                        cout << "Ошибка: необходимо ввести число!\n";
                        break;
                    }
                }

                keeper.add(new obfigure(type, a, b));
                cout << "Фигура успешно добавлена!\n";
                break;
            }
            case 0:
                cout << "Завершение программы.\n";
                break;

            default:
                cout << "Нет такого пункта меню!\n";
                break;
            }
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << '\n';
        }

    } while (choice != 0);

    return 0;
}