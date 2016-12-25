#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int L;
	while (cin>>L && L) {
		int min_distance = 2000001, drogstore = -2000001, restaurant = -2000001;
		for (int i = 0; i < L; i++) {
			char c; cin>>c;
			if (c == 'Z') {
				min_distance = 0;
			} else {
				if (c == 'D') {
					drogstore = i;
					min_distance = min(min_distance, drogstore - restaurant);
				} else if (c == 'R'){
					restaurant = i;
					min_distance = min(min_distance, restaurant - drogstore);
				}
			}
		}
		cout<<min_distance<<endl;
	}
	return 0;
}