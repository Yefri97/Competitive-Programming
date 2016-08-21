#include<bits/stdc++.h>
using namespace std;

int main () {
    double height, up, down, fatigue;
    while(cin>>height>>up>>down>>fatigue && height!=0) {
        string target; int day;
        double initDay, advanced, position, endDay = 0, factor = (up*fatigue)/100;
        for(int i = 0; true; i++) {
            initDay = endDay;
            advanced = (up > i*factor)? up - i*factor : 0;
            position = initDay + advanced;
            if(position > height) {
                target = "success";
                day = i+1;
                break;
            }
            endDay = position - down;
            if(endDay < 0) {
                target = "failure";
                day = i+1;
                break;
            }
        }
        cout<<target<<" on day "<<day<<endl;;
    }
    return 0;
}
