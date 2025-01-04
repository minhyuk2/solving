#include <bits/stdc++.h>

using namespace std;

//이게 안되면 벡터로
int arr[2188][2188];

int ones;
int minuss;
int zeros;

void getPaper(int N, int X, int Y){
    //첫번째 색으로 결정을 해도 되고 아니면 전체 확인을 해서 거기에 없는 경우에만 나눠서 하면 되는 것이다.
    int first_find = arr[X][Y];
    int allSame = 1;
    for(int i = 0; i< N ; i++){
        for(int t = 0 ; t < N; t++){
            if(arr[X+i][Y+t]!=first_find){
                allSame = 0;
                break;
            }
        }
    }
    if(allSame == 1){
        // switch(first_find){
        //     case 1 :
        //         ones++;
        //         break;
        //     case 0 :
        //         zeros++;
        //         break;
        //     case -1 :
        //         minuss++;
        //         break;
        // }
        if(first_find == 0){
            zeros++;
        }else if(first_find == -1){
            minuss++;
        }else{
            ones++;
        }
        return;
    }else{
        getPaper(N/3,X,Y);

        getPaper(N/3,X+N/3,Y);

        getPaper(N/3,X+2*(N/3),Y);

        getPaper(N/3,X+N/3,Y+N/3);

        getPaper(N/3,X,Y+N/3);

        getPaper(N/3,X,Y+2*(N/3));

        getPaper(N/3,X+2*(N/3),Y+2*(N/3));

        getPaper(N/3,X+N/3,Y+2*(N/3));

        getPaper(N/3,X+2*(N/3),Y+N/3);
    }


}





int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    for(int i = 0 ; i< N; i ++){
        for(int t =0 ; t < N ; t++){
            cin >> arr[i][t];
        }
    }
    getPaper(N,0,0);
    cout << minuss << "\n" << zeros << "\n" << ones << "\n";

}