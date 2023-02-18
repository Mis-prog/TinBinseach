#pragma once
#include <iostream>
#include <vector>

using namespace std;

void print(int n, vector<int>& a) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

bool seach(vector<int>& N, int n, int key) {
	int left = 0, right = n - 1, middle;
	while (left <= right) {
		middle = (right + left) / 2;
		if (N[middle] == key) {
			return true;
		}
		if (N[middle] < key) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return false;
}

void test1() {
	int n, k;
	cin >> n >> k;
	vector<int> N(n), K(k);
	print(n, N);
	print(k, K);
	for (int i = 0; i < k; i++) {
		if (seach(N, n, K[i])) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}