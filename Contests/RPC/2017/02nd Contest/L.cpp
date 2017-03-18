/*
 *  RPC 02st Contest 2017
 *  Problem H: Barbells
 *  Outcome: Accepted | Category: Brute Force + Bitsmask
 */
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v.size(); j++)
			if ((v[i] ^ v[j]) == (v[i] | v[j])) return true;
	return false;
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> barbells(n), plates(m);
	for (int i = 0; i < n; i++)
		cin >> barbells[i];
	for (int i = 0; i < m; i++)
		cin >> plates[i];
	int limit = 1 << m;
	map< int, vector<int> > subsets;
	for (int mask = 0; mask < limit; mask++) {
		int acc = 0;
		for (int j = 0; j < m; j++) {
			if (mask & (1 << j))
				acc += plates[j];
		}
		subsets[acc].push_back(mask);
	}
	set<int> weights;
	for (int i = 0; i < n; i++)
		weights.insert(barbells[i]);
	for (map< int, vector<int> >::iterator it = subsets.begin(); it != subsets.end(); it++) {
		if (check(it->second)) {
			for (int i = 0; i < n; i++)
				weights.insert(barbells[i] + 2 * (it->first));
		}
	}
	for (set<int>::iterator it = weights.begin(); it != weights.end(); it++)
		cout << *it << endl;
	return 0;
}