#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

vector<string> split(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int nextInt() {
  string line; getline(cin, line);
  return stoi(line);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = nextInt();
  vector<string> input;
  string line;
  while (t--) {
    getline(cin, line);

    getline(cin, line);
    input = split(line);
    vector<int> p;
    for (string s : input)
      p.push_back(stoi(s));

    getline(cin, line);
    vector<string> v = split(line);

    int n = p.size();
    vector<string> ans(n);
    fori(i, 0, n)
      ans[p[i] - 1] = v[i];

    for (string d : ans)
      cout << d << endl;

    if (t) cout << endl;

  }
  return 0;
}
