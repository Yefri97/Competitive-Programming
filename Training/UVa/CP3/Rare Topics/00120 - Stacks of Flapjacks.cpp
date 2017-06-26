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

vector<string> split(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int n;
vector<int> sp;

void flip(int pos) {
	cout << n - pos << " ";
	fori(j, 0, (pos + 1) / 2)
		swap(sp[j], sp[pos - j]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	while (getline(cin, line)) {
		cout << line << endl;
		vector<string> tokens = split(line);
		sp.clear();
		fori(i, 0, tokens.size()) sp.push_back(atoi(tokens[i].c_str()));
		n = sp.size();
		for (int i = n - 1; i >= 0; i--) {
			int max_val = -1, idx;
			for (int j = i; j >= 0; j--) {
				if (max_val < sp[j]) {
					max_val = sp[j];
					idx = j;
				}
			}
			if (idx != i) {
				if (idx != 0)
					flip(idx);
				flip(i);
			}
		}
		cout << 0 << endl;
	}
	return 0;
}