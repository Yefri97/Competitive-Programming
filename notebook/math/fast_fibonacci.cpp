// Fast fibonacci sequence
void mult(ll A[2][2], ll B[2][2]) {
	ll a = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	ll b = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	ll c = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	ll d = A[1][0] * B[0][1] + A[1][1] * B[1][1];
	A[0][0] = a % MD;
	A[0][1] = b % MD;
	A[1][0] = c % MD;
	A[1][1] = d % MD;
}

void power(ll M[2][2], int e) {
	if (e == 0 || e == 1)
		return;

	ll F[2][2] = {{1, 1}, {1, 0}};

	power(M, e >> 1);
	mult(M, M);

	if (e % 2)
		mult(M, F);
}

ll fib(int n) {
	ll A[2][2] = {{f(2), f(1)}, {f(1), f(0)}};
	ll M[2][2] = {{1, 1}, {1, 0}};

	power(M, n - 1);

	if (n > 1) mult(A, M);

	return A[0][1];
}