#include <bits/stdc++.h>

using namespace std;

int nums[26];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string arrays;
    cin >> arrays;

    fill(nums,end(nums),-1);
    for(int i =0; i<arrays.size();i++){
        if(nums[arrays[i]-'a'] == -1)
            nums[arrays[i]-'a'] = i;
    }

    for(int i =0; i<26;i++){
        cout << nums[i] << " ";
    }
    cout << "\n";
}