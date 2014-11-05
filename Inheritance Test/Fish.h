#ifndef FISH_H
#define FISH_H

#include "Animal.h"
#include <string>

class Fish: public Animal
{
    public:
        Fish(std::string &name, std::string &waterType): Animal(name)
        {
            this->waterType = waterType;
        };
        std::string waterType;
};

#endif // FISH_H
