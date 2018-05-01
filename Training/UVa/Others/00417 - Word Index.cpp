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

int id;
string s;
map<string, int> mapper;

void gen(int k, int n) {
	if (n == 0) { mapper[s] = id++; return; }
	fori(i, k, 26) {
		s.push_back(i + 'a');
		gen(i + 1, n - 1);
		s.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	id = 1;
	gen(0, 1);
	gen(0, 2);
	gen(0, 3);
	gen(0, 4);
	gen(0, 5);
	string q;
	while (cin >> q)
		cout << mapper[q] << endl;
	return 0;
}