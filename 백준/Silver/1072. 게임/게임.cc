#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

ll X,Y;
ll Z;

bool solve(ll mid){
    // if(mid == 0) return true;
    ll z = ((Y+mid) *100)/(X+mid);

    // cout << "z : " << z <<"\n";
    return z >= (Z+1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X >> Y;
    Z = (Y*100)/X;
    // Z = ((static_cast<double>(Y)/static_cast<double>(X))) * 100;
    // Z = trunc(Z);
    // cout << "Z : " << Z <<"\n";

    ll st = 1;
    ll en  = 1000000005;

    while(st<en){
        ll mid  = (st+en)/2;

        // cout << mid << "\n";
        if(solve(mid)){
            en = mid;
        }else{
            // cout << "here\n";
            st = mid+1;
        }
    }

    if(en == 1000000005){
        cout << "-1\n";
    }else{
        cout << en << "\n";
    }

    
}