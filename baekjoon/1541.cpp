#include <bits/stdc++.h>

//https://www.acmicpc.net/problem/1541

using namespace std;


long long int findPlus(vector<string> strArr){
    int position;
    int cur = 0;
    long long int minVal = 0;
    int currVal = 0;
    int firstCk = 0;
    // vector<string> strArr;
    //이러면 -를 기준으로 분리한 것이다.
    for(auto it = strArr.begin();it != strArr.end(); ++it){
        // cout << *it <<"\n";
        if(it->find("+")==string::npos){
            //+가 없는 경우
            currVal  = stoi(*it);
        }else{
            while((position = it->find("+",cur))!=string::npos){
                int len = position - cur;
                currVal += stoi(it->substr(cur,len));
                // cout << currVal << "\n";
                cur = position + 1;
            }
            if (cur < it->size()) {
                //이 남은 마지막 더하는 것을 절대 까먹지 말자
            
            //마지막을 더하기 위한  것
                currVal += stoi(it->substr(cur));
            }
        }
  
        if(firstCk ==0){
            minVal += currVal;
            firstCk = 1;
        }else{
            minVal -= currVal;
        }
        currVal = 0;
        cur = 0;
    }
    return minVal;
}

int findMinus(string liness){
    int position;
    int ans  =0;
    int cur = 0;
    vector<string> strArr;
    //이러면 -를 기준으로 분리한 것이다.
    while((position = liness.find("-",cur))!=string::npos){
        int len = position - cur;
        strArr.push_back(liness.substr(cur,len));
        // cout << liness.substr(cur,len)<<"\n";
        cur = position + 1;

    }
    if (cur < liness.size()) {
        //이렇게 되면 시작 위치만 지정해주는 것이다.
        //   cout << liness.substr(cur)<<"\n";
        strArr.push_back(liness.substr(cur));
    }
    return findPlus(strArr);
}



//여는 괄호는 숫자앞이나 

int main(void){
    //-뒤의 값이 최대가 되게끔 만들면 되는것이다.
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string tempLine;
    getline(cin,tempLine);
    // cout << tempLine<<"\n";
    cout << findMinus(tempLine) << "\n";
}