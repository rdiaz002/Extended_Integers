#include <iostream>
#include "ex_num.h"
int main() {
    char int_a[] = "18446744073709551699";
    char int_b[] = "18446744073709551698";
    ex_num ex_int_a(int_a);
    ex_num ex_int_b(int_b);
    ex_num s = ex_int_a + ex_int_b;
    std::cout<<s<<std::endl;
    return 0;
}