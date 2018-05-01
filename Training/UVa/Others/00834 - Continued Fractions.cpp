#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b;
	while (cin >> a >> b) {
		if (b == 1) { cout << "[" << a << "]" << endl; continue; }
		bool first = true;
		cout << "[";
		while (b) {
			cout << a / b;
			if (b != 1) cout << (first ? ";" : ","); first = false;
			int tmpA = b;
			int tmpB = a % b;
			a = tmpA;
			b = tmpB;
		}
		cout << "]" << endl;
	}
	return 0;
}