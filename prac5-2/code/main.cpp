#include "hwlib.hpp"
#include "Sett.hpp"
#include <iostream>

int main( void ) {
    Sett s = Sett<int , 10>();


    std::cout << s << "\n";
    s.add(4);
    std::cout << s << "\n";
    s.remove(4);
    std::cout << s << "\n";
    s.add(2);
    std::cout << s << "\n";
    s.add(5);
    std::cout << s << "\n";
    s.remove(2);
    std::cout << s << "\n";
    s.add(1);
    s.add(7);
    s.add(4);
    s.add(345);
    s.add(33);
    s.add(26);
    s.add(85268);
    s.add(3325);
    s.add(323);
    s.add(2622);
    s.add(85268);

    std::cout << s;
};