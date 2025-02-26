#include <bits/stdc++.h>

using namespace std;
int N;

vector<string> vec;
vector<long long int> answer;

bool comp(string &A, string &B){
    if(A.size() < B.size()){
        return true;
    }else if(A.size()==B.size()){
        for(int i=0;i<A.size();i++){
            if(A[i] < B[i]){
                return true;
            }else if(A[i] == B[i]){
                continue;
            }
            else{
                return false;
            }
        }
        return false;
    }else{
        return false;
    }
}



string getReal(string dummy){
    bool firsts = false;
    string forReturn = "";
    int checks = 0;
    for(int i=0;i<dummy.size();i++){
        if(dummy[i] == '0'){
            checks++;
        }
    }
    if(checks == dummy.size()){
        return "0";
    }

    for(int i=0;i<dummy.size();i++){
        if(dummy[i] == '0' && firsts == false){
            continue;
        }else{
            firsts= true;
            forReturn+=dummy[i];
        }
    }
    return forReturn;
}

void getArr(string temp){
    string dummy = "";
    for(int i=0;i<temp.size();i++){
        if(temp[i] >=48 && temp[i]<=57){
            dummy += temp[i];
            // cout << dummy << "\n";
        }else{
            if(dummy != ""){
                // answer.push_back(stoll(dummy));
                //100자리가 넘을 수 있기에 0을 제거 후에 string으로 출력해야하는구나
                vec.push_back(getReal(dummy));
                dummy = "";
            }
        }
    }
    if(dummy != ""){
                vec.push_back(getReal(dummy));
                dummy = "";
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    string temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        // vec.push_back(temp);
        getArr(temp);
    }

    sort(vec.begin(),vec.end(),comp);
    for(auto it : vec){
        cout << it << "\n";
    }

}