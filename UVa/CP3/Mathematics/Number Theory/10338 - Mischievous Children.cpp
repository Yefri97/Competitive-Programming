#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll fact[30]; fact[0] = fact[1] = 1;
  for (ll i = 2; i <= 20; i++) 
    fact[i] = i * fact[i - 1];
  int t, cs = 0; cin >> t;
  while (t--) {
    cout << "Data set " << ++cs << ": ";
    int freq[30]; memset(freq, 0, sizeof freq);
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++)
      freq[s[i] - 'A']++;
    ll ans = fact[s.size()];
    for (int i = 0; i < 26; i++)
      ans /= fact[freq[i]];
    cout << ans << endl;
  }
  return 0;
}