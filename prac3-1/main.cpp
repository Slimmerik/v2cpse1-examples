#include "hwlib.hpp"
//#include "klok.hpp"
#include "lookup.hpp"
#include <algorithm>

    //loopup object for clock angles. object contains list of hwlib::xy
    constexpr lookup angles = lookup<60, 25, hwlib::xy>();

    // system time tick triggers
    const long long unsigned int us_in_second   = 1000000;
    long long unsigned int update_at            = 2000000;

    //24hour clock
    int seconds = 50;
    int minutes = 59;
    int hours = 23;

    //oled dimentions
    constexpr auto origin     = hwlib::xy( 0, 0 );
    constexpr auto oled_size  = hwlib::xy( 128, 64 );
    constexpr auto centre     = origin + oled_size / 2;

    // draws the clock handles
    //@parm oled object
    void update_handles(hwlib::glcd_oled_i2c_128x64_buffered & oled){
            //seconds handle
            hwlib::line(centre,centre + angles.get((seconds + 30) % 60)).draw(oled);

            //minutes handle
            hwlib::line(centre,centre + angles.get((minutes + 30) % 60)).draw(oled);

            //hours handle
            hwlib::line(centre,centre + angles.get((int)(((hours + 6) % 12)*5))).draw(oled);
    }

    //draws digital clock
    //@parm oled object
    void update_digital_clock(hwlib::glcd_oled_i2c_128x64_buffered & oled, hwlib::terminal_from & display){
        display << "\f"<< hours << ":" << minutes << ":" << seconds ;
    }

    //draws zero to 12 indicators
    //@parm oled object
    void update_zero_to_twelve(hwlib::glcd_oled_i2c_128x64_buffered & oled){
        for (int i = 0 ; i < 60; i+=5){
            //hwlib::cout << "x "  << (int)(angles.get(i).x) << " y "  << (int)(angles.get(i).y) <<  "\n";
            hwlib::circle(centre + angles.get(i), 3).draw(oled);
        }
    }

    // updates all the display elements, digi clock, clock handles, zero to 12 indicators.
    //@parm oled object
    //@parm display terminal for text
    void update_display(hwlib::glcd_oled_i2c_128x64_buffered & oled, hwlib::terminal_from & display){
        oled.clear();
        update_digital_clock(oled, display);
        update_handles(oled);
        update_zero_to_twelve(oled);
        oled.flush();
    }

    // updates the time if system clock tick triggerd
    void update_real_time(){
        seconds +=1;

        if (seconds == 60){
            minutes +=1;
            seconds = 0;
        }

        if (minutes == 60 ){
            hours +=1;
            seconds = 0;
            minutes = 0;
        }

        if (hours == 24  ){
            seconds = 0;
            minutes = 0;
            hours = 0;
        }
    }

    //updates the system clock trigger
    void update_update_time(){
        update_at = update_at + us_in_second;
    }

    //The run methode that that starts the loop for the clock
    //@param oled
    void run(hwlib::glcd_oled_i2c_128x64_buffered & oled){
        //start time
        //hwlib::cout << "START " << hwlib::now_us();

        //create display text terminal
        auto font = hwlib::font_default_8x8();
        auto display = hwlib::terminal_from( oled, font);

        for(;;){
            //update clock
            if (hwlib::now_us() > update_at){
                //hwlib::cout << "TIME " << hwlib::now_us() << "\n";
                //hwlib::cout << hours << " : " << minutes << " : "<< seconds << "\n";

                //update tick
                update_real_time();
                //update 24 hour clock
                update_update_time();
                //update display
                update_display(oled, display);
            }
        }
    }



int main( void ){
    // kill the watchdog & wait for the PC console to start
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms( 500 );

    //init oled, i2c and, scl,sda pins for i2c.
    auto scl      = hwlib::target::pin_oc( hwlib::target::pins::scl );
    auto sda      = hwlib::target::pin_oc( hwlib::target::pins::sda );
    auto i2c_bus  = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    auto oled     = hwlib::glcd_oled_i2c_128x64_buffered( i2c_bus, 0x3c );

    //start clock loop
    run(oled);
}


