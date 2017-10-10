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

char val[] = {'V', 'U', 'C', 'D'};

int cowToInt(string s) {
	int n = s.size(), ans = 0;
	fori(i, 0, n) {
		int id = find(val, val + 4, s[i]) - val;
		ans = id + 4 * ans;
	}
	return ans;
}

string intToCow(int x) {
	string ans;
	fori(i, 0, 8) {
		ans.push_back(val[x % 4]);
		x /= 4;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	cout << "COWCULATIONS OUTPUT" << endl;
	while (t--) {
		string num1, num2; cin >> num1 >> num2;
		int a = cowToInt(num1), b = cowToInt(num2);
		fori(i, 0, 3) {
			char c; cin >> c;
			if (c == 'A')
				b = a + b;
			else if (c == 'R')
				b /= 4;
			else if (c == 'L')
				b *= 4;
		}
		string y = intToCow(b);
		string out; cin >> out;
		cout << ((out == y) ? "YES" : "NO") << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}