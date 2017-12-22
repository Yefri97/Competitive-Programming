void radix_sort(vector<int> &v) {
	int n = v.size();
	int step = 1, mmax = *max_element(v.begin(), v.end());
	while (step <= mmax) {
		// counting sort
		vector<int> freq(10), tmp(n);
		for (int i = 0; i < n; i++)
				freq[(v[i] / step) % 10]++;
		for (int i = 1; i < 10; i++)
				freq[i] += freq[i - 1];
		for (int i = n - 1; i >= 0; i--) {
				tmp[freq[(v[i] / step) % 10] - 1] = v[i];
				freq[(v[i] / step) % 10]--;
		}
		for (int i = 0; i < n; i++)
				v[i] = tmp[i];
		step *= 10;
	}
}