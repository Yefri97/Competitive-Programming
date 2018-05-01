// Sorting algorithms

// O(n ** 2)
void bubble_sort(vector<int> &v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
}

// O(n + max_element)
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

// O(n ** 2)
void insertion_sort(vector<int> &v) {
	for (int i = 0; i < n; i++) {
		int n = v.size();
		int x = v[i], j = i;
		while (j > 0 && v[j - 1] > x) {
			v[j] = v[j - 1];
			j--;
		}
		v[j] = x;
	}
}

// O(n * lg(n))
void merge_sort(vector<int> &v, int l, int r) {
	if (l + 1 == r) return;
	int m = (l + r) / 2;
	merge_sort(v, l, m);
	merge_sort(v, m, r);
	vector<int> tmp(r - l);
	for (int i = l, j = m, k = 0; i < m or j < r; k++) {
		if (j == r || (i < m && v[i] <= v[j])) {
			tmp[k] = v[i];
			i++;
		} else {
			tmp[k] = v[j];
			j++;
		}
	}
	for (int i = 0; i < (int)tmp.size(); i++)
		v[l + i] = tmp[i];
}

// O(n ** 2) | Theta(n * lg(n))
void quick_sort(vector<int> &v, int l, int r) {
	int key = v[l + rand() % (r - l + 1)];
	int i = l, j = r;
	do {
		while (v[i] < key) i++;
		while (v[j] > key) j--;
		if (i <= j) {
			swap(v[i], v[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j) quickSort(l, j);
	if (i < r) quickSort(i, r);
}

// O()
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

// O (n ** 2)
void selection_sort(vector<int> &v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int min_val = i;
		for (int j = i + 1; j < n; j++)
			if (v[j] < v[min_val])
				min_val = j;
		swap(v[i], v[min_val]);
	}
}