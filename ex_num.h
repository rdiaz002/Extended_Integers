//
// Created by Ronny on 9/15/2017.
//

#ifndef EXT_NUMBERS_TUT_EX_NUM_H
#define EXT_NUMBERS_TUT_EX_NUM_H

#include <stdlib.h>
#include <vector>

typedef std::vector<char> vec;

class ex_num {
public :
    ex_num();

    ex_num(char *);

    ex_num(const ex_num &);

    ex_num operator-(ex_num &);

    ex_num operator+(ex_num &);

    template<typename T>
    ex_num operator+(T b) {
        ex_num temp(itoa(b, new char, 10));
        return *this + temp;
    }

    template<typename T>
    ex_num operator-(T b) {
        ex_num temp(itoa(b, new char, 10));
        return *this - temp;
    }

    ~ex_num();

    friend std::ostream &operator<<(std::ostream &, const ex_num &);

private:
    void clean_up(ex_num &);
    void sub_recur(vec &, vec &, int index = 0);
    vec data;
    bool sign;


};


#endif //EXT_NUMBERS_TUT_EX_NUM_H
