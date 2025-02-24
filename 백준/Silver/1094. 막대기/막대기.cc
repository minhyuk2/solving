#include <bits/stdc++.h>

using namespace std;


int X;
// stack<int> sta;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X;
    
    // sta.push(64);
    int temp = 64;
    int counts =1;
    int small = 64;
    //가장 짧은 것을 자른다.
    if(X == 64){
        cout << 1 <<"\n";
        return 0;
    }

    while(1){
        small = small/2;
        counts++;
        if(temp - small >= X){
            temp -= small;
            //반 쪼개니까 2개가 늘어나는데 이 경우에는 하나를 버리는 것이고
            counts--;
        }else{
            // counts ++;
        }
        // cout << temp << "\n";
        // sta.pop();
        // if(stone + temp >= X){
        //     sta.push(stone);
        //     temp += stone;
        // }else{
        //     sta.push(stone);
        //     // sta.push(stone);
        //     temp += stone*2;
        // }
        if(temp == X){
            break;
        }
    }  
    cout << counts << "\n";

}  