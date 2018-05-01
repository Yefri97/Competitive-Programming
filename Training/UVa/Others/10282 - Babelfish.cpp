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

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	map<string, string> mapper;
	string line;
	while (getline(cin, line) && line.size()) {
		vector<string> vs = splitLine(line);
		mapper[vs[1]] = vs[0];
		mapper[vs[0]] = vs[0];
	}
	while (getline(cin, line)) {
		string ans = mapper[line];
		cout << (ans.size() ? ans : "eh") << endl;
	}
	return 0;
}