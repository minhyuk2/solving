#include <bits/stdc++.h>

using namespace std;

int N;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long int> vec;
    vector<long long int> vec2; //음수인 경우?

    vec.push_back(0);
    vec.push_back(1);
    vec2.push_back(0); //0
    vec2.push_back(1); //1
    vec2.push_back(-1); //-2는 -1이다.
    vec2.push_back(2);  //-3 2
                        //-4 -3
                        //-5 5
                        //-6 -8
                        //-7 13

    cin >> N;

    if(N ==0){
        cout << 0 << "\n" << 0 << "\n";
    }else if(N<0){
        int plusN = -N;
        for(int i =4;i<=plusN;i++){
            if(vec2[i-2] < 0){
                if(vec2[i-1] > 0){
                    long long int number =(labs(vec2[i-2])%1000000000 + labs(vec2[i-1])%1000000000)%1000000000;
                    vec2.push_back(-number);
                }
            }else{
                    long long int number =(labs(vec2[i-2])%1000000000+ labs(vec2[i-1])%1000000000)%1000000000;
                    vec2.push_back( number);
            }
        }
        if(vec2[plusN] < 0){
            cout << -1 << "\n" << labs(vec2[plusN]) << "\n";
        }else{
            cout << 1 << "\n" << labs(vec2[plusN]) << "\n";
        }
    }else{
        for(int i = 2; i<=N;i++){
            long long int number = (vec[i-1]%1000000000+vec[i-2]%1000000000)%1000000000;
            vec.push_back(number);
        }

        cout << 1 << "\n" << vec[N] << "\n";

    }

}   