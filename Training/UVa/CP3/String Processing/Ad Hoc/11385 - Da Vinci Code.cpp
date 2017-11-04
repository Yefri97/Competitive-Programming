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

vector<string> split_line(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int next_int() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi fib(50);
	fib[0] = fib[1] = 1;
	fori(i, 2, 50)
		fib[i] = fib[i - 1] + fib[i - 2];
	int t = next_int();
	while (t--) {
		int n = next_int();
		string line;
		vector<string> input;
		getline(cin, line);
		input = split_line(line);
		getline(cin, line);
		vi v(n);
		fori(i, 0, n)
			v[i] = atoi(input[i].c_str());
		int m = *max_element(v.begin(), v.end());
		m = find(fib.begin() + 1, fib.end(), m) - fib.begin();
		string ans(m, ' ');
		int i = 0, j = 0;
		while (i < n) {
			while (!isupper(line[j])) j++;
			int idx = (find(fib.begin() + 1, fib.end(), v[i]) - fib.begin()) - 1;
			ans[idx] = line[j];
			i++;
			j++;
		}
		cout << ans << endl;
	}
	return 0;
}