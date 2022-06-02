#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "HoppyAnimal.hpp"

using namespace std;

class Cathy
{
private:
    string name;
public:
    Cathy(): name("Cathy"){}
    bool isHappy(vector<HoppyAnimal*> vec)
    {
        for(HoppyAnimal* a : vec)
        {
            if(a->getLevel() <5)
                return false;
        }
        return true;
    }
};
