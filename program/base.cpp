#include "Base.h"
using namespace std;

Base::Base() : type(1) {
    cout << "Base: вызван конструктор по умолчанию\n";
}
Base::Base(const int type) : type(type) {
    if (type == 0) {
        throw invalid_argument("Тип фигуры не может быть пустым!");
    }
    cout << "Base: параметризованный конструктор (" << this->type << ")\n";
}

Base::Base(const Base& other) : type(other.type) {
   cout << "Base: вызван конструктор копирования\n";
}

Base::~Base() {
   cout << "Base: вызван деструктор\n";
}

void Base::setType(int t) { type = t; }
int Base::getType() const { return type; }