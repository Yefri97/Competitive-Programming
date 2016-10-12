#include <bits/stdc++.h>
using namespace std;

struct hola{
  char id, ho;
};

hola h[5][5];

int main() {
  hola ho = {'3'};
  h[0][0] = ho;
  cout << h[0][0].id << endl;
  return 0;
}