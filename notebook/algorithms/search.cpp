// Searching algorithms

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

// Ternary search in integers numbers
int ternary_search(vector<int> &v) {
	int n = v.size();
	int lo = 0, hi = n - 1;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (A[mid] < A[mid + 1])
			lo = mid;
		else
			hi = mid;
	}
	return lo + 1;
}

// Ternary search in floating numbers
double ternary_search(args) {
	double lo = 0.0, hi = oo;
	for (int i = 0; i < num_iterations; i++) {
		double mid1 = (l * 2 + r) / 3; // l + (r - l) / 3
		double mid2 = (l + 2 * r) / 3; // r - (r - l) / 3
		if (f(mid1, args) < f(mid2, args))
			lo = mid1;
		else
			hi = mid2;
	}
	return lo;
}