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
    else if (type == 2)
        return a * b / 2.0;
    else if (type == 3)
        return a * b / 2.0;
    else if (type == 4)
        return a * b;
    else if (type == 5)
        return a * b;
    else if (type == 6)
        return a * a * 3.14;
}



void plfigure::print() const {
    if (type == 1) {
        std::cout << "Квадрат\n";
        std::cout << "Размер A: " << a << '\n';
    }
    else if (type == 2) {
        std::cout << "Треугольник\n";
        std::cout << "Основание A: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else if (type == 3) {
        std::cout << "Трапеция\n";
        std::cout << "Сумма оснований A: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else if (type == 4) {
        std::cout << "Параллелограмм\n";
        std::cout << "Основание A: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else if (type == 5) {
        std::cout << "Прямоугольник\n";
        std::cout << "Основание A: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else if (type == 6) {
        std::cout << "Круг\n";
        std::cout << "Радиус r: " << a << '\n';
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
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < a; ++j) {
                std::cout << "* ";
            }
            std::cout << '\n';
        }
    }
    else if (type == 2) {
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
    else if (type == 3) {
        std::cout << "Рисунок трапеции:\n";
        int c = (4 * b - 4) / (b - 1);
        int s = 4;
        for (int i = 0; i < b; ++i) {
            int sp = (4 * b - s) / 2;
            for (int j = 0; j < sp; ++j) {
                std::cout << " ";
            }
            for (int j = 0; j <= s; j++) {
                std::cout << "*";
            }
            s += c;;
            std::cout << '\n';
        }
    }
    else if (type == 4) {
        std::cout << "Рисунок Параллелограмм:\n";
        int c = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < i; ++j) {
                std::cout << " ";
            }
            for (int i = 0; i <= a; ++i) {
                std::cout << "*";
            }

            std::cout << '\n';
        }
    }
    else if (type == 5) {
        std::cout << "Рисунок прямоугольника:\n";
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                std::cout << "* ";
            }
            std::cout << '\n';
        }
    }
    else if (type == 6) {
        std::cout << "Рисунок круга:\n";

        const int width = a;
        const int length = static_cast<int>(a * 1.5);

        for (int y = width; y >= -width; y -= 2) {
            for (int x = -length; x <= length; ++x) {
                double dist = std::sqrt(static_cast<double>(x * x + y * y));
                if (std::fabs(dist - a) < 1.0) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
            }
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

    if (type == 2 || type == 3 || type == 4 || type == 5) {
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
    else if (type == 3)
        name = "Трапеция";
    else if (type == 4)
        name = "Параллелограмм";
    else if (type == 5)
        name = "Прямоугольник";
    else if (type == 6)
        name = "Круг";
    else
        throw std::runtime_error("Неизвестный тип плоской фигуры!");

    file << "Плоские" << ' ' << name << ' '
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
