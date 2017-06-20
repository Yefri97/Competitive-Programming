// Time: 08:00min
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
	int state = 0;
	while (getline(cin, line)) {
		string result;
		fori(i, 0, line.size()) {
			if (line[i] == '\"') {
				if (state == 0)
					result += "``";
				else
					result += "''";
				state = 1 - state;
			} else {
				result.push_back(line[i]);
			}
		}
		cout << result << endl;
	}
	return 0;
}