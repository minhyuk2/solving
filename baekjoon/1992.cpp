#include <bits/stdc++.h>

using namespace std;


//스택을 써야하나 한 번 괄호 열면 무조건 닫혀야하니까
//char배열로 해서 집어넣어 가야겠네

char arr[65][65];

//계속 4개의 숫자가 자기 자신 기준 4개의 숫자가 자기랑 같은지를 확인해서 아니면 또 세분화하게 나누기 

void makeFour(vector<char> &vec,int X,int Y,int sizes){

    //1개짜리일때의 끝나는 조건을 명시해줘야함.
    //이게 거의 1개짜리의 결과이고,
    // for(int i = 0; i < N-1; i = i+2){
    //     for(int t =0; t< N-1; t++){
    //         //4방향검사
    //         int color = arr[i][t];
    //         int sameColor = 0;
    //         //밑에
    //         if(arr[i+1][t] != color){
    //             sameColor = 1;
    //         }
    //         //대각오른
    //         if(arr[i+1][t+1] == color){
    //             sameColor = 1;
    //         }
    //         //오른
    //         if(arr[i][t+1] == color){
    //             sameColor = 1;
    //         }
    //         if(sameColor == 1){

    //         }else{

    //             //다 같은 경우
    //             vec.push_back((char)color);
    //         }
    //     }
    // }
    //1사분면
    char color1 = arr[X][Y];
    int sameColor1 = 0;
    for(int i =0; i< sizes;i++){
        for(int t= 0 ; t< sizes ; t++){
            if(arr[X+i][Y+t] != color1){
                sameColor1 = 1;
            }
        }
    }

    //2사분면
    char color2 = arr[X][Y+sizes];
    int sameColor2= 0;
    for(int i =0; i< sizes;i++){
        for(int t= 0 ; t< sizes ; t++){
            if(arr[X+i][Y+t+sizes] != color2){
                sameColor2 = 1;
            }
        }
    }

    //3사분면
    char color3 = arr[X+sizes][Y];
    int sameColor3= 0;
    for(int i =0; i< sizes;i++){
        for(int t= 0 ; t< sizes ; t++){
            if(arr[X+i+sizes][Y+t] != color3){
                sameColor3 = 1;
            }
        }
    }

    //4사분면
    char color4 = arr[X+sizes][Y+sizes];
    int sameColor4= 0;
    for(int i =0; i< sizes;i++){
        for(int t= 0 ; t< sizes ; t++){
            if(arr[X+i+sizes][Y+t+sizes] != color4){
                sameColor4 = 1;
            }
        }
    }
    //모두가 같은 경우
    if((sameColor1 == 0) && (sameColor2 == 0 )&& (sameColor3 == 0) && (sameColor4 == 0)){
        if(color1 == color2 && color2 == color3 && color3 == color4){
            vec.push_back(color1);
        }else{
            //모든 색은 같지 않고 각각은 다 동일한 경우
            vec.push_back('(');
            vec.push_back(color1);
            vec.push_back(color2);
            vec.push_back(color3);
            vec.push_back(color4);
            // vec.push_back((char)(color2+'0'));
            // vec.push_back((char)(color3+'0'));
            // vec.push_back((char)(color4+'0'));
            vec.push_back(')');
        }
    }else{
        //아니고 다른게 있는 경우에 해당하는 친구는 보충학습을 위해서 한 번 더 나누게끔 들어가야한다.
        vec.push_back('(');
        
        //재귀니까 끝나고 나와서 얘가 덮네ㅇㅋ
        if(sameColor1 == 0){
            vec.push_back(color1);
        }else{
            makeFour(vec,X,Y,sizes/2);
        }

        if(sameColor2 == 0){
            vec.push_back(color2);
        }else{
            makeFour(vec,X,Y+sizes,sizes/2);
        }
        if(sameColor3 == 0){
            vec.push_back(color3);
        }else{
            makeFour(vec,X+sizes,Y,sizes/2);
        }

        if(sameColor4 == 0){
            vec.push_back(color4);
        }else{
            makeFour(vec,X+sizes,Y+sizes,sizes/2);
        }
        vec.push_back(')');
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    for(int i = 0; i < N ; i++){
        for(int t = 0 ; t < N; t++){
            cin >> arr[i][t];
        }
    }
    //스택이랑 출력을 위한 벡터를 담아서 넘겨주고,
    vector<char> vec;
    makeFour(vec,0,0,N/2);

    for(auto it : vec){
        cout << it;
    }
    cout << "\n";
}