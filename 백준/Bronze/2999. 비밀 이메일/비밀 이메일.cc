#include <bits/stdc++.h>

using namespace std;
string temp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> temp;
    int R = -1;
    int C;
    for(int i =temp.size(); i>0; i--){

        if(temp.size()%i == 0 && temp.size()/i <= i){
            R = temp.size()/i;
            C = i;
        }
    }

    // cout << R << " " << C << "\n";

    //이걸 이제 해독하는거니까 반대의 과정을 거치게 만들어야 하네
    char arr[R][C];
    int indexs = 0;
    for(int i=0;i<C;i++){
        for(int t=0;t<R;t++){
            arr[t][i] = temp[indexs++];
        }
    }
    // for(int i=0;i<R;i++){
    //     for(int t=0;t<C;t++){
    //         cout << arr[i][t] << " ";
    //     }
    //     cout << "\n";
    // }

    char getLetter[R][C];
    string answer;
    for(int i=0;i<R;i++){
        for(int t=0;t<C;t++){
            answer += arr[i][t];
        }
    }
    cout << answer << "\n";

}