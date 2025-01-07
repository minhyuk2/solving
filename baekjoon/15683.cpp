#include <bits/stdc++.h>

using namespace std;

int arr2[9][9];

// int answer = 64;
int N, M;
int counting;
int counting2;

int minAnswer = 65;
void fiveColor(int X, int Y,int** arr);
void fourColor(int X, int Y, int offf,int** arr);
void threeColor(int X, int Y, int offf,int** arr);
void twoColor(int X, int Y, int offf,int** arr);
void oneColor(int X, int Y, int offf,int** arr);


//이 문제는 말 그대로 브루트 포스로 모든 경우의 수를 다 적용해보아야하네 시간 초과 안나니까 ㅇㅋ
//어떤 것을 먼저 선택할지도 문제에 영향을 미치니까 그걸 고려해서
//이러면 돌아와서 배열에 대한 복구를 어떻게 치지?

void copyArr(int** arr, int** result){
    for(int i = 0 ; i< N; i ++){
        for(int t= 0 ; t < M; t++){
            result[i][t] = arr[i][t];
        }
    }
}

void colorArr(int X, int Y, int** arr){
    int firtsY = Y;
    for(int i = X; i < N ; i ++){
        for(int t = Y ; t < M; t++){
            if(arr[i][t] == 1){
                for(int p = 0 ; p< 4; p++){
                    // cout << "여기까지\n" ;
                    // cout << arr[i][t] << "\n";
                    int** newArray = new int*[9];
                    for (int k = 0; k < 9; k++) {
                        newArray[k] = new int[9];
                    }
                    copyArr(arr,newArray);
                    oneColor(i,t,p,newArray);
                    // 동적 메모리 해제
                    for (int k = 0; k < 9; k++) {
                        delete[] newArray[k];
                    }
                    delete[] newArray;
                }
                // int** newArray = new int*[9];
                // for (int k = 0; k < 9; k++) {
                //     newArray[k] = new int[9];
                // }
                // copyArr(arr,newArray);
                // oneColor(i,t,0,newArray);
                // // 동적 메모리 해제
                // for (int k = 0; k < 9; k++) {
                //     delete[] newArray[k];
                // }
                // delete[] newArray;

                // int newArray1[9][9];
                // copyArr(arr,newArray1);
                // oneColor(i,t,1,newArray1);

                // int newArray2[9][9];
                // copyArr(arr,newArray2);
                // oneColor(i,t,2,newArray2);
                
                // int newArray3[9][9];
                // copyArr(arr,newArray3);
                // oneColor(i,t,3,newArray3);
                
            }else if(arr[i][t] == 2 ){

         
                for(int p = 0 ; p< 2; p++){
                    int** newArray = new int*[9];
                    for (int k = 0; k < 9; k++) {
                        newArray[k] = new int[9];
                    }
                    copyArr(arr,newArray);
                    twoColor(i,t,p,newArray);
                    // 동적 메모리 해제
                    for (int k = 0; k < 9; k++) {
                        delete[] newArray[k];
                    }
                    delete[] newArray;
                }

            }else if(arr[i][t] ==3 ){
                for(int p = 0 ; p< 4; p++){
                    int** newArray = new int*[9];
                    for (int k = 0; k < 9; k++) {
                        newArray[k] = new int[9];
                    }
                    copyArr(arr,newArray);
                    threeColor(i,t,p,newArray);
                    // 동적 메모리 해제
                    for (int k = 0; k < 9; k++) {
                        delete[] newArray[k];
                    }
                    delete[] newArray;
                }
            }else if(arr[i][t] == 4 ){
                for(int p = 0 ; p < 4; p++){
                    int** newArray = new int*[9];
                    for (int k = 0; k < 9; k++) {
                        newArray[k] = new int[9];
                    }
                    copyArr(arr,newArray);
                    fourColor(i,t,p,newArray);
                    // 동적 메모리 해제
                    for (int k = 0; k < 9; k++) {
                        delete[] newArray[k];
                    }
                    delete[] newArray;
                }
                //그냥 이렇게 계속 새로운 메모리를 넣어도 되나 후
            }else if(arr[i][t] ==5 ){
                fiveColor(i,t,arr);
            }
        }
        Y = 0;
    }
    int answer =0 ;
    // cout << "마지막 줄 실행 \n";
    for(int i = 0 ; i < N;  i++){
        // cout << "\n";
        for(int t=0 ; t < M; t++){
            // cout << arr[i][t] << " ";
            if(arr[i][t] == 0){
                answer++;
            }
        }
    }
    // cout <<"끝"<< "\n";

    if(answer < minAnswer){
        minAnswer = answer;
    } 
}   

//보이는 곳은 7로 표시 얘는 고정
void fiveColor(int X, int Y,int** arr){

        //가로 채우기
        for(int i = Y ; i <M; i++){
            if(arr[X][i] == 6){
                break;
            }else if(arr[X][i] == 0){
                arr[X][i] = 7;
            }
        }
        for(int i = Y ; i >=0; i--){
            if(arr[X][i] == 6){
                break;
            }else if(arr[X][i] == 0){
                arr[X][i] = 7;
            }
        }
        //세로 채우기
        for(int i = X ; i <N; i++){
            if(arr[i][Y] == 6){
                break;
            }else if(arr[i][Y] == 0){
                arr[i][Y] = 7;
            }
        }
        for(int i = X ; i >=0; i--){
            if(arr[i][Y] == 6){
                break;
            }else if(arr[i][Y] == 0){
                arr[i][Y] = 7;
            }
        }
    
}
//4번은 그 방향이 칠할 수 있는 것의 제일 작게 칠할 수 있는 것의 방향을 세야한다.
void fourColor(int X, int Y, int offf,int** arr){
        // cout << "\n들어온 나의 좌표" << X << Y << "\n";
        if(offf != 0){
            for(int i = Y; i <M; i++){
                if(arr[X][i] == 6){
                    break;
                }else if(arr[X][i] == 0){
                    arr[X][i] = 7;
                }
            }
        }
        //가로 채우기(왼쪽)
        if(offf != 1){
            for(int i = Y ; i >=0; i--){
                if(arr[X][i] == 6){
                    break;
                }else if(arr[X][i] == 0){
                    arr[X][i] = 7;
                }
            }
        }
        //세로 채우기(아래)
        if(offf != 2){
            for(int i = X ; i <N; i++){
                if(arr[i][Y] == 6){
                    break;
                }else if(arr[i][Y] == 0){
                    arr[i][Y] = 7;
                }
            }
        }
        //세로 채우기(위)
        if(offf != 3){
            for(int i = X ; i >=0; i--){
                if(arr[i][Y] == 6){
                    break;
                }else if(arr[i][Y] == 0){
                    arr[i][Y] = 7;
                }
            }
        }
    // cout << "여기가 4번쨰 시행 \n";
    // for(int i = 0 ; i < N;  i++){
    //     cout << "\n";
    //     for(int t=0 ; t < M; t++){
    //         cout << arr[i][t] << " ";
    //     }
    // }
    // cout << "\n"<< counting2 << "끝" << "\n";
    // counting2++;
    
    if(Y+1 == M){
        colorArr(X+1,0,arr);
    }else{
        colorArr(X,Y+1,arr);
    }
    // colorArr(X,Y+1,arr);

}


//4번은 그 방향이 칠할 수 있는 것의 제일 작게 칠할 수 있는 것의 방향을 세야한다.
void threeColor(int X,int Y,int offf,int** arr){
        //얘네를 다 카운트해서 제일 적은 걸로 결정?
        //얘네가 갔던 길만 지워야지 잘못된 길도 지울 수가 있으니까 그걸 저장해둬야하나?
        //뭐 해봤자 연산이 적기는 해
        //다 비교해서 이렇게 채워넣어준다.
        //나머지 애들도 다 비슷한 과정별로 해주면 될 것 같은데 최대한의 크기가 되게끔 최소인 애를 빼고
    //     int counting[4] = {0,};
    
    //     //얘네는 크기 판단용
    //     for(int i = it.second ; i <M; i++){
    //         if(arr[it.first][i] == 6){
    //             break;
    //         }else if(arr[it.first][i] == 0){
    //             counting[0]++;
    //         }
    //     }
    //     //가로 채우기(왼쪽)
    //     for(int i = it.second ; i >=0; i--){
    //         if(arr[it.first][i] == 6){
    //             break;
    //         }else if(arr[it.first][i] == 0){
    //            counting[1]++;
    //         }
    //     }
    //     //세로 채우기(아래)
    //     for(int i = it.first ; i <N; i++){
    //         if(arr[i][it.second] == 6){
    //             break;
    //         }else if(arr[i][it.second] == 0){
    //             // arr[i][it.second] = 7;
    //             counting[2]++;
    //         }
    //     }
    //     //세로 채우기(위)
    //     for(int i = it.first ; i >=0; i--){
    //         if(arr[i][it.second] == 6){
    //             break;
    //         }else if(arr[i][it.second] == 0){
    //             // arr[i][it.second] = 7;
    //             counting[3]++;
    //         }
    //     }

        int open0 = 0;
        int open1 = 0;
        int open2 = 0;
        int open3 = 0;
    //     //여기 알고리즘을 짜는게 좀 헷갈리네 어떻게 묶어야할까
    //     int counting2[4] = {0,};
    //     counting2[0] = counting[0]+ counting[3]; //오른쪽 + 위
    //     counting2[1] = counting[3]+ counting[1]; //왼쪽  + 위
    //     counting2[2] = counting[1] + counting[2]; // 왼쪽 + 아래
    //     counting2[3] = counting[2] + counting[0] ;// 오른쪽 + 아래

    //    int minVal = *max_element(begin(counting2),end(counting2));
        
        if(offf == 0){
            open0 = 1;
            open3 = 1;
        }else if(offf == 1){
            open3 = 1;
            open1 = 1;
        }else if(offf == 2){
            open1 = 1;
            open2 = 1;
        }else if(offf == 3){
            open2 = 1;
            open0 = 1;
        }
        //가로 채우기(오른쪽)
        if(open0 == 1){
            for(int i = Y; i <M; i++){
                if(arr[X][i] == 6){
                    break;
                }else if(arr[X][i] == 0){
                    arr[X][i] = 7;
                }
            }
        }
        //가로 채우기(왼쪽)
        if(open1 == 1){
            for(int i = Y ; i >=0; i--){
                if(arr[X][i] == 6){
                    break;
                }else if(arr[X][i] == 0){
                    arr[X][i] = 7;
                }
            }
        }
        //세로 채우기(아래)
        if(open2 == 1){
            for(int i = X ; i <N; i++){
                if(arr[i][Y] == 6){
                    break;
                }else if(arr[i][Y] == 0){
                    arr[i][Y] = 7;
                }
            }
        }
        //세로 채우기(위)
        if(open3 == 1){
            for(int i = X; i >=0; i--){
                if(arr[i][Y] == 6){
                    break;
                }else if(arr[i][Y] == 0){
                    arr[i][Y] = 7;
                }
            }
        }

        // cout << "세번째 시행\n";
        if(Y+1 == M){
            colorArr(X+1,0,arr);
        }else{
            colorArr(X,Y+1,arr);
        }
        // colorArr(X,Y+1,arr);
}


//4번은 그 방향이 칠할 수 있는 것의 제일 작게 칠할 수 있는 것의 방향을 세야한다.
void twoColor(int X, int Y, int offf, int** arr){
        

        int open0 = 0;
        int open1 = 0;
        int open2 = 0;
        int open3 = 0;
        
        if(offf == 0){
            open0 = 1;
            open1 = 1;
        }else if(offf == 1){
            open2 = 1;
            open3 = 1;
        }
        //가로 채우기(오른쪽)
        if(open0 == 1){
            for(int i = Y ; i <M; i++){
                if(arr[X][i] == 6){
                    break;
                }else if(arr[X][i] == 0){
                    arr[X][i] = 7;
                }
            }
        }
        //가로 채우기(왼쪽)
        if(open1 == 1){
            for(int i = Y ; i >=0; i--){
                if(arr[X][i] == 6){
                    break;
                }else if(arr[X][i] == 0){
                    arr[X][i] = 7;
                }
            }
        }
        //세로 채우기(아래)
        if(open2 == 1){
            for(int i = X; i <N; i++){
                if(arr[i][Y] == 6){
                    break;
                }else if(arr[i][Y] == 0){
                    arr[i][Y] = 7;
                }
            }
        }
        //세로 채우기(위)
        if(open3 == 1){
            for(int i = X; i >=0; i--){
                if(arr[i][Y] == 6){
                    break;
                }else if(arr[i][Y] == 0){
                    arr[i][Y] = 7;
                }
            }
        }
    // cout << "여기가 2번쨰 시행 \n";
    // counting ++;
    // cout << "count: " << counting << "\n";
    // for(int i = 0 ; i < N;  i++){
    //     cout << "\n";
    //     for(int t=0 ; t < M; t++){
    //         cout << arr[i][t] << " ";
    //     }
    // }
    // cout << "끝" << "\n";
        // if(Y+1 == M){
        //     colorArr(X+1,0,arr);
        // }else{
        //     colorArr(X,Y+1,arr);
        // }
    if(Y+1 == M){
        colorArr(X+1,0,arr);
    }else{
        colorArr(X,Y+1,arr);
    }
}



//4번은 그 방향이 칠할 수 있는 것의 제일 작게 칠할 수 있는 것의 방향을 세야한다.
void oneColor(int X, int Y, int offf, int** arr){

        //얘네를 다 카운트해서 제일 적은 걸로 결정?
        //얘네가 갔던 길만 지워야지 잘못된 길도 지울 수가 있으니까 그걸 저장해둬야하나?
        //뭐 해봤자 연산이 적기는 해
        //다 비교해서 이렇게 채워넣어준다.
    
        if(offf == 0){
            for(int i = Y ; i <M; i++){
                if(arr[X][i] == 6){
                    break;
                }else if(arr[X][i] == 0){
                    arr[X][i] = 7;
                }
            }
        }
        //가로 채우기(왼쪽)
        if(offf== 1){
            for(int i = Y ; i >=0; i--){
                if(arr[X][i] == 6){
                    break;
                }else if(arr[X][i] == 0){
                    arr[X][i] = 7;
                }
            }
        }
        //세로 채우기(아래)
        if(offf == 2){
            for(int i = X; i <N; i++){
                if(arr[i][Y] == 6){
                    break;
                }else if(arr[i][Y] == 0){
                    arr[i][Y] = 7;
                }
            }
        }
        //세로 채우기(위)
        if(offf == 3){
            for(int i = X; i >=0; i--){
                if(arr[i][Y] == 6){
                    break;
                }else if(arr[i][Y] == 0){
                    arr[i][Y] = 7;
                }
            }
        }
        if(Y+1 == M){
            colorArr(X+1,0,arr);
        }else{
            colorArr(X,Y+1,arr);
        }
}



//벡터도 기본은 Pass by value이기 때문에 pass by reference로 넘기기 위해 &를 써야함

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //모든 경우의 수를 다 수행해서 작은 걸 구해도 괜찮을 것 같은데

    int** newArray = new int*[9];
    for (int k = 0; k < 9; k++) {
        newArray[k] = new int[9];
    }

    cin >> N >> M;
    for(int i = 0 ; i < N;  i++){
        for(int t=0; t < M; t++){
            cin >> newArray[i][t];
        }
    }

    // int** pointing = arr2;
    colorArr(0,0,newArray);

    cout << minAnswer << "\n";

    //볼 수 있는 방향을 다 #으로 칠해두는거지
    //그냥 구현문제네
    //그러면 만약에 제일 센 5를 제외하고 나머지는 방향을 하나씩 돌려가면서 제일 작은 것을 찾아나가는건데
    //너무 경우의 수가 무수히 많아진다.
    //그렇게 되면..아 벽이 없는 쪽이 좋고 겹치지 않는게 좋음 그러면 그리디로 하는게 좋은데
    //가장 많이 채울 수 있게 하는 방법이 뭐가 있을까
    //가장 많이 채우는게 궁극적인 목표인데 그리디는 아니야 그러면 답은 항상 마지막에 0의 개수를 세면 됨
    //하나씩 방향을 돌려가면서 찾아나가면 되겠다.ㅇㅋ

    //그리디로 푸니까 이런 문제가 발생하게 되는 것이다 그렇네.

}