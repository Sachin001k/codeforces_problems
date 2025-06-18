#include<iostream>

using namespace std;

int main(){
    int t; //test cases
    cin>>t;
    while(t--){
        int k,a,b,x, y;

        cin>>k>>a>>b>>x>>y;
        long long total = 0;

        while (true) {
            // Can cook both
            if (k >= a && k >= b) {
                if (x <= y && k >= a) {
                    k -= x;
                } else if (k >= b) {
                    k -= y;
                }
                total++;
            }
            // Only A is possible
            else if (k >= a) {
                k -= x;
                total++;
            }
            // Only B is possible
            else if (k >= b) {
                k -= y;
                total++;
            }
            // Cannot cook either
            else {
                break;
            }
        }

        cout << total << endl;
        

    }

    return 0;
}