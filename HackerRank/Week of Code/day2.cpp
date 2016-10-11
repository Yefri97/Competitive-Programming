#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100, SIZE_ALPHA = 26;
char arr[MAX_N + 10];
int freq[SIZE_ALPHA + 10];

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    memset(freq, 0, sizeof freq);
    int ok = 1, underscores = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == '_') {
        underscores++;
      } else {
        freq[arr[i] - 'A']++;
        int a = (i > 0)? (arr[i] != arr[i - 1]) : 1;
        int b = (i < n - 1)? (arr[i] != arr[i + 1]) : 1;
        if (a && b) ok = 0;
      }
    }
    if (ok == 0) {
      ok = 1;
      for (int i = 0; i < SIZE_ALPHA; i++)
        if (freq[i] == 1) ok = 0;
      if (underscores == 0) ok = 0;
    }
    cout << ((ok)? "YES" : "NO") << endl;
  }
  return 0;
}