#include <bits/stdc++.h>

using namespace std;

int arr[130][130];

int blue;
int white;

//한 번에 확인하고 아닌 경우에만 분할하는 것도 하나의 방법이다.

void getColor(int N,int X, int Y){
    //이 함수를 통해서 잘라서 나가는 것이다.
    //재귀적 사고를 가져야 한다.
    //아니면 파랑인지 하양인지 체크하는 형식으로 해야하나?
    if(N == 1 && (arr[X-1][Y-1]==1)){
        blue ++;   
        return;
    }else if(N==1){
        white++;
        return;
    }
    //1,2,3,4분면 다 색을 확인 해야 함.
    //그 안의 색이 다 같으면 확인 안해도 됨.
    //근데 이렇게 하면 결국에 N^2이기 때문에 전수조사하는 것과 같은 결과가 나오게 된다.

    int color1W =0;
    int color1B =0;
    int color2W =0;
    int color2B =0;
    int color3W =0;
    int color3B =0;
    int color4W =0;
    int color4B =0;



    for(int i = 0 ;i < N/2; i++){
        for(int t =0 ; t< N/2 ; t++){
            if(arr[X-1+i][Y-1+t] == 0){
                color1W ++;
            }else{
                color1B++;
            }
        }
    }
    // cout << color1B << "\n" << color1W << "\n";
    if(color1B == 0){
        white += 1;
    }else if(color1W==0){
        blue += 1;
    }else{
        getColor(N/2,X,Y);
    }

    for(int i = 0 ;i < N/2; i++){
        for(int t =0 ; t< N/2 ; t++){
            if(arr[X+N/2-1+i][Y-1+t] == 0){
                color2W ++;
            }else{
                color2B++;
            }
        }
    }
    if(color2B == 0){
        white += 1;
    }else if(color2W == 0 ){
        blue += 1;
    }else{
        getColor(N/2,X+N/2,Y);
    }


    for(int i = 0 ;i < N/2; i++){
        for(int t =0 ; t< N/2 ; t++){
            if(arr[X-1+i][Y+N/2-1+t] == 0){
                color3W ++;
            }else{
                color3B++;
            }
        }
    }
    if(color3B == 0){
        white += 1;
    }else if(color3W == 0){
        blue += 1;
    }else{
        getColor(N/2,X,Y+N/2);
    }

    for(int i = 0 ;i < N/2; i++){
        for(int t =0 ; t< N/2 ; t++){
            if(arr[X+N/2-1+i][Y+N/2-1+t] == 0){
                color4W ++;
            }else{
                color4B++;
            }
        }
    }
    if(color4B == 0){
        white += 1;
    }else if(color4W == 0){
        blue += 1;
    }else{
        getColor(N/2,X+N/2,Y+N/2);
    }
}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    //한 변의 길이
    int totalBlue = 0;
    int totalWhite = 0;
    for(int i = 0 ; i < N ; i++){
        for(int p=0; p < N; p++){
            cin >> arr[i][p];
            if(arr[i][p] == 0){
                totalWhite ++;
            }else{
                totalBlue++;
            }
        }
    }
    if(totalBlue == 0){
        white += 1;
    }else if(totalWhite==0){
        blue += 1;
    }else{
        getColor(N,1,1);
    }
    
    cout << white << "\n" << blue << "\n";


}