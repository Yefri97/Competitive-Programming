#include <bits/stdc++.h>
using namespace std;

struct word{
  char a, b, c, d;

  word(char _a, char _b, char _c, char _d) : a(_a), b(_b), c(_c), d(_d) {}

  bool operator == (word other) const {
    return (a == other.d && b == other.c && c == other.b && d == other.a);
  }
};

int main() {
  int n;
  while (cin >> n && n) {
    stack<word> sw;
    int ans = 0;
    while (n--) {
      if (sw.empty()) sw.push(word('F', 'A', 'C', 'E'));
      char a, b, c, d; cin >> a >> b >> c >> d;
      word w = word(a, b, c, d);
      if (w == sw.top()) { 
        sw.pop();
        ans++;
      } else {
        sw.push(w);
      }
    }
    cout << ans << endl;
  }
  return 0;
}