#include <bits/stdc++.h>

using namespace std;

int K,N;
char arr[6562][6562];

void makeStar(int X, int Y,int sizes){
    //9개의 영역으로 나누고 해야함
    //사이즈가 1일 때 출력
    if(sizes == 3){
        // cout << "here\n";
        // cout << X << Y << "\n";
        for(int i = 0; i < sizes ; i++){
            for(int t = 0; t < sizes; t++){
                if(i== 1 && t == 1){
                    arr[i+X][t+Y] = ' ';
                    continue;
                }
                arr[i+X][t+Y] = '*';
            }
            // if(i != 2)
            //     cout << "\n";
        }
        return;
    }

    int alpha = sizes/3;
    //1
    makeStar(X,Y,alpha);
    //2
    makeStar(X,Y+alpha,alpha);
    //3
    makeStar(X,Y+2*alpha,sizes/3);
    //4
    makeStar(X+alpha,Y,sizes/3);
    //5
    for(int i =0 ; i< sizes; i++){
        for(int t =0 ; t< sizes; t++){
            arr[i+X+alpha][t+Y+alpha] = ' ';
        }
    }
    //6
    makeStar(X+alpha,Y+2*alpha,sizes/3);
    //7
    makeStar(X+2*alpha,Y,sizes/3);
    //8
    makeStar(X+2*alpha,Y+alpha,sizes/3);
    //9
    makeStar(X+2*alpha,Y+2*alpha,sizes/3);

}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    makeStar(0,0,N);

    for(int i = 0; i < N; i++){
        for(int t =0 ; t < N; t++){
            cout << arr[i][t];
        }
        cout <<"\n";
    }
}