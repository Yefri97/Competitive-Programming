// Just Ad Hoc
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 1010;
double A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n) {
		double avg = 0;
		fori(i, 0, n) {
			cin >> A[i];
			avg += A[i];
		}
		avg = avg / n;
		double pos = 0, neg = 0;
		fori(i, 0, n) {
			double v = (int)((A[i] - avg) * 100.0) / 100.0;
			if (v > 0) pos += v;
			else neg -= v;
		}
		cout << "$" << fixed << setprecision(2) << (neg > pos ? neg : pos) << endl;
	}
	return 0;
}