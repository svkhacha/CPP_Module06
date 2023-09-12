#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout<<RED<<"ERROR: Invalid number of arguments"<<RESET<<std::endl;
        return 0;
    }
    else
    {
        std::string arg = argv[1];
        ScalarConverter::convert(arg);
    }
    return 0;
}