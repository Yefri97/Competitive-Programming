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

string days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
string months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
int nom[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		string m, d; cin >> m >> d;
		int id = 0;
		while (months[id] != m) id++;
		int x = 0;
		while (days[x] != d) x++;
		int ans = 0;
		fori(i, 0, nom[id]) {
			if ((x % 7) == 5 || (x % 7) == 6) ans++;
			x++;
		}
		cout << ans << endl;
	}
	return 0;
}