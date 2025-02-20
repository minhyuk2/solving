#include <bits/stdc++.h>

using namespace std;

vector<string> arr;
int N;

//문제가 sort의 comp 부분을 구하는 것을 요구한다는 것을 알고 풀었다.
bool  comp(const string& str1, const string str2){
    if(str1.size() < str2.size()){
        return true; // 더 작은 것에 대해서 true 큰 것에 대해서 false가 리턴되어야한다.
    }else if(str1.size() > str2.size()){
        return false;
    }else{
        //같은 경우
        int number1 =0,number2=0;
        for(auto it : str1){
            if(it-'0' < 10 && it-'0' >=0){
                number1 += (it-'0');
            }
        }
        for(auto it : str2){
            if(it-'0' < 10 && it-'0' >=0){
                number2 += (it-'0');
            }
        }

        if(number1 < number2){
            return true;
        }else if(number1 > number2){
            return false;
        }else{
            return str1 < str2;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    string temp;
    for(int i =0; i< N;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end(),comp);

    for(auto it : arr){
        cout << it << "\n";
    }
}