
//
#include <iostream>

int main()
{
    std::cout << "Enter an integer: \n";

    int x{};
    std::cin >> x;

    if ( x >= 20 )
    {
        std::cout << "result: " << x << " is greater than 20 \n";  
    }
    else if ( x >=  0 )
    {
        std::cout << "result: " << x << " is between 0 and 20 \n";
    }    
    else 
    { 
        std::cout << "result: " << x << " is less than zero \n";
        std::cout << "a negative number \n";
    }

    return 0;
}