#include <string>
#include <iostream>
#include "card.hpp"

namespace ariel {
    // default constructor
    Card::Card(){};
    // value ans sign constructor
    Card::Card(int v, int s){
        if(v <= 13 && v >= 1){
            (this)->value = v;
        }
        if(s <= 4 && s >= 1){
            (this)->sign = s;
        }
    }     
}
