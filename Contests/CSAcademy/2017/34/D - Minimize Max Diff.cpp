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

const int INF = 2e9, MAXN = 100010;
int A[MAXN], B[MAXN];

struct minQueue {
  int minIn;
  stack<int> input, smin;

  minQueue() : minIn(INF) {}
  
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
    minIn = INF;
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
	int n, k; cin >> n >> k;
	fori(i, 0, n)
		cin >> A[i];
	fori(i, 0, n - 1)
		B[i] = A[i + 1] - A[i];
	minQueue mq;
	fori(i, 0, n - k - 1)
		mq.push(-B[i]);
	int ans = -mq.qmin();
	fori(i, n - k - 1, n - 1) {
		mq.push(-B[i]); mq.pop();
		ans = min(ans, -mq.qmin());
	}
	cout << ans << endl;
	return 0;
}