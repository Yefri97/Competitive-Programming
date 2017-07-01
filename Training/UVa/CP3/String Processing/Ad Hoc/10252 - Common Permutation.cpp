// Frequency Counting
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
	string a;
	while (getline(cin, a)) {
		string b; getline(cin, b);
		vector<int> freqA(26), freqB(26);
		fori(i, 0, a.size())
			freqA[a[i] - 'a']++;
		fori(i, 0, b.size())
			freqB[b[i] - 'a']++;
		string ans;
		fori(i, 0, 26) {
			int x = min(freqA[i], freqB[i]);
			fori(j, 0, x)
				ans.push_back(i + 'a');
		}
		cout << ans << endl;
	}
	return 0;
}