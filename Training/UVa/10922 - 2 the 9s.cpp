#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int f(string s, int d) {
  int acc = 0;
  for (char c : s)
  acc += c - '0';
  if (acc % 9) return 0;
  if (acc == 9) return d + 1;
  return f(to_string(acc), d + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
  while (cin >> s && s != "0") {
    int ans = f(s, 0);
    if (ans == 0) {
      cout << s << " is not a multiple of 9." << endl;
    } else {
      cout << s << " is a multiple of 9 and has 9-degree " << ans << "." << endl;
    }
  }
	return 0;
}
