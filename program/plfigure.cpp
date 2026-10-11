#include "plfigure.h"
#include <stdexcept>
#include <limits>

plfigure::plfigure() : Base(1), a(1), b(1) {
    std::cout << "plfigure: конструктор по умолчанию\n";
}

plfigure::plfigure(int t, double x, double y)
    : Base(t), a(x), b(y) {
    setA(x);
    setB(y);
    std::cout << "plfigure: конструктор с параметрами\n";
}

plfigure::plfigure(const plfigure& other)
    : Base(other), a(other.a), b(other.b) {
    std::cout << "plfigure: конструктор копирования\n";
}

plfigure::~plfigure() {
    std::cout << "plfigure: деструктор\n";
}

double plfigure::getA() const { return a; }
double plfigure::getB() const { return b; }


void plfigure::setA(double x) {
    if (x <= 0)
        throw std::invalid_argument("Размер должен быть больше нуля");
    a = x;
}

void plfigure::setB(double x) {
    if (x <= 0)
        throw std::invalid_argument("Размер должен быть больше нуля");
    b = x;
}

double plfigure::plob() const {
    if (type == 1)
        return a * a;

    return a * b / 2.0;
}



void plfigure::print() const {
    if (type == 1) {
        std::cout << "\nКвадрат\n";
        std::cout << "Размер A: " << a << '\n';
    }
    else if (type == 2) {
        std::cout << "\nТреугольник\n";
        std::cout << "Основание A: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else {
        std::cout << "Неизвестный тип фигуры!\n";
        return;
    }

    std::cout << "Площадь: " << plob() << '\n';
}

void plfigure::draw() const {
    int size = static_cast<int>(std::round(a));

    if (size < 1) {
        size = 1;
    }

    if (size > 30) {
        size = 30;
    }

    if (type == 1) {
        std::cout << "Рисунок квадрата:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << "* ";
            }
            std::cout << '\n';
        }
    }
    else {
        std::cout << "Рисунок треугольника:\n";
        int c = 0;
        for (int i = b; i > 0; i--) {
            for (int j = 0; j < i; ++j) {
                std::cout << " ";
            }
            for (int i = 0; i <= c * 2; i++) {
                std::cout << "*";
            }
            c++;
            std::cout << '\n';
        }
    }
}

void plfigure::edit() {
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




void plfigure::saveToFile(std::ostream& file) const {
    string name;

    if (type == 1)
        name = "Квадрат";
    else if (type == 2)
        name = "Треугольник";
    else
        throw std::runtime_error("Неизвестный тип плоской фигуры!");

    file << "Плоские " << name << ' '
        << a << ' ' << b << ' ' << plob() << '\n';

    if (!file)
        throw std::runtime_error("Ошибка записи плоской фигуры!");
}

void plfigure::loadFromFile(std::ifstream& file) {
    double x, y, savedArea;

    if (!(file >> x >> y >> savedArea))
        throw std::runtime_error("Ошибка чтения плоской фигуры!");

    setA(x);
    setB(y);

}
