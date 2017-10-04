//
// Created by Ronny on 9/15/2017.
//

#ifndef EXT_NUMBERS_TUT_EX_NUM_H
#define EXT_NUMBERS_TUT_EX_NUM_H
#include <stdlib.h>
#include <vector>
class ex_num {
public :
    ex_num ();
    ex_num (char * );
    ex_num(const ex_num & );
    ex_num operator - (ex_num & b);
    ex_num operator + (ex_num & b);
    ~ex_num();
    friend std::ostream & operator << (std::ostream& ,const ex_num &);
private:
void sub_recur(std::vector<int> &, std::vector<int> &,int index = 0);

std::vector<int> data;


};


#endif //EXT_NUMBERS_TUT_EX_NUM_H
