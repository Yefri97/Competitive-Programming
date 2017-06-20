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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs = 0;
	string word;
	while (cin >> word && word != "#") {
		cout << "Case " << ++cs << ": ";
		if (word == "HELLO") cout << "ENGLISH" << endl;
		else if (word == "HOLA") cout << "SPANISH" << endl;
		else if (word == "HALLO") cout << "GERMAN" << endl;
		else if (word == "BONJOUR") cout << "FRENCH" << endl;
		else if (word == "CIAO") cout << "ITALIAN" << endl;
		else if (word == "ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
		else cout << "UNKNOWN" << endl;
	}
	return 0;
}