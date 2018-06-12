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

vi splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	vi v;
	for (string s : tokens)
		v.push_back(atoi(s.c_str()));
	return v;
}

int nextInt() {
	string line; getline(cin, line);
	return atoi(line.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = nextInt();
	while (t--) {
		string line; getline(cin, line);
		vi v = splitLine(line);
		int n = v.size() - 1, max_val = -1, flag = 0;
		for (int x : v) {
			if (!flag && x == n) { flag = 1; continue; }
			max_val = max(max_val, x);
		}
		cout << max_val << endl;
	}
	return 0;
}