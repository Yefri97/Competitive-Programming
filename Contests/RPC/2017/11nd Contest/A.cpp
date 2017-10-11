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

const int oo = 1e9, k = 12;

string A[] = {"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#", "LA", "LA#", "SI"};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	while (cin >> n >> s) {
		int pos = find(A, A + k, s) - A;
		cout << A[mod(pos - n, k)] << endl;
	}
	return 0;
}