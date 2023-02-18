#pragma once
#include <iostream>
#include <math.h>
#include "iomanip"
using namespace std;

long double function(int x) {
    long double left = 0, right = x;
    long double result = (left + right) / 2;
    while (abs(x - (result * result + sqrt(result + 1))) > 0.0000000000000001) {
        if ((result * result + sqrt(result + 1)) > x) {
            right = result;
        }
        else {
            left = result;
        }
        result = (left + right) / 2;
    }
    return result;
}

void test4() {
    double x;
    cin >> x;
    cout << setprecision(20) << function(x);
}