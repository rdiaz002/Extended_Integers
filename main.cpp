#include <iostream>
#include "ex_num.h"
int main() {
    char base[] = "18446744073709551699";
    char lo[] = "18446744073709551699";
    ex_num basic(base);
    ex_num los(lo);
    ex_num s = basic + los;
    
    return 0;
}