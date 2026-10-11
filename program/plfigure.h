#ifndef PLFIGURE_H
#define PLFIGURE_H

#include "Base.h"

class plfigure : public Base {
    double a;
    double b;

public:
    plfigure();
    plfigure(int type, double a, double b);
    plfigure(const plfigure& other);
    ~plfigure() ;

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