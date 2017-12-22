// O (n ^ 2)
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