#pragma once
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& N,int maxN) {
    for (int i = 0; i < maxN; i++) {
        cin >> N[i];
    }
}

int minnumber(int a,int b,int key) {
    if (abs(a - key) <= abs(b - key)) {
        return a;
    }
    else {
        return b;
    }
}

int seach(vector<int>& N, int key,int maxN) {
    int left = 0, right = maxN-1;
    int middle = (left + right) / 2;
    while (left <= right) {
        if (N[middle] == key) {
            return key;
        }
        if (abs(right - left) == 1) {
            /*if (left == 0) {
                return minnumber(N[left], N[right], key);
            }
            if (right == (N.size() - 1)) {
                return minnumber(N[left], N[right], key);
            }*/
            int a = minnumber(N[middle-1], N[left], key);
            int b = minnumber(N[left], N[right], key);
            int c = minnumber(N[right], N[middle+1], key);
            int m = min(a,min(b,c));
            return m;
        }
        if (N[middle] > key) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
        middle = (left + right) / 2;
    }
    if (right < 0) {
        return N[left];
    }
    else {
        return N[right];
    }
}

void test2() {
    int n, k;
    cin >> n >> k;
    vector<int> N(n+1), K(k+1);
    print(N,n); print(K,n);
    for (int i = 0; i < k; i++) {
        cout << seach(N, K[i],n) << endl;
    }
}