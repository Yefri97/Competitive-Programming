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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a;
	while (getline(cin, a)) {
		string b; getline(cin, b);
		vector<string> input = splitLine(a);
		int n = input.size();
		vi c(n);
		fori(i, 0, n)
			c[i] = atoi(input[i].c_str());
		input = splitLine(b);
		int m = input.size(), first = 1;
		fori(i, 0, m) {
			int x = atoi(input[i].c_str()), ans = 0;
			fori(j, 0, n)
				ans = x * ans + c[j];
			if (!first) cout << " "; first = 0;
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}