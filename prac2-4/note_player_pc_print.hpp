#ifndef _NOTE_PLAYER_PC_PRINT_HPP
#define _NOTE_PLAYER_PC_PRINT_HPP

#include "note_player.hpp"

// ===========================================================================
//
// simple note player for a speaker connected to serial
//
// ===========================================================================

class note_player_pc_print : public note_player {

private:
    void print_to_serial(const note & n);

public:
   void play( const note & n ) override;
};

#endif
