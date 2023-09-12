#include "Serializer.hpp"

int main()
{
    Data    data;
    data.str = "Yerevan";
    data.num = 42;

    uintptr_t   data1 = Serializer::serialize(&data);
    Data*       data2 = Serializer::deserialize(data1);

    std::cout<<YELLOW<<&data<<RESET<<std::endl;
    std::cout<<CYAN<<data2<<RESET<<std::endl;
    std::cout<<YELLOW<<data.str<<data.num<<RESET<<std::endl;
    std::cout<<CYAN<<data2->str<<data2->num<<RESET<<std::endl;
    return 0;
}