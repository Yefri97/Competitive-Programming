// Mathematical Simulation (Brute Force), Harder
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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		int result = n, bottles = n;
		while (bottles > 2) {
			result += bottles / 3;
			bottles = bottles / 3 + bottles % 3;
		}
		result += (bottles == 2 ? 1 : 0);
		cout << result << endl;
	}
	return 0;
}