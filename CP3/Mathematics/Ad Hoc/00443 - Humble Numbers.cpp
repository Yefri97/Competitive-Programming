#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX = 2e9;

int main() {
  vector<ll> v;
  for (ll l = 1; l <= MX; l *= 7)
    for (ll k = 1; k * l <= MX; k *= 5)
      for (ll j = 1; j * k * l <= MX; j *= 3)
        for (ll i = 1; i * j * k * l <= MX; i *= 2)
          v.push_back(i * j * k * l);
  sort(v.begin(), v.end());
  int n;
  while (cin >> n && n) {
    string suffix = "th";
    if ((n / 10) % 10 != 1) {
      if (n % 10 == 1) suffix = "st";
      if (n % 10 == 2) suffix = "nd";
      if (n % 10 == 3) suffix = "rd";
    }
    cout << "The " << n << suffix << " humble number is " << v[n - 1] << "." << endl;
  }
  return 0;
}