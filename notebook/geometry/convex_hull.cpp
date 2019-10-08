// O(n * log(n))
bool cmp(PT a, PT b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

vector<PT> convexHull(vector<PT> pts) {
	sort(pts.begin(), pts.end(), cmp);
	vector<PT> S;
	// Lower Hull
	for (int i = 0; i < SZ(pts); i++) {
		while (SZ(S) > 1 && !ccw(S[SZ(S) - 2], S[SZ(S) - 1], pts[i]))
			S.pop_back();
		S.push_back(pts[i]);
	}
	// Upper Hull
	for (int i = SZ(pts) - 2, t = SZ(S); i >= 0; i--) {
		while (SZ(S) > t && !ccw(S[SZ(S) - 2], S[SZ(S) - 1], pts[i]))
			S.pop_back();
		S.push_back(pts[i]);
	}
	return S;
}