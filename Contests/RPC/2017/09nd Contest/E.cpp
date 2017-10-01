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

int nextInt() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

bool isvowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n = nextInt();
	while (n--) {
		string s, ans; getline(cin, s);
		for (char c : s) {
			ans.push_back(c);
			if (isvowel(c)) {
				ans.push_back('p');
				ans.push_back(c);
			}
		}
		cout << ans << endl;
	}
	return 0;
}