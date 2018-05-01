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
	string line;
	while (getline(cin, line) && line != "Game Over") {
		vector<string> input = splitLine(line);
		int n = (int)input.size(), it = 0;
		vector<int> v(n), cnt(n, 1);
		fori(f, 0, 10) {
			char c = input[it][0];
			if (isdigit(c)) {
				v[it] = c - '0';
				it++;
				char cc = input[it][0];
				if (isdigit(cc)) {
					v[it] = cc - '0';
				} else {
					v[it] = 10 - v[it - 1];
					if (f < 9) cnt[it + 1]++;
					else v[it + 1] = (isdigit(input[it + 1][0]) ? input[it + 1][0] - '0' : 10);
				}
				it++;
			} else {
				v[it] = 10;
				if (f < 9) {
					cnt[it + 1]++;
					cnt[it + 2]++;
				} else {
					char cc;
					it++;
					cc = input[it][0];
					v[it] = (cc == 'X' ? 10 : cc - '0');
					it++;
					cc = input[it][0];
					v[it] = (cc == 'X' ? 10 : cc == '/' ? 10 - v[it - 1] : cc - '0');
				}
				it++;
			}
		}
		int ans = 0;
		fori(i, 0, n)
			ans += cnt[i] * v[i];
		cout << ans << endl;
	}
	return 0;
}