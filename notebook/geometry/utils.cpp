// float precision
bool const operator == (double a, double b) { return fabs(a - b) < EPS; }
bool const operator >= (double a, double b) { return a - b > -EPS; }

// Rotate a point by a angle tetha(rad) ccw around (0, 0)
PT rotate(PT p, double tetha) {
	// rad = tetha * PI / 180.0
	int x = p.x * cos(tetha) - p.y * sin(tetha);
	int y = p.x * sin(tetha) + p.y * cos(tetha);
	return PT(x, y);
}

PT toVec(PT a, PT b) { return PT(b.x - a.x, b.y - a.y); }
PT scale(PT v, double s) { return PT(v.x * s, v.y * s); }
PT translate(PT p, PT v) { return PT(p.x + v.x, p.y + v.y); }

double norm_sq(PT v) { return v.x * v.x + v.y * v.y; }
double dot(PT v1, PT v2) { return (v1.x * v2.x + v1.y * v2.y); }
double cross(PT v1, PT v2) { return v1.x * v2.y - v1.y * v2.x; }

// closest point from p to the line defined by two points a and b
PT closestToLine(PT p, PT a, PT b) {
	// formula: c = a + u * ab
	PT ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / dot(ab, ab);
	// if (u < 0.0) return a;
	// if (u > 1.0) return b;
	return translate(a, scale(ab, u));
}

// return angle aob in rad
double angle(PT a, PT o, PT b) {
	PT oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// Given three collinear points p, q, r, checks point r lies on line segment pq
bool onSegment(PT p, PT q, PT r) {
	if (p.x > q.x) swap(p.x, q.x);
	if (p.y > q.y) swap(p.y, q.y);
	return (p.x <= r.x && r.x <= q.x && p.y <= r.y && r.y <= q.y);
}

// return true if point r is on the left side of line pq
bool ccw(PT p, PT q, PT r) { return cross(toVec(p, q), toVec(p, r)) > 0; }

// return true if point r is on the same line as the line pq
bool collinear(PT p, PT q, PT r) { return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

// find orientation of ordered triplet (p, q, r)
int orientation(PT p, PT q, PT r) {
	if (collinear(p, q, r)) return 0;
	return ccw(p, q, r) ? 1 : -1;
}

// check if line segment 'p1q1' and 'p2q2' intersect
bool doIntersect(PT p1, PT q1, PT p2, PT q2) {
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4) return true;
	if (o1 == 0 && onSegment(p1, q1, p2)) return true;
	if (o2 == 0 && onSegment(p1, q1, q2)) return true;
	if (o3 == 0 && onSegment(p2, q2, p1)) return true;
	if (o4 == 0 && onSegment(p2, q2, q1)) return true;
	return false;
}

// Given 2 points on the circle (p1 and p2) and radius r of the corresponding circle
// we can determine the location of the centers (c1 andc2) of the two possible circles 
bool circle2PtsRad(PT p1, PT p2, double r, PT &c) {
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	double det = r * r / d2 - 0.25;
	if (det < 0.0) return 0;
	double h = sqrt(det);
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true; // to get the other center, reverse p1 and p2
}

// Returns the area of ​​a regular polygon of n sides and length l
double area(int n, int l) { return n * (l * 0.5) * (l * 0.5 / tan(PI / n)); }