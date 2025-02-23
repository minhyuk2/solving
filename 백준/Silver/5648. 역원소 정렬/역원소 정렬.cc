#include <bits/stdc++.h>

using namespace std;
int N;
vector<long long int> vec;
vector<long long int> vec2;
long long int changess(long long int A){
    string number1 =to_string(A);
    // string number2 = to_string(B);

    reverse(number1.begin(),number1.end());
    // reverse(number2.begin(),number2.end());

    long long int num1 = stoll(number1);
    // int num2 = stoi(number2);

    return num1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i =0 ; i<N;i++){
        long long int number;
        cin >> number;
        vec.push_back(number);
    }

    for(int i =0 ; i<N;i++){
        vec2.push_back(changess(vec[i]));
    }
    sort(vec2.begin(),vec2.end());
    // sort(vec.begin(),vec.end(),comp);

    for(auto it : vec2){
        cout << it << "\n";
    }

}