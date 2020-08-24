#include "hwlib.hpp"
#include "note_player_pc_print.hpp"


void note_player_pc_print::play( const note & n ){
   if( n.frequency == 0 ){
      hwlib::wait_us( n.duration );

   } else {
      auto half_period = 1'000'000 / ( 2 * n.frequency );
      auto end = hwlib::now_us() + n.duration;
      do {
         note_player_pc_print::print_to_serial(n);
         hwlib::wait_us( half_period );

         hwlib::wait_us( half_period );
      } while ( end > hwlib::now_us() );
   }
}

void note_player_pc_print::print_to_serial(const note & n ){
    hwlib::cout << n.frequency << " " << n.duration << "\n";
}
