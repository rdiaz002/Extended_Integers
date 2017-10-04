//
// Created by Ronny on 9/15/2017.
//

#include <iostream>
#include <cstring>
#include "ex_num.h"

ex_num::ex_num() {

}

ex_num::ex_num(char *val) {
    for (int i = 0; i < strlen(val); i++) {
        data.push_back((int) *(val + i) - 48);
    }
    std::cout << data[0] << std::endl;
    std::cout << std::endl;
}

ex_num::ex_num(const ex_num &) {

}

ex_num ex_num::operator-(ex_num &b) {
    std::vector<int> tempb;
    tempb.resize(b.data.size());
    std::vector<int> tempa;
    tempa.resize(data.size());
    std::copy(b.data.begin(), b.data.end(), tempb.begin());
    std::copy(data.begin(), data.end(), tempa.begin());

    while (tempb.size() < tempa.size()) {
        tempb.insert(tempb.begin(), 0);
    }
    for (int i = tempa.size() - 1; i >= 0; i--) {
        if (tempa.at(i) < tempb.at(i)) {
            sub_recur(tempa, tempb, i - 1);
        }
        tempb[i] = tempa[i] - tempb[i];
    }
    ex_num d;
    d.data.resize(tempb.size());
    std::copy(tempb.begin(), tempb.end(), d.data.begin());
    return d;
}

ex_num ex_num::operator+(ex_num &b) {
    std::vector<int> tempb;
    tempb.resize(b.data.size() + 1);
    std::vector<int> tempa;
    tempa.resize(data.size() + 1);
    std::copy(b.data.begin(), b.data.end(), tempb.begin() + 1);
    std::copy(data.begin(), data.end(), tempa.begin() + 1);
    ex_num d;
    d.data.resize(tempa.size());
    while (tempb.size() < tempa.size()) {
        tempb.insert(tempb.begin(), 0);
    }
    for (int i = tempa.size() - 1; i >= 0; i--) {
        if ((tempa.at(i) + tempb.at(i)) >= 10) {
            d.data.at(i) = (tempa.at(i) + tempb.at(i)) % 10;
            tempa.at(i - 1) += 1;
        } else {
            d.data.at(i) = (tempa.at(i) + tempb.at(i));
        }
    }
    return d;
}

void ex_num::sub_recur(std::vector<int> &a, std::vector<int> &b, int index) {
    if (a.at(index) > b.at(index)) {
        a.at(index) -= 1;
    } else {
        sub_recur(a, b, index - 1);
        a.at(index) -= 1;
    }
    a.at(index + 1) += 10;
    return;
}

ex_num::~ex_num() {

}
