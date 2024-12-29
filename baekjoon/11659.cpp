#include <bits/stdc++.h>

using namespace std; 

// int board[100001][100001];
int getB[100001];


int checkOut(int range1, int range2,int N){
    return getB[range2] - getB[range1-1];
}


int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> ansarr;
    int N, M;
    cin >> N >> M;
    int tempo;
    getB[0] = 0;
    for(int i = 1 ;  i <= N ; i++){
       cin >>  tempo;
       getB[i] = tempo + getB[i-1];
    }
    int range1;
    int range2;
    for(int i =0; i < M ; i ++){
        cin >> range1 >> range2;
        ansarr.push_back(checkOut(range1,range2,N));
    }

    for (std::vector<int>::iterator it = ansarr.begin(); it != ansarr.end(); ++it) {
                cout << *it << "\n";
    }
}  
    