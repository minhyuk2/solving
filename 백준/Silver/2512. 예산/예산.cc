#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int N;
vector<ll> arr;
ll M;
ll total;

bool solve(ll x){

    ll temp = 0;
    int counter = 0 ;
    for(auto it : arr){
        if(it <=x){
            temp += it;
            counter ++;
        }
    }

    temp = temp + (N-counter) * x;
    if(temp <= M){
        return true;
    }else{
        return false;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int temp;
    for(int i =0; i< N; i++){
        cin >> temp;   
        arr.push_back(temp);
        total += temp;
    }

    cin >> M;

    if(total <= M){
        cout << *max_element(arr.begin(),arr.end()) << "\n";
    }else{
        
        sort(arr.begin(),arr.end());


        ll st = 1;
        ll en = 100000001;

        while(st < en){
            ll mid = (st + en + 1)/2;

            if(solve(mid)) st = mid;
            else en = mid - 1;

            // cout << st << "\n";
        }

        cout << st << "\n";





        // ll medium =  M / N;

        // ll tempSum = 0;
        // int counter = 0;
        // for(auto it : arr){
        //     if(it <= medium){
        //         tempSum += it;
        //         counter++;
        //     }
        // }


        // ll vers = M - tempSum;
        // cout << vers/(N-counter) << "\n";
    }




}