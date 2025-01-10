#include <bits/stdc++.h>

using namespace std;

int N;
char arr[5000][7200];


//뾰족점을 시작위치로 줘야겠네
void makeStar(int X, int Y,int sizes){
    
    if(sizes == 3){
        // cout << "her\n";
        for(int i= 0; i< 3;i++){
            for(int t= 0; t <5; t++){
                if(i == 0){
                    if(t==2){
                        arr[X][Y] = '*';
                        continue;
                    }
                }

                if(i ==1){
                    if(t==1||t==3){
                        arr[X+i][Y-2+t] = '*';
                        continue;
                    }
                }
                if(i==2){
                    arr[X+i][Y-2+t] = '*';
                }

            }
        }
        return;
    }

    //1구역
    makeStar(X,Y,sizes/2);
    //2구역
    makeStar(X+sizes/2,Y-sizes/2,sizes/2);
    //3구역
    makeStar(X+sizes/2,Y+sizes/2,sizes/2);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
        fill(arr[i],arr[i]+7200,' ');
    
    int number = N*2-1;
    makeStar(0,(number)/2,N);

    for(int i =0; i < N; i++){
        for(int t =0 ; t< number; t++){
            cout << arr[i][t];
        }
        cout << "\n";
    }
}