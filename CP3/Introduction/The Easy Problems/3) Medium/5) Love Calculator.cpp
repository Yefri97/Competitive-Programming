#include<bits/stdc++.h>
using namespace std;

int min_one_digit(int n) {
    if (n/10 == 0) return n;
    int cont = 0;
    for (int num = n; num; num /= 10) {
        cont += num%10;
    }
    return min_one_digit(cont);
}

int convert_number(string s) {
    int cont = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (64 <= int(c) && int(c) <= 91 || 96 <= int(c) && int(c) <= 123)
            cont += c & 31;
    }
    return min_one_digit(cont);
}

int main() {
    string A, B;
    while(getline(cin, A) && getline(cin, B)) {
        int first = convert_number(A), second = convert_number(B);
        double x = min(first, second), y = max(first, second);
        cout<<fixed<<setprecision(2)<<(x/y)*100<<" %"<<endl;
    }
    return 0;
}
