#include <iostream>

using namespace std;

//다시 한 번 풀어볼 것

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int paper[100][100] = {0,};
    int answer=0;
    int left, bottom;
    for(int i =0; i<N; i++){
        cin >>left >> bottom;
        
        for(int j = left; j < left +10; j++){
            for(int k = bottom; k < bottom +10; k++){
                if(paper[j][k]!=1){
                    answer++;
                    paper[j][k]=1;
                }
            }
        }
    }
    cout << answer << "\n";

}