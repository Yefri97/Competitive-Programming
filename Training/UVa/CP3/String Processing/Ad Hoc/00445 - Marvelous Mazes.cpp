// Output Fomatting
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	while (getline(cin, line)) {
		fori(it, 0, line.size()) {
			if (line[it] == '!') {
				cout << endl;
				continue;
			}
			int cont = 0;
			while (isdigit(line[it])) {
				cont += line[it] - '0';
				it++;
			}
			fori(i, 0, cont)
				cout << (line[it] == 'b' ? ' ' : line[it]);
		}
		cout << endl;
	}
	return 0;
}