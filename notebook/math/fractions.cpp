struct Fraction {
	ll p, q;
	Fraction() {}
	Fraction(ll _p, ll _q) {
		ll g = __gcd(_p, _q);
		p = _p / g; q = _q / g;
	}
	bool operator < (const Fraction &o) const {
		return p * o.q < q * o.p;
	}
	bool operator == (const Fraction &o) const {
		return p == o.p && q == o.q;
	}
};