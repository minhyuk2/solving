#include <bits/stdc++.h>

using namespace std;

//전에 나온 것이 소문자인지 대문자인지 확인해야 한다.
int getString(string temp){
    int findJ = 0;
    //대문자는 둘다 나올 수 없다.
    if(!(temp[0] <= 122 && temp[0] >= 97)){
        // if(temp[0]!='_')
        return 0;
    }
    if(temp[temp.size()-1]=='_'){
        return 0;
    }
   //첫문자에도 _가 들어갈 수 있는지 확인하기
    int counter = 1;
    for(int i =1; i<temp.size();i++){
        //소문자인지 확인 -> 소문자가 아니면 _ 인지 확인
        //대문자도 확인해야지 java형식은
        if(temp[i] == '_'){
            if(findJ==2){
                return 0;
            }
            if(findJ==1){
                if(!(temp[i-1] >= 97 && temp[i-1] <=122)){
                    return 0;
                }
            }
            findJ = 1; // 이게 c++
        
        }

        if(temp[i] >= 97 && temp[i] <=122){
            counter++;
            //소문자인 경우
        }else if(temp[i] <=90 && temp[i] >=65){
            if(findJ == 0){
                findJ = 2;
            }else if(findJ == 1){
                return 0;
            }
        }
    }
    if(counter == temp.size()){
        return 4;
    }

    return findJ;
}

void transString(string temp,int findJ){
    int prevs = 0;
    if(findJ == 0){
        cout << "Error!\n";
    }else if(findJ == 1){
        //c++을
        for(int i=0;i<temp.size();i++){
            if(temp[i] == '_'){
                prevs = 1;
                continue;
            }
            if(prevs == 1){
                prevs = 0;
                char gogos = temp[i] - 32;
                cout << gogos;
            }else{
                cout << temp[i];
            }
        }
        cout << "\n";
    }else if(findJ==4){
        for(auto it : temp){
            cout << it;
        }
        cout << "\n";
    }
    else{
        for(int i=0;i<temp.size();i++){
            if(temp[i] <=90 && temp[i] >=65 ){
                //대문자인 경우
                prevs = 1;
                // continue;
            }
            if(prevs == 1){
                prevs = 0;
                char gogos = temp[i] +32;
                cout << "_";
                cout << gogos;
            }else{
                cout << temp[i];
            }
        }
        cout << "\n";
    }


}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string temp;
    cin >> temp;
    int number = getString(temp);
    transString(temp,number);

}