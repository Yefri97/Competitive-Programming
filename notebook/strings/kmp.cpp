void kmp(string T, string P) {
	int n = T.size(), m = P.size();
	vector<int> b(m + 1); b[0] = -1;
	// Preprocess P
	int i = 0, j = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
	// Search T
	i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if (j == m) {
			cout << "P is found at index " << i - j << endl;
			j = b[j];
		}
	}
}