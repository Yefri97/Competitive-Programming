ll x, y, d;

void extendedEuclidean(ll a, ll b) {
	if (b == 0) { d = a; x = 1; y = 0; return; }
	extendedEuclidean(b, a % b);
	ll x1 = x;
	ll y1 = y;
	x = y1;
	y = x1 - y1 * (a / b);
}

// Ecuaciones diofanticas
// x * a + y * b = d
// k * x * a + k * y * b = k * d
// Solucion para todo X y Y tal que:
// x = k * x1 + (a / d) * n, y = k * y1 + (b / d) * n
// n: -oo ... -1, 0, 1, ... oo
// 
// Valores de n que hacen a X y Y positivos
// ceil(-k * x * d / b) <= n <= floor(k * y * d / a)