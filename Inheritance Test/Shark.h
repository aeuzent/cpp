#ifndef SHARK_H
#define SHARK_H

#include "Fish.h"
#include <string>

class Shark : public Fish
{
    public:
        Shark(std::string &name, std::string &waterType, std::string &type): Fish(name, waterType)
        {
            this->type = type;
        };
        std::string type;
};

#endif // SHARK_H
