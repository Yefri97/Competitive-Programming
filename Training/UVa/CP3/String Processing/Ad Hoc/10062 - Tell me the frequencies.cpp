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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool first = true;
	string line;
	while (getline(cin, line)) {
		if (!first) cout << endl; first = false;
		map<int, int> mapper;
		for(char c : line)
			mapper[c]++;
		vii ans;
		for (auto x : mapper)
			ans.push_back(ii(x.second, -x.first));
		sort(ans.begin(), ans.end());
		for (auto x : ans)
			cout << -x.second << " " << x.first << endl;
	}
	return 0;
}