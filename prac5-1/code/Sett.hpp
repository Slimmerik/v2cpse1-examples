#ifndef V2CPSE1_EXAMPLES_SET_HPP
#define V2CPSE1_EXAMPLES_SET_HPP
#include <iostream>

class Sett {
private:


public:
    std::array<int, 10> set = {};
    std::array<bool, 10> setMask = {};
    Sett(){

    }

    void add(int x){
        bool done = true;
        if(contains(x)){

        }else{
            for (int i =0 ; i < 10; i++){
                if (setMask[i] == false && done){
                    set[i] = x;
                    setMask[i] = true;
                    done = false;
                }
            }
        }
    }

    void remove( int x){
        for (int i =0 ; i < 10; i++){
            if (set[i] == x){
                set[i] = 0;
                setMask[i] = false;
            }
        }
    }

    bool contains( int x){
        bool reB = false;
        for (int tempVal : set){
            if(tempVal == x){
                reB = true;
            }
        }
        return reB;
    }
   friend std::ostream &operator <<( std::ostream &ost, Sett &s);
};

std::ostream &operator <<( std::ostream &ost, Sett &s) {
    ost << s.set[0] << " "
        << s.set[1] << " "
        << s.set[2] << " "
        << s.set[3] << " "
        << s.set[4] << " "
        << s.set[5] << " "
        << s.set[6] << " "
        << s.set[7] << " "
        << s.set[8] << " "
        << s.set[9] << "\n";
    return ost;
}
#endif //V2CPSE1_EXAMPLES_INTEGERSET_HPP
