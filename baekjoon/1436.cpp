#include <bits/stdc++.h>

using namespace std;

int main(void){


    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int number;
    cin >> number;
    int counter = 0;
    for(int i = 0; i < 100000000; i ++){
        if(to_string(i).find("666") != string::npos){
            counter ++;
            if(counter == number){
                cout <<  i << "\n";
                return 0;
            }
        }
    }

}