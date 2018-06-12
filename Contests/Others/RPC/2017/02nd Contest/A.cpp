/*
 *  RPC 02st Contest 2017
 *  Problem A: Alphabet
 *  Outcome: Accepted | Category: Longest Increasing Subsequence (LIS)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	string line; cin >> line;
	int n = line.size();
	vector<int> lis(n);
	lis[0] = 1;
	for (int i = 1; i < n; i++) {
		int best = 0;
		for (int j = 0; j < i; j++) 
			if (line[j] < line[i])
				best = max(best, lis[j]);
		lis[i] = best + 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, lis[i]);
	cout << 26 - ans << endl;
	return 0;
}