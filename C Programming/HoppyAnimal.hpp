#pragma once
#include <iostream>
#include <string>
#include "Days.hpp"
using namespace std;

class HoppyAnimal
{
protected:
    int exhilaration_level;
    string name;
    HoppyAnimal(const string& n_name, int level): name(n_name), exhilaration_level(level){}
public:
    string getName(){return name;}
    bool isAlive(){return exhilaration_level >= 0;}
    int getLevel(){return exhilaration_level;}
    void takenCareOf(int e){exhilaration_level+=e;}
    virtual void levelDecrease(Day* &day)  = 0;
    virtual ~HoppyAnimal(){}
};

class Dog : public HoppyAnimal
{
public:
    Dog(const string& d_name, int level): HoppyAnimal(d_name, level){}
    void levelDecrease(Day* &day) override {
        day = day->levelDecrease(this);
    }

};

class Fish : public HoppyAnimal
{
public:
    Fish(const string& d_name, int level): HoppyAnimal(d_name, level){}
    void levelDecrease(Day* &day) override {
        day = day->levelDecrease(this);
    }

};

class Bird : public HoppyAnimal
{
public:
    Bird(const string& d_name, int level): HoppyAnimal(d_name, level){}
    void levelDecrease(Day* &day) override {
        day = day->levelDecrease(this);
    }
};

