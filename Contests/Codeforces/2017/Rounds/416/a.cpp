#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b; cin >> a >> b;
	int x = pow((double)a, 0.5), y = (pow(4 * (double)b + 1, 0.5) - 1) / 2;
	if (x > y)
		cout << "Valera" << endl;
	else
		cout << "Vladik" << endl;
	return 0;
}