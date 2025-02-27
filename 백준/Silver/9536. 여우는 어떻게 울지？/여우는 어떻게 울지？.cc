#include <bits/stdc++.h>

int T;

using namespace std;
vector<string> vec;
vector<string> sound;


//공백 기준으로 문자열 자르기
//갑자기 공백 자르기가 레전드로 헷갈리네,,
vector<string> getSub(string temp){
    // int index = temp.find(" ",0);
    // string first = temp.substr(0,index);
    // int index2 = temp.find(" ", index);
    // string second = temp.substr(index+1,index2);
    // // int index3 = temp.find(" ", index2+1);
    // string third = temp.substr(index2+1,-1);
    int index = 0;
    string nows = "";
    vector<string> now;
    for(int i =0;i<temp.size();i++){
        if(temp[i] == ' '){
            now.push_back(nows);
            nows = "";
            continue;
        }
        nows += temp[i];
        // int tempIndex = temp.find(" ",index+1);
        // cout <<"temp : "<< tempIndex << "\n";
        // string nowString = temp.substr(index,tempIndex-index+1);
        // index = tempIndex;
        // cout << nowString << "\n";
    }
    now.push_back(nows);

    // for(auto it : now){
    //     cout << it << "\n";
    // }
    // cout << first << " "  << second  <<  " " << third << "\n";
    // cout << third << "\n";
    // // cout << first << "helloe\n";
    // now.push_back(first);
    // now.push_back(second);
    // now.push_back(third);
    return now;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    string temp;
    string answer;
    cin.ignore(); //개행버퍼를 넣기 위함이다.
    for(int i =0;i<T;i++){
        //첫문장에 대해서만 처리하면 됨
        getline(cin,answer);
        sound.clear();
    
        while(1){
            getline(cin,temp);
            if(temp == "what does the fox say?"){
                break;
            }
            vector<string> nows = getSub(temp);
            sound.push_back(nows[2]);
        }

        vector<string> nows = getSub(answer);
        for(int t=0;t<nows.size();t++){
            bool isOk = false;
            for(int p=0;p<sound.size();p++){
                if(nows[t] == sound[p]){
                    isOk = true;
                    break;
                }
            }
            if(!isOk){
                cout << nows[t] << " ";
            }
        }
        cout << "\n";
        
    }
    //이제 sound에 대한 처리를 해주면 된다.

    // cout << temp << "\n";
    // for(auto it :vec){
    //     cout << it << "\n";
    // }
}