#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 1001;

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool rated = false;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if (a != b)
			rated = true;
		A[i] = a;
	}
	if (rated) {
		cout << "rated" << endl;
	} else {
		bool unrated = false;
		for (int i = 1; i < n; i++) {
			if (A[i] > A[i-1])
				unrated = true;
		}
		if (unrated)
			cout << "unrated" << endl;
		else
			cout << "maybe" << endl;
	}
	return 0;
}