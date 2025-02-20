#include <bits/stdc++.h>

using namespace std;

string documents;
string checks;

int answer ;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string dummmys;
    getline(cin,documents);
    getline(cin,checks);

    size_t index = 1;
    // cout << documents << "\n";
    // cout << checks << "\n";
    
    while(index != string::npos){
        index = documents.find(checks);
        if(index == string::npos)
            break;
        answer++;
        documents = documents.substr(index+checks.size(),string::npos);
        
    }
    cout << answer << "\n";
    
}