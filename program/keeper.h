#pragma once
#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Keeper {
private:
    Base** arr;
    int size;
public:
    Keeper();
    ~Keeper();

    void add(Base* object);
    void remove(int index);
    void printAll() const;
    void drawAll() const;
    void edit(int index);

    int getSize() const;

    void saveAll(const char* filename) const;
    void loadAll(const char* filename);
};

#endif