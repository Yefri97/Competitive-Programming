// Mo's Algorithm O(n * sqrt(n))

const int ROOT = 200;

struct Query {
	int id;
	int L, R;
	Query() {}
	Query(int _id, int _L, int _R) : id(_id), L(_L), R(_R) {}
};

bool cmp(Query a, Query b) {
	if (a.L / ROOT == b.L / ROOT)
		return a.R < b.R;
	return a.L / ROOT < b.L / ROOT;
}

void mo(vi &a, vector<Query> &qs, vi &ans) {
	sort(qs.begin(), qs.end(), cmp);
	int currL = 0, currR = 0;
	int currSum = 0;
	fori(i, 0, SZ(qs)) {
		int L = qs[i].L, R = qs[i].R;
		while (currL < L) {
			currSum -= a[currL];
			currL++;
		}
		while (currL > L) {
			currSum += a[currL - 1];
			currL--;
		}
		while (currR <= R) {
			currSum += a[currR];
			currR++;
		}
		while (currR > R + 1) {
			currSum -= a[currR - 1];
			currR--;
		}
		ans[qs[i].id] = currSum;
	}
}