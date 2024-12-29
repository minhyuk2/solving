#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int red[1001][3];
int green[1001][3];
int blue[1001][3];

int minFunc(int house, int redNext,int first){

    int redAns = first;
    for(int i = 1 ; i < house; i++){
        if(redNext == 1){
            if(min(red[i][1],red[i][2])==red[i][1]){
                redAns += red[i][1];
                redNext = 2;
            }else{
                redAns += red[i][2];
                redNext = 3;
            }
        }else if(redNext == 2){
            if(min(red[i][0],red[i][2])==red[i][0]){
                redAns += red[i][0];
                redNext = 1;
            }else{
                redAns += red[i][2];
                redNext = 3;
            }
        }else{
            if(min(red[i][0],red[i][1])==red[i][0]){
                redAns += red[i][0];
                redNext = 1;
            }else{
                redAns += red[i][1];
                redNext = 2;
            }
        }
    }
    return redAns;

}

int minFunc2(int house){

    //첫번째 줄은 그대로 넣고 나머지부터 이제 바꿔가기 시작하면 되는거지 채워나가기
    green[0][0] = red[0][0];
    green[0][1] = red[0][1];
    green[0][2] = red[0][2];

    //이제 두번째 거 선택할 때는 나머지부터 2,3의 최대를 선택했을 때를 계속 더해서 넘어가면 되나?
    //그렇게 한 줄씩 채워나가는게 dp구나
    for(int i = 1 ; i <house ;i++){
        green[i][0] += (min(green[i-1][1],green[i-1][2]) + red[i][0]);
         green[i][1] += (min(green[i-1][2],green[i-1][0]) + red[i][1]);
          green[i][2] += (min(green[i-1][0],green[i-1][1]) + red[i][2]);
    }

    int minSmall = min(green[house-1][0],green[house-1][1]);
    int realSmall = min(green[house-1][2],minSmall);
    return realSmall;
}



int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int house;
    cin >> house;
    int first,sec,third;
    //초기값 설정
    // cin >> first >> sec >> third;
    int redAns = 0 ;
    int greenAns = 0 ;
    int blueAns = 0 ;
    redAns += first;
    greenAns += sec;
    blueAns += third;
    int redNext = 1;
    int  greenNext =2;
    int blueNext = 3;
    for(int i = 0 ; i < house; i++){
        cin >> red[i][0] >> red[i][1] >> red[i][2];
    }

    // int minRed = minFunc(house,1,red[0][0]);
    // int minGreen = minFunc(house,2,red[0][1]);
    // int minBlue = minFunc(house,3,red[0][2]);

    // int realAns = min(minRed,minGreen);
    // int oneMore  = min(minBlue,realAns);

    int twoMore = minFunc2(house);
    // cout << oneMore <<"\n";
    cout << twoMore <<"\n";
    //그리디로는 풀리지 않는구나 그러면 디피로는 어떻게 풀어야하는거지?
    //dp로 계속 채워가면서 풀어여할 듯
    //가면서 계속 작은 것을 선택해서 넣어주는 식으로 dp를 작성해야지


}

