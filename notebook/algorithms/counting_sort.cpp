void counting_sort(vector<int> &v) {
	int n = v.size(), max_val = *max_element(v.begin(), v.end());
	vector<int> freq(max_val + 1), tmp(n);
	for (int i = 0; i < n; i++)
		freq[v[i]]++;
	for (int i = 1; i <= max_val; i++)
		freq[i] += freq[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		tmp[freq[v[i]] - 1] = v[i];
		freq[v[i]]--;
	}
	for (int i = 0; i < n; i++)
		v[i] = tmp[i];
}