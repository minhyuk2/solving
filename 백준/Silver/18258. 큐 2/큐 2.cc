#include <bits/stdc++.h>

using namespace std;

int N;

void makeCalculator(){
    queue<int> que;
    string str;
    for(int i =0; i<=N;i++){
        getline(cin,str);
        if(str.find("push") != string::npos){
            //push를 포함하고 있는 경우에는
            string subStr = str.substr(5,string::npos);
            int number = stoi(subStr);
            que.push(number);
        }else if(str.find("pop") != string::npos){
            if(que.empty()){
                cout << -1 <<"\n";
            }else{
                cout << que.front() << "\n";
                que.pop();
            }
        }else if(str.find("size") != string::npos){
            cout << que.size() << "\n";
        }else if(str.find("empty") != string::npos){
            if(que.empty()){
                 cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(str.find("front") != string::npos){
            if(que.empty()){
                cout << -1 <<"\n";
            }else{
                cout << que.front() << "\n";
            }
        }else if(str.find("back") != string::npos){
            if(que.empty()){
                cout << -1 <<"\n";
            }else{
                cout << que.back() << "\n";
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    makeCalculator();


}