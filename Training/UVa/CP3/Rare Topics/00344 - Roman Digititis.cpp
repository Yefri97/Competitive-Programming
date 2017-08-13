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

int freq[100][5];

string A[] = {"", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"};
string B[] = {"", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc"};

string order = "ivxlc";

int getId(char c) { fori(i, 0, 5) if (c == order[i]) return i; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(i, 0, 10) {
		fori(j, 0, 10) {
			int idx = 10 * i + j;
			string num = B[i] + A[j];
			fori(i, 0, num.size())
				freq[idx][getId(num[i])]++;
		}
	}
	fori(i, 1, 100)
		fori(j, 0, 5)
			freq[i][j] += freq[i-1][j];
	int n;
	while (cin >> n && n) {
		cout << n << ": ";
		fori(i, 0, 5) {
			cout << freq[n][i] << " " << order[i];
			if (i < 4) cout << ", ";
		}
		cout << endl;
	}
	return 0;
}