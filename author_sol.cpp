#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int result = 0;
	int len = 0;
	// In case of multiple days, consider the given sequence as a cyclic sequence. 
	// Concatenate the sequence twice and solve the previous case. 
	// Sure, it is not necessary to concatenate it in explicit way, 
	// just use a[i % n] instead of a[n] and process i = 0 ... 2 * n - 1.
	for (int i = 0; i < 2 * n; i++) {
		if (a[i % n] == 1) {
			len++;
			result = max(result, len);
		} else {
			len = 0;
		}
	}
	cout << result << '\n';
	return 0;
}
