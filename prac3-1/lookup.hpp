#ifndef _LOOKUP_HPP
#define _LOOKUP_HPP
#include <math.h>


template<int N, int offset, typename T>
class lookup{
public:

    constexpr lookup(){
        for(int i =0; i < N; i++){
            values[i] = hwlib::xy(  sin(radians_from_degrees(i*(int)(360/N)))*offset,
                                    cos(radians_from_degrees(i*(int)(360/N)))*offset
            );
        }
    }
    constexpr T get( int n ) const{
        return values[ n ];
    }

    constexpr double radians_from_degrees( int degrees ){
       return 2 * 3.14 * ( degrees / 360.0 );
    }

    constexpr double pow( double g, int n ){
       double result = 1;
       while( n > 0 ){
           result *= g;
           --n;
       }
       return result;
    }

    constexpr double fac( int n ){
       double result = 1;
       while( n > 0 ){
           result *= n;
           --n;
       }
       return result;
    }

    constexpr double sin( double a ){
       return
          a
          - pow( a, 3 ) / fac( 3 )
          + pow( a, 5 ) / fac( 5 )
          - pow( a, 7 ) / fac( 7 )
          + pow( a, 9 ) / fac( 9 )
          - pow( a, 11 ) / fac( 11 )
          + pow( a, 13 ) / fac( 13 )
          - pow( a, 15 ) / fac( 15 )
          + pow( a, 17 ) / fac( 17 );
    }

    constexpr double cos( double a ){
       return
          1
          - pow( a, 2 ) / fac( 2 )
          + pow( a, 4 ) / fac( 4 )
          - pow( a, 6 ) / fac( 6 )
          + pow( a, 8 ) / fac( 8 )
          - pow( a, 10 ) / fac( 10 )
          + pow( a, 12 ) / fac( 12 )
          - pow( a, 14 ) / fac( 14 )
          + pow( a, 16 ) / fac( 16 );
}



private:
    std::array<T, N> values = {};
};
#endif