#include <bits/stdc++.h>

using namespace std;

int N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    string str;
    deque<int> deq;
    for(int i =0; i<=N; i++){
        getline(cin,str);
        if(str.find("push_front") != string::npos){
            string subStr = str.substr(11);//이러면 12부터 끝까지를 인식
            int number = stoi(subStr);
            deq.push_front(number);

        }else if(str.find("push_back") != string::npos){
            string subStr = str.substr(10);//이러면 12부터 끝까지를 인식
            int number = stoi(subStr);
            deq.push_back(number);
            
        }else if(str.find("pop_front") != string::npos){
            if(deq.empty()){
                cout << -1 << "\n";
            }else{
                cout << deq.front() << "\n";
                deq.pop_front();
            }
            
        }else if(str.find("pop_back") != string::npos){
            if(deq.empty()){
                cout << -1 << "\n";
            }else{
                cout << deq.back() << "\n";
                deq.pop_back();
            }
            
        }else if(str.find("size") != string::npos){
            cout << deq.size() << "\n";
            
        }else if(str.find("empty") != string::npos){
            if(deq.empty()){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
            
        }else if(str.find("front") != string::npos){
            if(deq.empty()){
                cout << -1 << "\n";
            }else{
                cout << deq.front() << "\n";
            }
        }else if(str.find("back") != string::npos){
            if(deq.empty()){
                cout << -1 << "\n";
            }else{
                cout << deq.back() << "\n";
            }
        }
    }
}