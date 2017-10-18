//
// Created by Ronny on 9/15/2017.
//

#include <iostream>
#include <cstring>
#include "ex_num.h"


ex_num::ex_num() {

}

ex_num::ex_num(char *val) {
    sign=(val[0]=='-' ?  true: false);
    int j = 0;
    sign? j=1: j=0;

    for (int i = strlen(val) - 1; i >= j; i--) {
        data.push_back((int) *(val + i) - 48);
    }

    clean_up(*(this));
}

ex_num::ex_num(const ex_num &) {

}

ex_num ex_num::operator-(ex_num &b) {
    int max_size = std::max(b.data.size(), data.size());
    vec tempb;
    tempb.resize(max_size + 1);
    vec tempa;
    tempa.resize(max_size + 1);
    std::copy(b.data.begin(), b.data.end(), tempb.begin());
    std::copy(data.begin(), data.end(), tempa.begin());

    for (int i = 0; i < tempa.size(); i++) {
        if (tempa.at(i) < tempb.at(i)) {
            sub_recur(tempa, tempb, i + 1);
        }
        tempb[i] = tempa[i] - tempb[i];
    }
    ex_num d;
    d.data.resize(max_size + 1);
    std::copy(tempb.begin(), tempb.end(), d.data.begin());
    clean_up(d);
    return d;
}

ex_num ex_num::operator+(ex_num &b) {
    int max_size = std::max(b.data.size(), data.size());
    vec tempb;
    tempb.resize(max_size + 1);
    vec tempa;
    tempa.resize(max_size + 1);
    std::copy(b.data.begin(), b.data.end(), tempb.begin());
    std::copy(data.begin(), data.end(), tempa.begin());
    ex_num d;
    d.data.resize(max_size + 1);
    for (int i = 0; i < max_size; i++) {
        if ((tempa.at(i) + tempb.at(i)) >= 10) {
            d.data.at(i) = (tempa.at(i) + tempb.at(i)) % 10;
            tempa.at(i + 1) += 1;
        } else {
            d.data.at(i) = (tempa.at(i) + tempb.at(i));
        }
    }
    clean_up(d);
    return d;
}

void ex_num::sub_recur(vec &a, vec &b, int index) {
    if (a.at(index) > b.at(index)) {
        a.at(index) -= 1;
    } else {
        sub_recur(a, b, index + 1);
        a.at(index) -= 1;
    }
    a.at(index - 1) += 10;
    return;
}

ex_num::~ex_num() {

}

void ex_num::clean_up(ex_num &d) {
    while (*(d.data.end() - 1) == 0 && d.data.size() > 1) {
        d.data.erase(d.data.end() - 1);
    }
}

std::ostream &operator<<(std::ostream &cout, const ex_num &b) {

    for (int i = b.data.size() - 1; i >= 0; i--) {
        cout << (int) b.data.at(i);
    }
    return cout;
}
