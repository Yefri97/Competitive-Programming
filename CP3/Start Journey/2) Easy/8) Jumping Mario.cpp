#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int w, a=0, b=0;
        cin>>w;
        int prev;
        cin>>prev;
        w--;
        while(w--){
            int num;
            cin>>num;
            if(prev<num){
                a++;
            }else if(prev>num){
                b++;
            }
            prev=num;
        }
        cout<<"Case "<<i+1<<": "<<a<<" "<<b<<endl;
    }
    return 0;
}
