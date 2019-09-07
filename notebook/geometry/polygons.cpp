// Polygon's Algorithms
// add PT[0] to the end

double area(vector<PT> &pol) {
	double ans = 0.0;
	for (int i = 0; i < SZ(pol) - 1; i++)
		ans += cross(pol[i], pol[i + 1]);
	return fabs(ans) * 0.5;
}

bool isConvex(vector<PT> &pol) {
	if (SZ(pol) <= 3) return false;
	bool isLeft = ccw(pol[SZ(pol) - 2], pol[SZ(pol) - 1], pol[1]);
	for (int i = 0; i < SZ(pol) - 2; i++)
		if (ccw(pol[i], pol[i + 1], pol[i + 2]) != isLeft)
			return false;
	return true;
}

// Points strictly inside
bool inPolygon(PT p, vector<PT> &pol) {
	double sum = 0;
	for (int i = 0; i < SZ(pol) - 1; i++)
		if (ccw(p, pol[i], pol[i + 1])) sum += angle(pol[i], p, pol[i + 1]);
		else sum -= angle(pol[i], p, pol[i + 1]);
	return fabs(fabs(sum) - 2 * PI) < EPS;
}