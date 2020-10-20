#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const int MK = 26;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	string s; cin >> s;
	vi freq(MK);
	for (char c : s)
		freq[c - 'A']++;
	int odd = 0;
	fori(i, 0, MK)
		odd += (freq[i] % 2);
	if (odd > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	int c = -1;
	string ans;
	fori(i, 0, MK) {
		if (freq[i] % 2) {
			c = i;
			freq[i]--;
		}
		freq[i] /= 2;
		while (freq[i]--)
			ans.push_back(i + 'A');
	}
	cout << ans;
	if (c != -1) cout << (char)(c + 'A');
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}
