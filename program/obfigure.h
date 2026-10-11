#pragma once
#ifndef OBFIGURE_H
#define OBFIGURE_H

#include "Base.h"

class obfigure : public Base {
    double a;
    double b;

public:
    obfigure();
    obfigure(int type, double a, double b);
    obfigure(const obfigure& other);
    ~obfigure();

    double getA() const;
    double getB() const;

    void setA(double a);
    void setB(double b);

    double plob() const override;
    void print() const override;
    void draw() const override;
    void edit() override;

    void saveToFile(std::ostream& file) const override;
    virtual void loadFromFile(ifstream& file) override;
   };

#endif