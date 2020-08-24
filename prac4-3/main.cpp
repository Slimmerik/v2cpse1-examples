#include <iostream>
#include <fstream>

#include "compressor.hpp" 
#include "decompressor.hpp" 

int main( void ){	
   lz_compressor< 4096 > compressor;
 
   std::ifstream f1;
   f1.open( "lorem.txt" );
   //f1.open( "wilhelmus.asm" );
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   std::ofstream f2;
   f2.open( "loremOUT.asm" );
   //f2.open( "lorem.asm" );
   if( ! f2.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }


   compressor.compress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f2 ]( char c ){static bool check = false; if (check == false){f2 << "\t\t.cpu cortex-m0\n\t\t.text\n\t\t.align 1\n\t\t.global lorem\nlorem:    .asciz \"";check = true;};f2.put( c ); }
      //[ &f2 ]( char c ){ f2.put( c ); }
      );

   f2.put('\"');
   f1.close();
   f2.close();
   std::cout << "closed \n";


   
//   f1.open( "loremOUT.txt" );
//   if( ! f1.is_open()){
//      std::cerr << "compressed file not opened";
//      return -1;
//   }
//
//   lz_decompressor decompressor;
//   decompressor.decompress(
//      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
//      [ &f2 ]( char c ){ std::cout << c; }
//   );
}