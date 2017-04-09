// Binary search
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<int> books(n);
    for (int i = 0; i < n; i++)
      cin >> books[i];
    int m; cin >> m;
    sort(books.begin(), books.end());
    int a, b;
    for (int i = 0; i < n and 2 * books[i] <= m; i++) {
      if (binary_search(books.begin(), books.end(), m - books[i])) {
        a = books[i];
        b = m - books[i];
      }
    }
    cout << "Peter should buy books whose prices are " << a << " and " << b << "." << endl;
    cout << endl;
  }
  return 0;
}