#include "Keeper.h"
#include "plfigure.h"
#include "obfigure.h"
#include <limits>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

Keeper::Keeper() : arr(nullptr), size(0) {
    cout << "Keeper: конструктор по умолчанию\n";
}

Keeper::~Keeper() {
    for (int i = 0; i < size; i++)
        delete arr[i];

    delete[] arr;

    cout << "Keeper: деструктор\n";
}



void Keeper::add(Base* obj) {
    if (obj == nullptr)
        throw invalid_argument("Нельзя добавить пустую фигуру!");

    Base** temp = new Base * [size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    temp[size] = obj;

    delete[] arr;
    arr = temp;
    size++;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Неверный индекс фигуры!");

    delete arr[index];

    Base** temp = nullptr;

    if (size > 1)
        temp = new Base * [size - 1];

    for (int i = 0, j = 0; i < size; i++) {
        if (i != index)
            temp[j++] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size--;
}

void Keeper::printAll() const {
    if (size == 0) {
        cout << "Список фигур пуст.\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "\nФигура №" << i + 1 << '\n';
        arr[i]->print();
    }
}

void Keeper::drawAll() const {
    if (size == 0) {
        cout << "Список фигур пуст.\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "\nФигура №" << i + 1 << '\n';
        arr[i]->draw();
    }
}

void Keeper::edit(int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Неверный индекс фигуры!");

    arr[index]->edit();
}

int Keeper::getSize() const {
    return size;
}

void Keeper::saveAll(const char* filename) const {
    ofstream file(filename);

    if (!file)
        throw runtime_error("Ошибка открытия файла для записи!");

    file << size << '\n';

    for (int i = 0; i < size; i++)
        arr[i]->saveToFile(file);

    if (!file)
        throw runtime_error("Ошибка сохранения фигур в файл!");

    cout << "Фигуры сохранены в файл.\n";
}

void Keeper::loadAll(const char* filename) {
    ifstream file(filename);

    if (!file)
        throw runtime_error("Ошибка открытия файла!");

    int newSize;

    if (!(file >> newSize) || newSize < 0)
        throw runtime_error("Ошибка чтения количества фигур!");

    Keeper temp;

    for (int i = 0; i < newSize; i++) {
        string category, name;

        if (!(file >> category >> name))
            throw runtime_error("Ошибка чтения типа фигуры!");

        Base* obj = nullptr;

        if (category == "Плоские") {
            int type;

            if (name == "Квадрат")
                type = 1;
            else if (name == "Треугольник")
                type = 2;
            else if (name == "Трапеция")
                type = 3;
            else if (name == "Параллелограмм")
                type = 4;
            else if (name == "Прямоугольник")
                type = 5;
            else if (name == "Круг")
                type = 6;
            else
                throw runtime_error("Неизвестный тип фигуры!");

            obj = new plfigure(type, 1, 1);
        }
        else if (category == "Объемные") {
            int type;

            if (name == "Куб")
                type = 1;
            else if (name == "Параллелепипед") {
                type = 2;
            }
            else if (name == "Пирамида")
                type = 3;
            else if (name == "Цилиндр") {

                type = 4;
            }
            else if (name == "Конус")
                type = 5;
            else if (name == "Сфера")
            {
                type = 6;

            }
            else
                throw runtime_error("Неизвестный тип фигуры!");

            obj = new obfigure(type, 1, 1);
        }
        else {

            throw runtime_error("Неизвестная категория фигуры!");
        }

        try {

            obj->loadFromFile(file);
            temp.add(obj);
        }
        catch (...) {

            delete obj;
            throw;
        }
    }

    for (int i = 0; i < size; i++)
        delete arr[i];

    delete[] arr;

    arr = temp.arr;
    size = temp.size;

    temp.arr = nullptr;
    temp.size = 0;

    cout << "Фигуры загружены из файла.\n";
}