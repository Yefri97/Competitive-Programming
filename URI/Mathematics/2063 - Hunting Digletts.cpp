#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mcm(ll a, ll b) {
  return (a * b) / __gcd(a, b);
}

const int MAX_N = 100;

int main() {
  int conn[MAX_N + 10], cicle[MAX_N + 10];
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; x--;
    conn[i] = x;
  }
  for (int i = 0; i < n; i++) {
    int tortoise = i, hare = conn[tortoise], mu = 1;
    while (tortoise != hare) {
      hare = conn[hare];
      mu++;
    }
    cicle[tortoise] = mu;
  }
  ll ans = 1;
  for (int i = 0; i < n; i++)
    ans = mcm(ans, cicle[i]);
  cout << ans << endl;
  return 0;
}