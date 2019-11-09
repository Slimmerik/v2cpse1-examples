#include "hwlib.hpp"
extern "C" {
void uart_put_char( char c ){
   hwlib::cout << c;
}

void wait_123(){
    hwlib::wait_ms( 2000 );
}

void print_asciz( const char * s );//{
//   while( *s != '\0'){
//      uart_put_char( *s );
//      ++s;
//   }
//}

char conv_char(char c){
    if((c>='A')&&(c<='Z')){
        c=c-'A'+'a';
    }else{
        if((c>='a')&&(c<='z')){
            c=c-'a'+'A';
        }
    }
    return c;
}

void application();//{
//    print_asciz( "Hello world, the ANSWER is 42! @[]`{}~\n" );
//}

};

int main( void ){	
   
    namespace target = hwlib::target;
    
    // wait for the PC console to start
    hwlib::wait_ms( 2000 );

    uart_put_char(conv_char('S'));
    uart_put_char('\n');

    application();

    uart_put_char('\n');
    uart_put_char('D');
}