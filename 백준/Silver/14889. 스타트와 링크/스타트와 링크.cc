#include <bits/stdc++.h>

using namespace std;

int N;
int arr[24][24];
vector<int> person;

int answer = 100000000;


bool isHere[20];
vector<int> p2;
void getBack(int start){

    if(p2.size() == N/2){
        int team1 = 0, team2 = 0;
        vector<int> temp;
        for(int i = 0;i <N;i++){
            if(!binary_search(p2.begin(),p2.end(),i)){
                temp.push_back(i);
            }
        }

        for(int i=0;i<N/2;i++){
            for(int t=0;t<N/2;t++){
                team1 += arr[p2[i]][p2[t]];
            }
        }

        for(int i=0;i<N/2;i++){
            for(int t=0;t<N/2;t++){
                team2 += arr[temp[i]][temp[t]];
            }
        }

        if(answer > abs(team1 - team2)){
            answer = abs(team1-team2);
        }

        return;
    }



    for(int i =start;i<N;i++){
        if(!isHere[i]){
            isHere[i] = 1;
            p2.push_back(i);
            getBack(i);
            isHere[i] = 0;
            p2.pop_back();
        }
    }
    return;

}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i <N;i++){
        for(int t = 0; t<N;t++){
            cin >> arr[i][t];
        }
    }



    for(int i=0;i<N;i++){
        person.push_back(i);
    }



    // do{
    //     int team1 =0;
    //     int team2 = 0;
    //     for(int i=0;i<N/2;i++){
    //         for(int t=0;t<N/2;t++){
    //             team1 += arr[person[i]][person[t]];
    //         }
    //     }

    //     for(int i=N/2;i<N;i++){
    //         for(int t=N/2;t<N;t++){
    //             team2 += arr[person[i]][person[t]];
    //         }
    //     }

    //     if(answer > abs(team1 - team2)){
    //         answer = abs(team1-team2);
    //     }

    // }while(next_permutation(person.begin(),person.end()));
    // //순열을 구하는 것이기에 에러가 발생하는 것이다. 그러면 조합을 구하게끔 수정해야겠네


    getBack(0);

    cout << answer << "\n";
}