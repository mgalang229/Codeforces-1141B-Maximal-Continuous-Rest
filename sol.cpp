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
	// 'mx' contains the maximal number of continuous hours
	int mx = INT_MIN;
	// 'cnt' contains the current count of resting hour
	int cnt = 0;
	// 'initial' contains the first continuous resting hours
	int initial = 0;
	bool checker = true;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			// if the current element is 1, increment 'cnt'
			cnt++;
		} else {
			if (checker) {
				// for the first encounter of 0 (working hour), store the first
				// continuous resting hours in the 'initial' variable
				initial = cnt;
			}
			// set 'checker' to false
			checker = false;
			// find the maximal number of continuous resting hours
			mx = max(mx, cnt);
			// reset 'cnt' to 0
			cnt = 0;
		}
	}
	// check if the first and last element both contains 1 (they are connected)
	if (a[0] == 1 && a[n - 1] == 1) {
		// if yes, then add to the value of the 'initial' (first continuous resting hours)
		// to 'cnt' because the end and the beginning are connected if they both contain 1
		cnt += initial;
	}
	// find the maximum for the last time between 'mx' and 'cnt'
	mx = max(mx, cnt);
	cout << mx << '\n';
	return 0;
}
