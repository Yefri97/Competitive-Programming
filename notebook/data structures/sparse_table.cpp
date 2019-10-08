const int MN = 100000;
const int ML = 18;

int T[MN][ML];
int ln[MN];

void build(vi &v) {
	// log2 O(1)
	ln[1] = 0;
	for (int i = 2; i < MN; i++)
		ln[i] = ln[i / 2] + 1;
	// Sparse table
	int n = v.size();
	for (int i = 0; i < n; i++)
		T[i][0] = v[i];
	for (int j = 1, p = 2; p <= n; j++, p <<= 1)
		for (int i = 0; i + p - 1 < n; i++)
			T[i][j] = min(T[i][j - 1], T[i + (p >> 1)][j - 1]);
}

int query(int l, int r) {
	int k = ln[r - l + 1];
	return min(T[l][k], T[r + 1 - (1 << k)][k]);
}