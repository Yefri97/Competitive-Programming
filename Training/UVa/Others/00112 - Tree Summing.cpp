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

int n;
bool ans;

int getToken() {
	int c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	if (c == '(' || c == ')') return -oo;
	int sign = 1;
	if (c == '-') {
		sign = -1;
		c = getchar();
	}
	int target = 0;
	while (isdigit(c)) {
		target = target * 10 + (c - '0');
		c = getchar();
	}
	ungetc(c, stdin);
	return sign * target;
}

bool go(int k) {
	getToken(); // Left Parent
	int x = getToken();
	if (x == -oo) return true;
	k += x;
	bool a = go(k);
	bool b = go(k);
	if (a && b && k == n) ans = true;
	getToken(); // Right Parent
	return false;
}

int main() {
	while (cin >> n) {
		ans = false;
		go(0);
		cout << (ans ? "yes" : "no") << endl;
	}
	return 0;
}