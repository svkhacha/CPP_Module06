#include "Classes.hpp"

Base::~Base(void) { }

Base*   generate(void)
{
    std::cout<<GREEN<<"Random generator generated the Derived object !"<<RESET<<std::endl;
    srand(static_cast<unsigned int>(time(NULL)));
    if (rand() % 3 == 2)
    {
        return new(A);
    }
    else if (rand() % 3 == 1)
    {
        return new(B);
    }
    else
        return new(C);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout<<"(ptr) Type: "<<PINK<<"A"<<RESET<<std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout<<"(ptr) Type: "<<PINK<<"B"<<RESET<<std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout<<"(ptr) Type: "<<PINK<<"C"<<RESET<<std::endl;
}

void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout<<"(reference) Type: "<<CYAN<<"A"<<RESET<<std::endl;
        return ;
    }
    catch (std::exception& e) { }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout<<"(reference) Type: "<<CYAN<<"B"<<RESET<<std::endl;
        return ;
    }
    catch (std::exception& e) { }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout<<"(reference) Type: "<<CYAN<<"C"<<RESET<<std::endl;
        return ;
    }
    catch (std::exception& e) { }
}