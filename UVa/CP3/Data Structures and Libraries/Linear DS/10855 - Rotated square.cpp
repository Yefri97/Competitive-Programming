// 2D Array Manipulation
#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

vvc rotate(vvc mat) {
	int n = mat.size();
	vvc target(n, vc(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			target[j][n - i - 1] = mat[i][j];
		}
	}
	return target;
}

int solver(vvc a, vvc b) {
	int ans = 0, na = a.size(), nb = b.size();
	for (int i = 0; i < na - nb + 1; i++) for (int j = 0; j < na - nb + 1; j++) {
		int cont = 0;
		for (int k = 0; k < nb; k++) for (int l = 0; l < nb; l++) {
			cont += (a[i + k][j + l] == b[k][l]);
		}
		ans += (cont == nb * nb);
	}
	return ans;
}

int main() {
	int na, nb;
	while (cin >> na >> nb && (na || nb)) {
		vvc mata(na, vc(na)), matb(nb, vc(nb));
		for (int i = 0; i < na; i++)
			for (int j = 0; j < na; j++)
				cin >> mata[i][j];
		for (int i = 0; i < nb; i++)
			for (int j = 0; j < nb; j++)
				cin >> matb[i][j];
		int a = solver(mata, matb);
		int b = solver(mata, rotate(matb));
		int c = solver(mata, rotate(rotate(matb)));
		int d = solver(mata, rotate(rotate(rotate(matb))));
		cout << a << " " << b << " " << c << " " << d << endl;
	}
	return 0;
}