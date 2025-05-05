#include <iostream>

#include "Liste.h"

int main()
{

    Liste<std::string> l;

	 l.push_front("test_pushfront");

            l.push_back("test_pushback");

    std::cout << l;
    std::cout << std::endl;

    std::cout << l;
    std::cout << std::endl;
}
