// O (n ^ 2)
void bubble_sort(vector<int> &v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
}