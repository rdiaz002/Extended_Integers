#include <iostream>
#include "ex_num.h"
int main() {
    char int_a[] = "10000000000000000000000000";
    char int_b[] = "10";

    ex_num ex_int_a(int_a);
    ex_num ex_int_b(int_b);
    ex_num s = ex_int_a + ex_int_b;
    //std::cout<<ex_int_a<<std::endl;
    std::cout<<ex_int_a - 13;

    return 0;
}