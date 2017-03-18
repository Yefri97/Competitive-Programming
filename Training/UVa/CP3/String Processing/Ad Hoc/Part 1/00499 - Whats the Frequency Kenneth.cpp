#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    int freq[60]; memset(freq, 0, sizeof freq);
    int mmax = -1;
    for (int i = 0; i < line.size(); i++) {
      char c = line[i];
      if (!isalpha(c)) continue;
      int x;
      if (isupper(c))
        x = ++freq[c - 'A'];
      else
        x = ++freq[c - 'a' + 26];
      mmax = max(mmax, x);
    }
    for (int i = 0; i < 2 * 26; i++)
      if (freq[i] == mmax)
        cout << char((i < 26)? i + 'A' : i + 'a' - 26);
    cout << " " << mmax << endl;
  }
  return 0;
}