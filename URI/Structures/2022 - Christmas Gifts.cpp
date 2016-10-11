#include <bits/stdc++.h>
using namespace std;

struct gift {
  string name;
  double value;
  int pref;
  gift(string _name, double _value, int _pref) : name(_name), value(_value), pref(_pref) {}
  bool operator < (gift other) const {
    if (pref != other.pref)
      return pref > other.pref;
    else if (value != other.value)
      return value < other.value;
    else
      return name < other.name;
  }
};

int main() {
  string name;
  int n;
  while (cin >> name >> n) {
    cin.ignore(100, '\n');
    vector<gift> vg;
    while (n--) {
      string line; getline(cin, line);
      double value; cin >> value;
      int pref; cin >> pref;
      cin.ignore(100, '\n');
      vg.push_back(gift(line, value, pref));
    }
    sort(vg.begin(), vg.end());
    cout << "Lista de " << name << endl;
    for (int i = 0; i < vg.size(); i++)
      cout << vg[i].name << " - R$" << fixed << setprecision(2) << vg[i].value << endl;
    cout << endl;
  }
  return 0;
}