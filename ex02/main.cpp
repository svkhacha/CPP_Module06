#include "Classes.hpp"

int main()
{
    Base*   typePtr = generate();
    Base&   typeRef = *typePtr;

    identify(typePtr);
    identify(typeRef);

    delete typePtr;
    return 0;
}