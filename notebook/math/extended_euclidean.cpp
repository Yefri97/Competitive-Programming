/*
Ecuaciones diofanticas
x * a + y * b = d
k * x * a + k * y * b = k * d
Solucion para todo X y Y tal que:
x = k * x1 + (b / d) * n, y = k * y1 - (a / d) * n
n: -oo ... -1, 0, 1, ... oo

Valores de n que hacen a X y Y positivos
ceil(-k * x * d / b) <= n <= floor(k * y * d / a)
ceil(-(d * x) / (double)b) <= n <= floor((d * y) / (double)a)
*/

void extendedEuclidean(ll a, ll b, ll &d, ll &x, ll &y) {
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extendedEuclidean(b, a % b, d, x, y);
		ll x1 = x, y1 = y;
		x = y1;
		y = x1 - (a / b) * y1;
	}
}

ll invModular(ll c, ll m) {
	ll d, x, y;
	extendedEuclidean(c, m, d, x, y);
	return (x + m) % m;
}
