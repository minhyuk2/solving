#include <bits/stdc++.h>

using namespace std;

int nodes[100001];

void gets(int st, int en){
    if(st >= en){
        return;
    }
    if(st == en-1){
        cout << nodes[st] << "\n";
        return;
    }
    
    int temp = nodes[st];
    // cout << temp << "\n";
    int newSt, newEn;

    newSt = st+1;
    newEn = newSt;
    for(int i=newSt;i < en; i++){
        if(nodes[i] > nodes[st]){
            // cout << nodes[i] << "\n";
            newEn = i;
            break;
        }
    }
    gets(st+1,newEn);
    gets(newEn,en);
    cout << temp << "\n";

}




int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int idx = 0;
    while(cin >> num){
        if(num == EOF){
            break;
        }
        nodes[idx++] = num;
    }
    // cout << idx << "\n";
    gets(0,idx);

}