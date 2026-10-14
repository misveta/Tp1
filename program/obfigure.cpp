#include "obfigure.h"
#include <stdexcept>
#include <limits>

obfigure::obfigure() : Base(1), a(1), b(0) {
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
        return a * a * a;
    else if (type == 2)
        return a * b;
    else if (type == 3)
        return a * b * (1.0 / 3);
    else if (type == 4)
        return 3.14 * a * a * b;
    else if (type == 5)
        return a * b * (1.0 / 3) * 3.14 * a;
    else if (type == 6)
        return a * a * a * 3.14 * (4.0 / 3);
}



void obfigure::print() const {
    if (type == 1) {
        std::cout << "Куб\n";
        std::cout << "Сторона A: " << a << '\n';
    }
    else if (type == 2) {
        std::cout << "Параллелепипед\n";
        std::cout << "Площадь основания: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else if (type == 3) {
        std::cout << "Пирамида\n";
        std::cout << "Площадь основания: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else if (type == 4) {
        std::cout << "Цилиндр\n";
        std::cout << "Радиус основания: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else if (type == 5) {
        std::cout << "Конус\n";
        std::cout << "Радиус основания: " << a << '\n';
        std::cout << "Высота B: " << b << '\n';
    }
    else if (type == 6) {
        std::cout << "Сфера\n";
        std::cout << "Радиус: " << a << '\n';
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
        std::cout << "Рисунок куба в плоском виде:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << "* ";
            }
            std::cout << '\n';
        }
    }
    else if (type == 2) {
        std::cout << "Рисунок параллелепипеда в плоском виде:\n";

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; ++j) {
                std::cout << "*" << " ";
            }

            std::cout << '\n';
        }
    }
    else if (type == 3) {
        std::cout << "Рисунок пирамиды в плоском виде:\n";
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
    else if (type == 4) {
        std::cout << "Рисунок цилиндр:\n";
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                std::cout << "* ";
            }
            std::cout << '\n';
        }
    }
    else if (type == 5) {
        std::cout << "Рисунок конуса в плоском виде:\n";
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
    else if (type == 6) {
        std::cout << "Рисунок сферы в плоском виде:\n";
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

void obfigure::edit() {
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


void obfigure::saveToFile(std::ostream& file) const {
    string name;

    if (type == 1)
        name = "Куб";
    else if (type == 2)
        name = "Параллелепипед";
    else if (type == 3)
        name = "Пирамида";
    else if (type == 4)
        name = "Цилиндр";
    else if (type == 5)
        name = "Конус";
    else if (type == 6)
        name = "Сфера";
    else
        throw std::runtime_error("Неизвестный тип объемной фигуры!");

    file << "Объемные" << ' ' << name << ' '
        << a << ' ' << b << ' ' << plob() << '\n';

    if (!file)
        throw std::runtime_error("Ошибка записи объемной фигуры!");
}

void obfigure::loadFromFile(std::ifstream& file) {
    double x, y, savedArea;

    if (!(file >> x >> y >> savedArea))
        throw std::runtime_error("Ошибка чтения объемной фигуры!");

    setA(x);
    setB(y);

}
