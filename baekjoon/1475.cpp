#include <iostream>
#include <string>
using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string setNum;
    int numbers[10] = {0,};
    cin >> setNum; 
    //set에 적힌 숫자를 입력받음

    //제일 많이 쓰인 숫자가 뭔지 파악하고 그 숫자를 통해서 세트를 구하는데 그때 6,9만 고려하면 됨
    for(int i =0 ; i < setNum.length() ; i++){
        //한글자씩 판단해서 숫자세기 
        numbers[setNum[i]-'0']++;
    }
    int max = 0;
    int smallMax = 0; //차선의 max
    for(int i =0; i < 10; i++){
        if(max < numbers[i]){
            max = numbers[i];
        }
        if(i != 6 && i != 9){
            if(smallMax < numbers[i]){
                smallMax = numbers[i];
            }
        }
    }
    //이렇게 푸는 것도 하나의 방법이지만 입력을 받을 때 6,9일때 하나로 입력받는 것도 하나의 방법이다.

    
    if((max == numbers[6])||(max == numbers[9])){
        //max가 6이랑 9로 잡힌 경우에 차선의 큰 것을 찾아놓고 그거랑 비교
        int top;
        //cout << numbers[6] << "  " << numbers[9] << "\n";
        if((numbers[6]+numbers[9])%2 == 0){
            top = (numbers[6]+numbers[9])/2;
        }else{
            top = (numbers[6]+numbers[9])/2 + 1;
        }

        if(smallMax > top){
            max = smallMax;        
        }else{
            max = top;
        }
    }

    cout << max << "\n";


}