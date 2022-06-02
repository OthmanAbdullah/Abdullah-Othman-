#pragma once
#include <iostream>
#include <string>

using namespace std;

class Dog;
class Bird;
class Fish;

class Day
{
public:
    virtual string getName() = 0;
    virtual Day* levelDecrease(Dog  *p) = 0;
    virtual Day* levelDecrease(Bird *p) = 0;
    virtual Day* levelDecrease(Fish *p) = 0;
    virtual ~Day() {}
};

class Bad : public Day
{
private:
    static Bad* D_instance;
public:
    string getName() override {return "Bad";}
    static Bad* instance();
    Day* levelDecrease(Dog  *p) override;
    Day* levelDecrease(Bird *p) override;
    Day* levelDecrease(Fish *p) override;
    static void destroy();
protected:
    Bad(){}
};

class Ordinary : public Day
{
private:
    static Ordinary* D_instance;
public:
    string getName() override {return "Ordinary";}

    static Ordinary* instance();
    Day* levelDecrease(Dog  *p) override;
    Day* levelDecrease(Bird *p) override;
    Day* levelDecrease(Fish *p) override;
    static void destroy();
protected:
    Ordinary(){}
};
class Good : public Day
{
private:
    static Good* D_instance;
public:
    string getName() override {return "Good";}
    static Good* instance();
    Day* levelDecrease(Dog  *p) override;
    Day* levelDecrease(Bird *p) override;
    Day* levelDecrease(Fish *p) override;
    static void destroy();
protected:
    Good(){}
};


