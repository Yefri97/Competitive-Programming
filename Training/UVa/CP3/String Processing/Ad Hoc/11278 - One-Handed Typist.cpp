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

char kb1[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./ ~!@#$\%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char kb2[] = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg\' ~!@#QJLMFP?{}$\%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	while (getline(cin, line)) {
		string ans;
		fori(i, 0, (int)line.size()) {
			char c = line[i];
			int idx = find(kb1, kb1 + 95, c) - kb1;
			ans.push_back(kb2[idx]);
		}
		cout << ans << endl;
	}
	return 0;
}