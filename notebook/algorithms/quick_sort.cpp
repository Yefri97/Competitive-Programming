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