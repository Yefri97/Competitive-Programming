typedef vector<int> Row;
typedef vector<Row> Matrix;

Matrix mult(Matrix a, Matrix b, int m) {
	Matrix ans = Matrix(SZ(a), Row(SZ(b[0])));
	for (int i = 0; i < SZ(a); i++) {
		for (int j = 0; j < SZ(b[0]); j++) {
			for (int k = 0; k < SZ(b); k++)
				ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % m;
		}
	}
	return ans;
}

Matrix fastExp(Matrix b, int e, int m) {
	Matrix ans = Matrix(SZ(b), Row(SZ(b)));
	for (int i = 0; i < SZ(b); i++) ans[i][i] = 1;
	while (e > 0) {
		if (e & 1) ans = mult(ans, b, m);
		b = mult(b, b, m);
		e >>= 1;
	}
	return ans;
}