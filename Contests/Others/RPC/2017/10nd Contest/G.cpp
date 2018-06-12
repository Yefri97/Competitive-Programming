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

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int nextInt() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = nextInt();
	while (t--) {
		string line; getline(cin, line);
		vector<string> input = splitLine(line);
		vector<int> v;
		for (string s : input)
			v.push_back(atoi(s.c_str()));
		int max_val = *max_element(v.begin(), v.end());
		int ans = 0, b = 0;
		fori(i, 0, (int)v.size()) {
			if (v[i] == max_val) {
				ans += b;
				b = 1 - b;
			}
			ans += b;
		}
		cout << ans << endl;
	}
	return 0;
}