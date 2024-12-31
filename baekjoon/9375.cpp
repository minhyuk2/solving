#include <bits/stdc++.h>

using namespace std;


int numbers[31];
string nums[31];

int calcNumber(int category){
    int ans = 1 ;
    int ans2 = 0;
    // if(category ==1 ){
    // for(int i = 0 ; i< category ; i ++){
    //     // ans = numbers[i] * ans;
    //     ans2 = numbers[i]+ans2;
    // }
    // return ans2;
    // }else{
    //     for(int i = 0 ; i< category ; i ++){
    //     ans = numbers[i] * ans;
    //     ans2 = numbers[i]+ans2;
    //     }
    //     return ans + ans2;
    // }
    for(int i = 0 ; i< category ; i ++){
        ans = (numbers[i]+1) * ans;
        // ans2 = numbers[i]+ans2;
    }
    return ans - 1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCase ;
    cin >> testCase;
    int clothCase;
    int category = 0;
    string  cloth, cate;

    for(int i= 0 ; i< testCase ; i ++){
        cin >> clothCase;
        category = 0;
        fill(numbers,numbers+31,0);
        fill(nums,nums+31,"0");
        for(int p = 0; p < clothCase ; p++){
            cin >> cloth >> cate;
            int catCheck = 0;
            for(int t = 0; t < category;t++){
                if(nums[t] == cate){
                    numbers[t]++;
                    catCheck = 1;
                }
            }
            if(catCheck == 0){
                //새로운게 들어온 경우
                nums[category] = cate;
                numbers[category]++;
                category++;
            }
        }
        cout << calcNumber(category) << "\n";
    }


}