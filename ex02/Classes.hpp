#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <exception>

#define GREEN	"\33[1;32m"
#define CYAN	"\33[1;36m"
# define PINK	"\33[1;35m"
#define RESET	"\33[0;m"

class Base
{
    public:
        virtual ~Base(void);
};

class A : public Base { };
class B : public Base { };
class C : public Base { };

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif