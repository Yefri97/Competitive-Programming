// Number Systems or Sequences
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

bool check(int n) {
	while (n % 2 == 0) n /= 2;
	while (n % 3 == 0) n /= 3;
	while (n % 5 == 0) n /= 5;
	return n == 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	/*
	int cont = 1, n = 2;
	while (true) {
		if (check(n)) cont++;
		if (cont == 1500) break;
		n++;
	}
	*/
	int number = 859963392;
	cout << "The 1500'th ugly number is " << number << "." << endl;
	return 0;
}