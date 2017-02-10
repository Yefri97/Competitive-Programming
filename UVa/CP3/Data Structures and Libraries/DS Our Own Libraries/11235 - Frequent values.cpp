// Tree-related Data Structures
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private: 
  vi st, A;
  int n;
  int left (int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    if (L == R) {
      st[p] = L;
    } else {
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] >= A[p2]) ? p1 : p2;
    }
  }

  int rmq(int p, int L, int R, int i, int j) {
    if (i >  R || j <  L) return -1;
    if (L >= i && R <= j) return st[p];

    int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] >= A[p2]) ? p1 : p2;
  }

  int update_point(int p, int L, int R, int idx, int new_value) {
    int i = idx, j = idx;

    if (i > R || j < L)
      return st[p];
    
    if (L == i && R == j) {
      A[i] = new_value;
      return st[p] = L;
    }

    int p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    return st[p] = (A[p1] >= A[p2]) ? p1 : p2;
  }

public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

  int update_point(int idx, int new_value) { return update_point(1, 0, n - 1, idx, new_value); }
};

const int kMaxN = 100000;
int input[kMaxN + 10];

int main() {
  int n;
  while (cin >> n && n) {
    int q; cin >> q;
    for (int i = 0; i < n; i++)
      cin >> input[i];
    
    vector<int> freq(2 * (kMaxN + 1));
    for (int i = 0; i < n; i++)
      freq[input[i] + kMaxN]++;
    
    vector<int> acum(2 * (kMaxN + 1));
    acum[0] = freq[0];
    for (int i = 1; i < 2 * (kMaxN + 1); i++)
      acum[i] = freq[i] + acum[i - 1];
    
    SegmentTree freqSt(freq);
    while (q--) {
      int i, j; cin >> i >> j; i--; j--;
      int x = input[i], y = input[j]; x += kMaxN; y += kMaxN;
      int newX = acum[x] - i, newY = freq[y] - (acum[y] - j) + 1;
      if (x == y) newX = newY = j - i + 1;
      
      freqSt.update_point(x, newX);
      freqSt.update_point(y, newY);

      int idxRmq = freqSt.rmq(x, y);
      if (idxRmq == x) cout << newX << endl;
      else if (idxRmq == y) cout << newY << endl;
      else cout << freq[idxRmq] << endl;
      
      freqSt.update_point(x, freq[x]);
      freqSt.update_point(y, freq[y]);
    }
  }
  return 0;
}