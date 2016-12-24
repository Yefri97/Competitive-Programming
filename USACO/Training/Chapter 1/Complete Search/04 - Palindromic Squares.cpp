/*
ID: yefri.g1
PROG: palsquare
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

string dec_to_base(string s, int b) {
    string target = "";
    for (int i = atoi(s.c_str()); i; i /= b) {
        char c = (i % b > 9)? ((i % b) - 10) + 'A' : (i % b) + '0'; 
        target = c + target;
    }
    return target;
}

int main() {
    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");
    int base; fin >> base;
    for (int i = 1; i < 300; i++) {
        string n = dec_to_base(to_string(i), base);
        string k = dec_to_base(to_string(i * i), base);
        if (is_palindrome(k)) {
            fout << n << " " << k << endl;
        }
    }
    return 0;
}