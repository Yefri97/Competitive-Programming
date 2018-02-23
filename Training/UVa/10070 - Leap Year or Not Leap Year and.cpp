#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

bool is_divisible(string n, int m) {
	int val = 0;
	fori(i, 0, (int)n.size())
		val = (val * 10 + (n[i] - '0')) % m;
	return val % m == 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int f = 1;
	string year;
	while (cin >> year) {
		if (!f) cout << endl; f = 0;
		bool is_leap = is_divisible(year, 4) && !is_divisible(year, 100) || is_divisible(year, 400);
		bool is_huluculu = is_divisible(year, 15);
		bool is_bulukulu = is_leap && is_divisible(year, 55);
		bool is_ordinary = !is_leap && !is_huluculu && !is_bulukulu;
		if (is_leap) cout << "This is leap year." << endl;
		if (is_huluculu) cout << "This is huluculu festival year." << endl;
		if (is_bulukulu) cout << "This is bulukulu festival year." << endl;
		if (is_ordinary) cout << "This is an ordinary year." << endl;
	}
	return 0;
}