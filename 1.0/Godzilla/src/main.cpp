/*

    Project Crack Me
        - Module: Godzilla
        - Level: 1.0

*/

#include <iostream>
#include <limits> 


int main(int, char**){
    std::cout << "Hello, Godzilla Software!\n";

    int pwd;

    for(;;)
    {
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #else
            system("clear");
        #endif

        std::cout << "-\n";
        std::cout << "- GODZILLA LOGIN\n";
        std::cout << "-\n\n";

        std::cout << "Input password: \n";
        std::cin >> pwd;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Access denied!\n";
            continue;
        }

        if(pwd == 0x1337) 
        {
            std::cout << "Access granted!\n";
            break;
        }
    }
    
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #else
        std::cout << "Press ENTER to continue . . .";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    #endif

    return 0;
}
