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
  vector<int> cubes(201);
  for (int i = 1; i <= 200; i++) cubes[i] = i * i * i;
  for (int a = 2; a <= 200; a++) {
    for (int b = 2; b * b * b <= a * a * a; b++) {
      for (int c = 2; b * b * b + c * c * c <= a * a * a; c++) {
        int val = a * a * a - b * b * b - c * c * c;
        int d = lower_bound(cubes.begin(), cubes.end(), val) - cubes.begin();
        if (cubes[d] == val && b <= c && c <= d)
          cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
      }
    }
  }
	return 0;
}
