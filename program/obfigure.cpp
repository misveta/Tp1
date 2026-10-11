#include "obfigure.h"
#include <stdexcept>
#include <limits>

obfigure::obfigure() : Base(1), a(1), b(1) {
    std::cout << "obfigure: конструктор по умолчанию\n";
}

obfigure::obfigure(int t, double x, double y)
    : Base(t), a(x), b(y) {
    setA(x);
    setB(y);
    std::cout << "obfigure: конструктор с параметрами\n";
}

obfigure::obfigure(const obfigure& other)
    : Base(other), a(other.a), b(other.b) {
    std::cout << "obfigure: конструктор копирования\n";
}

obfigure::~obfigure() {
    std::cout << "obfigure: деструктор\n";
}

double obfigure::getA() const { return a; }
double obfigure::getB() const { return b; }


void obfigure::setA(double x) {
    if (x <= 0)
        throw std::invalid_argument("Размер должен быть больше нуля");
    a = x;
}

void obfigure::setB(double x) {
    if (x <= 0)
        throw std::invalid_argument("Размер должен быть больше нуля");
    b = x;
}

double obfigure::plob() const {
    if (type == 1)
        return a*a*a;
    if (type ==2 )
        return a * b;
}



void obfigure::print() const {
    if (type == 1) {
        std::cout << "\nКуб\n";
        std::cout << "Сторона A: " << a << '\n';
    }
    else if (type == 2) {
        std::cout << "\nПараллелепипед\n";
        std::cout << "Площадь основания: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else {
        std::cout << "Неизвестный тип фигуры!\n";
        return;
    }

    std::cout << "Объем: " << plob() << '\n';
}

void obfigure::draw() const {
    int size = static_cast<int>(std::round(a));

    if (size < 1) {
        size = 1;
    }

    if (size > 30) {
        size = 30;
    }

    if (type == 1) {
        std::cout << "Рисунок куба:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << "* ";
            }
            std::cout << '\n';
        }
    }
    else {
        std::cout << "Рисунок параллелепипеда:\n";

        for (int i = 0; i < b; i++) {
            for (int j = 0; j < size; ++j) {
                std::cout << "*" << " ";
            }
      
            std::cout << '\n';
        }
    }
}

void obfigure::edit() {
    double x, y;

    std::cout << "Введите новый размер A: ";
    if (!(std::cin >> x))
        throw std::runtime_error("Нужно ввести число");
    setA(x);

    if (type == 2) {
        std::cout << "Введите новую высоту B: ";
        if (!(std::cin >> y))
            throw std::runtime_error("Нужно ввести число");
        setB(y);
    }
}


void obfigure::saveToFile(std::ostream& file) const {
    string name;

    if (type == 1)
        name = "Куб";
    else if (type == 2)
        name = "Параллелепипеда";
    else
        throw std::runtime_error("Неизвестный тип объемной фигуры!");

    file << "Объемные " << name << ' '
        << a << ' ' << b << ' ' << plob() << '\n';

    if (!file)
        throw std::runtime_error("Ошибка записи объемной фигуры!");
}

void obfigure::loadFromFile(std::ifstream& file) {
    string category, name;
    double x, y, savedArea;

    if (!(file >> category >> name >> x >> y >> savedArea))
        throw std::runtime_error("Ошибка чтения объемной фигуры!");

    if (category != "Объемные")
        throw std::runtime_error("Неверная категория фигуры!");

    if (name == "Куб")
        type = 1;
    else if (name == "Параллелепипеда")
        type = 2;
    else
        throw std::runtime_error("Неизвестная объемной фигура!");

    setA(x);
    setB(y);

   
}
