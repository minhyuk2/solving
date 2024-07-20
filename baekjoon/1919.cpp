#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A,B;
    cin >> A >> B; //A랑 B의 문자열을 입력받는다.
    int alpha1[26] = {0,};
    int alpha2[26] = {0,};
    //어떻게 하면 각각의 문자열의 하나씩 접근해서 그것의 개수를 세서 넣어줄 수 있을까?
    for(auto it : A){
        //각 string의 한 글자씩 접근해서 어떤 알파벳이 몇 개 있는지 확인하는 식으로 코드를 작성해야 한다.
        alpha1[it-'a']++; //해당하는 단어에 대해서 반복해준다.

    }

    for(auto it : B){
        alpha2[it-'a']++;
    }   
    int total = 0;

    for(int i = 0 ; i < 26 ; i++){
        
        total += abs(alpha1[i]-alpha2[i]);
    }
    
    cout << total << "\n";

    //어차피 알파벳은 몇 개가 안되기 때문에 각각 사용된 알파벳 개수를 센 다음에 큰 개수에서 작은 개수를 빼면 필요한 것만 남기고 다 없앨 수 있다.
    //근데 절댓값을 사용하면 이 계산을 쉽게 할 수 있다.

}