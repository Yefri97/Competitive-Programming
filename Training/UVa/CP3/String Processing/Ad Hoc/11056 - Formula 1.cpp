#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int to_int(string n) { return atoi(n.c_str()); }

struct ST {
	int min, sec, ms;
	string name1, name2;
	ST() {}
	ST(string _min, string _sec, string _ms, string _name) {
		min = to_int(_min);
		sec = to_int(_sec);
		ms = to_int(_ms);
		name1 = _name;
		fori(i, 0, (int)_name.size())
			name2.push_back(tolower(_name[i]));
	}
	bool operator < (const ST &o) const {
		if (min != o.min) return min < o.min;
		if (sec != o.sec) return sec < o.sec;
		if (ms != o.ms) return ms < o.ms;
		return name2 < o.name2;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		vector<ST> v(n);
		fori(i, 0, n) {
			string name, min, sec, ms, b;
			cin >> name;
			cin >> b;
			cin >> min;
			cin >> b;
			cin >> sec;
			cin >> b;
			cin >> ms;
			cin >> b;
			v[i] = ST(min, sec, ms, name);
		}
		sort(v.begin(), v.end());
		for (int i = 0, r = 1; i < n; i += 2, r++) {
			cout << "Row " << r << endl;
			cout << v[i].name1 << endl;
			if (i + 1 < n) cout << v[i + 1].name1 << endl;
		}
		cout << endl;
	}
	return 0;
}