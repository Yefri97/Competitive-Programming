// Binary search in integers numbers
int upper_bound(vector<int> &v, int k) {
	int n = v.size();
	int lo = -1, hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (v[mid] > k)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

// Binary search in floating numbers
double binary_search(args) {
	double lo = 0.0, hi = oo;
	for (int i = 0; i < num_iterations; i++) {
		double mid = (hi + lo) * 0.5;
		if (can(mid, args))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}