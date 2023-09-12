#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

#define YELLOW	"\33[1;33m"
#define CYAN	"\33[1;36m"
#define RESET	"\33[0;m"

struct Data
{
    std::string str;
    int         num;
};

class Serializer
{
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);   

    private:
        Serializer(void);
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer(void);
};

#endif