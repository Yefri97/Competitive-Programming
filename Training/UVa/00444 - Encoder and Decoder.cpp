#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
  while (getline(cin, line)) {
    string ans;
    if (isalpha(line[0])) {
      for (char c : line)
        ans += to_string(c);
      reverse(ans.begin(), ans.end());
    } else {
      reverse(line.begin(), line.end());
      int it = 0;
      while (it < line.size()) {
        int d = 2 + (line[it] == '1');
        string num = line.substr(it, d);
        ans.push_back(stoi(num));
        it += d;
      }
    }
    cout << ans << endl;
  }
	return 0;
}
