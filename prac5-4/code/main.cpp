#include "hwlib.hpp"
#include "Sett.hpp"
#include <iostream>

int main( void ) {
    Sett s = Sett<char , 3>();


    std::cout << s << "\n";
    s.add('a');
    std::cout << s << "\n";
    s.remove('a');
    std::cout << s << "\n";
    s.add('c');
    std::cout << s << "\n";
    s.add('d');
    std::cout << s << "\n";
    s.remove('c');
    std::cout << s << "\n";
    s.add('a');
    s.add('g');
    s.add('h');
   // s.add(345);
    s.add('y');
    s.add('k');
   // s.add(85268);
   // s.add(3325);
   // s.add(323);
  //  s.add(2622);
  //  s.add(85268);
    std::cout << s;

    std::cout << s.max()<< "\n";
};