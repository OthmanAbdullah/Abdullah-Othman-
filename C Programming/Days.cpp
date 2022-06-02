#include "Days.hpp"
#include "HoppyAnimal.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Bad* Bad::D_instance = nullptr;
Bad* Bad::instance()
{
    if (D_instance == nullptr)
    {
        D_instance = new Bad();
    }
    return D_instance;
}
void Bad::destroy()
{
    if (D_instance != nullptr)
    {
        delete D_instance;
        D_instance = nullptr;
    }
}

Day* Bad::levelDecrease(Dog *p)
{
    p->takenCareOf(-10);
    return this;
}

Day* Bad::levelDecrease(Fish *p)
{
    p->takenCareOf(-5);
    return this;
}

Day* Bad::levelDecrease(Bird *p)
{
    p->takenCareOf(-3);
    return this;
}


// Good day implementaion

Good* Good::D_instance = nullptr;
Good* Good::instance()
{
    if (D_instance == nullptr)
    {
        D_instance = new Good();
    }
    return D_instance;
}
void Good::destroy()
{
    if (D_instance != nullptr)
    {
        delete D_instance;
        D_instance = nullptr;
    }
}

Day* Good::levelDecrease(Dog *p)
{
    p->takenCareOf(3);
    return this;
}

Day* Good::levelDecrease(Fish *p)
{
    p->takenCareOf(1);
    return this;
}

Day* Good::levelDecrease(Bird *p)
{
    p->takenCareOf(2);
    return this;
}

// Ordinary day implementaion

Ordinary* Ordinary::D_instance = nullptr;
Ordinary* Ordinary::instance()
{
    if (D_instance == nullptr)
    {
        D_instance = new Ordinary();
    }
    return D_instance;
}
void Ordinary::destroy()
{
    if (D_instance != nullptr)
    {
        delete D_instance;
        D_instance = nullptr;
    }
}

Day* Ordinary::levelDecrease(Dog *p)
{
    p->takenCareOf(0);
    return this;
}

Day* Ordinary::levelDecrease(Fish *p)
{
    p->takenCareOf(-3);
    return this;
}

Day* Ordinary::levelDecrease(Bird *p)
{
    p->takenCareOf(-4);
    return this;
}