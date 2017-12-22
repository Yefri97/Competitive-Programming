// O (n ^ 2)
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