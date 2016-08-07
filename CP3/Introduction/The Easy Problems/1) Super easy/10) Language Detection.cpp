#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int n=1;
    string s, Target;
    while(cin>>s && s!="#"){
        if(s=="HELLO"){
            Target="ENGLISH";
        }else if(s=="HOLA"){
            Target="SPANISH";
        }else if(s=="HALLO"){
            Target="GERMAN";
        }else if(s=="BONJOUR"){
            Target="FRENCH";
        }else if(s=="CIAO"){
            Target="ITALIAN";
        }else if(s=="ZDRAVSTVUJTE"){
            Target="RUSSIAN";
        }else{
            Target="UNKNOWN";
        }
        cout<<"Case "<<n<<": "<<Target<<endl;
        n++;
    }
    return 0;
}
