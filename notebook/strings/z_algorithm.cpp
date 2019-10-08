vector<int> compute_z(string &s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	fori(i, 1, n) {
		if (i > r) {
			l = r = i;
			while (r < n and s[r - l] == s[r]) r++;
			z[i] = r - l; r--;
		} else {
			int k = i - l;
			if (z[k] < r - i + 1) {
				z[i] = z[k];
			} else {
				l = i;
				while (r < n and s[r - l] == s[r]) r++;
				z[i] = r - l; r--;
			}
		}
	}
	return z;
}
