#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long int> arr;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    long long int number;
    for(int i =0;i<N;i++){
        cin >> number;
        arr.push_back(number);
    }
    sort(arr.begin(),arr.end());
    long long int maxNum = 0;
    long long int tempNum = 0;
    int counter = 0;
    int tempCounter = 0;
    for(int i=0;i<N;i++){
        if(tempNum == arr[i]){
            tempCounter++;
        }else{
            tempNum = arr[i];
            tempCounter = 1;
        }
        if(tempCounter == counter){
            if(maxNum > tempNum){
                maxNum = tempNum;
            }
        }else if(tempCounter > counter){
            maxNum = tempNum;
            counter = tempCounter;
        }
    }

    cout << maxNum << "\n";
}