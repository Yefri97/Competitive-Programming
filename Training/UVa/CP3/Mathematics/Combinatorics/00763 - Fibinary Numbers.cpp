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

string sum(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vi fbin(102);
	fori(i, 0, (int)a.size())
		fbin[i] += a[i] - '0';
	fori(i, 0, (int)b.size())
		fbin[i] += b[i] - '0';
	while (true) {
		int it = 0;
		while (it < 101) {
			if (fbin[it] && fbin[it + 1]) {
				fbin[it]--;
				fbin[it + 1]--;
				fbin[it + 2]++;
				break;
			}
			if (fbin[it] > 1) {
				fbin[it] -= 2;
				if (it == 0) {
					fbin[it + 1]++;
				} else if (it == 1) {
					fbin[it + 1]++;
					fbin[it - 1]++;
				} else {
					fbin[it + 1]++;
					fbin[it - 2]++;
				}
				break;
			}
			it++;
		}
		if (it == 101) break;
	}
	int n = 101;
	while (n > 0 && fbin[n] == 0) n--;
	string ans;
	for (int i = 0; i <= n; i++)
		ans.push_back(fbin[i] + '0');
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int f = 1;
	string a, b;
	while (cin >> a >> b) {
		if (!f) cout << endl; f = 0;
		string c = sum(a, b);
		cout << c << endl;
	}
	return 0;
}