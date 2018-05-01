#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

bool check(vi &A, vi &B) {
	fori(i, 0, 3) if (A[i] == B[0])
		return false;
	fori(i, 1, 3) if (B[i] == B[0])
		return false;
	fori(i, 0, 3) {
		int win = 0;
		fori(j, 0, 3) {
			vi a, b;
			int cnt = B[i] > A[j];
			fori(k, 0, 3) if (k != j)
				a.push_back(A[k]);
			fori(k, 0, 3) if (k != i)
				b.push_back(B[k]);
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			if (b[0] > a[0] && b[0] > a[1])
				cnt += 2;
			else if (b[0] > a[0] && b[0] < a[1] || b[0] < a[0] && b[1] > a[1])
				cnt += 1;
			win += (cnt >= 2);
		}
		if (win == 3) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi A(3), B(3);
	while (cin >> A[0] && A[0]) {
		fori(i, 1, 3)
			cin >> A[i];
		fori(i, 1, 3)
			cin >> B[i];
		B[0] = 1;
		while (B[0] < 53) {
			if (check(A, B)) break;
			B[0]++;
		}
		cout << (B[0] < 53 ? B[0] : -1) << endl;
	}
	return 0;
}
