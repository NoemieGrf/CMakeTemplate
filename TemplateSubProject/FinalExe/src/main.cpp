#include "print.h"
#include "util.h"
#include <iostream>

int main()
{
    int result = Math::Add(3, 5);
    std::cout << result << std::endl;

    Print::DoPrint();

    return 0;
}