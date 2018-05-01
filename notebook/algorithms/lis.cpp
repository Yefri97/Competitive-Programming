// Longest Increasing Subsequence

// O(n ** 2)
int LIS(vector<int> &v) {
	int n = v.size();
	vector<int> lis(n, 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (v[j] < v[i])
				lis[i] = max(lis[i], lis[j] + 1);
	return *max_element(lis.begin(), lis.end());
}

// O(n * log(n))
int LIS(vector<int> &v) {
	int n = v.size(), lis = 0;
	vector<int> L(n);
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(L.begin(), L.begin() + lis, v[i]) - L.begin();
		L[pos] = v[i];
		lis = max(pos + 1, lis);
	}
	return lis;
}
