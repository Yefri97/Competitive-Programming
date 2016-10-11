#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3, SIZE_ALPHA = 26;

string line;
int cs; 
int trie[MAX_N + 10][SIZE_ALPHA + 10];

void constructTrie(int u, int i) {
  for (int j = i; j < line.size(); j++) {
    int c = line[j] - 'a';
    if (trie[u][c] == -1) {
      int v = ++cs;
      trie[u][c] = v;
      constructTrie(v, j + 1);
    }
  }
}

void print(int i, string s) {
  if (s.size()) cout << s << endl;
  for (int j = 0; j < SIZE_ALPHA; j++) {
    if (trie[i][j] != -1) {
      char c = j + 'a';
      print(trie[i][j], s + c);
    }
  }
}

void showTrie() {
  cout << " "; for (int i = 0; i < 26; i++) cout << char(i + 'a') << "  "; cout << endl;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 26; j++)
      cout << setw(2) << trie[i][j] << " ";
    cout << endl;
  }
}

int main() {
  while (cin >> line) {
    cs = 0;
    memset(trie, -1, sizeof trie);
    constructTrie(0, 0);
    //showTrie();
    print(0, "");
    cout << endl;
  }
  return 0;
}