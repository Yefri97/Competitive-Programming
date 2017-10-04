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

const int oo = 1e9, mxn = 200010;
int A[mxn];

struct minQueue {
  int minIn;
  stack<int> input, smin;

  minQueue() : minIn(oo) {}
  
  void push(int x) {
    minIn = min(minIn, x);
    input.push(x);
  }

  void update() {
    while (!input.empty()) {
      int x = input.top(); input.pop();
      if (smin.empty() or x < smin.top())
        smin.push(x);
      else
        smin.push(smin.top());
    }
    minIn = oo;
  }

  void pop() {
    if (smin.empty())
      update();
    smin.pop();
  }

  int qmin() {
    if (smin.empty())
      update();
    return min(minIn, smin.top());
  }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		fori(i, 0, n)
			cin >> A[i];
		minQueue min_val, max_val;
		ll acc = 0;
		fori(i, 0, m) {
			min_val.push(A[i]);
			max_val.push(-A[i]);
			acc += A[i];
		}
		ll ans = acc - (min_val.qmin()) - (-max_val.qmin());
		fori(i, m, n) {
			acc += A[i];
			acc -= A[i - m];
			min_val.push(A[i]);
			min_val.pop();
			max_val.push(-A[i]);
			max_val.pop();
			ans += acc - (min_val.qmin()) - (-max_val.qmin());
		}
		cout << ans << endl;
	}
	return 0;
}