#pragma once
#ifndef BASE_H
#define BASE_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

class Base {
protected:
   int type;
public:
    Base();
    Base(int type);
    Base(const Base& other);
    virtual ~Base();

    virtual void print() const = 0;
    virtual void draw() const = 0;
    virtual void edit() = 0;
    virtual double plob () const = 0;
    virtual void saveToFile(ostream& file) const = 0;
    virtual void loadFromFile(ifstream& file) = 0;

    void setType(int type);
    int getType() const;

};

#endif