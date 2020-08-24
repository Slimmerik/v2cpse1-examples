#include "ostream"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "Sett.hpp"


TEST_CASE( "Test Set type:long with INT: 10", "[single-file]" ) {
    Sett s = Sett<char, 3>();

    s.add('a');
    s.add('y');
    s.remove('a');
    s.add('g');
    std::cout << s;
    REQUIRE( s.contains('a') == false );
    REQUIRE( s.contains('g') == true );
    REQUIRE( s.max() == 'y' );
}

TEST_CASE( "Test Set type:int with INT: 5", "[single-file]" ) {
    Sett s = Sett<int, 15>();

    s.add(4);
    REQUIRE( s.contains(4) == true );
    s.remove(4);
    REQUIRE( s.contains(4) == false );
    s.add(1);
    s.add(7);
    s.add(4);
    s.add(345);
    s.add(33);
    s.add(26);
    s.add(85268);
    s.add(3325);
    s.add(323);  // << true
    s.add(2622);
    s.add(852658); // << false
    std::cout << s;
    REQUIRE( s.contains(3) == false );
    REQUIRE( s.contains(323) == true );
    REQUIRE( s.contains(852658) == true );
    REQUIRE( s.max() == 852658 );
}

