#ifndef V2CPSE1_EXAMPLES_SET_HPP
#define V2CPSE1_EXAMPLES_SET_HPP
#include <iostream>
template<typename T, int N>
class Sett {
private:


public:
    std::array<T, N> set = {};
    std::array<bool, N> setMask = {};
    Sett(){

    }

    T max(){
        T temp = set[0];
        for (int i =0; i < N ; i++){
            if( temp < set[i]){
                temp = set[i];
            }
        }
        return temp;
    }

    void add(T x){
        bool done = true;
        if(contains(x)){

        }else{
            for (int i =0 ; i < N; i++){
                if (setMask[i] == false && done){
                    set[i] = x;
                    setMask[i] = true;
                    done = false;
                }
            }
        }
    }

    void remove( T x){
        for (int i =0 ; i < N; i++){
            if (set[i] == x){
                set[i] = 0;
                setMask[i] = false;
            }
        }
    }

    bool contains( T x){
        bool reB = false;
        for (int tempVal : set){
            if(tempVal == x){
                reB = true;
            }
        }
        return reB;
    }
    template <typename U, int P>
    friend std::ostream &operator <<( std::ostream &ost, Sett<U, P> &s);


};

template<typename T, int N>
std::ostream &operator <<( std::ostream &ost, Sett<T, N > &s) {
    for (int i =0; i < N ; i++){
        ost << i <<":" <<  s.set[i] << " ";
    }
        ost << "\n";
    return ost;
}


#endif //V2CPSE1_EXAMPLES_INTEGERSET_HPP
