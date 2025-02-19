#include <bits/stdc++.h>

using namespace std;


int L,C;
vector<char> arr;
vector<char> vowel;
vector<char> consonant;

void printPass(vector<char> &passWord){
    for(auto it : passWord){
        cout << it;
    }
    cout << "\n";
}



void getVowel(int vNum,int cNum,vector<char> &passWord,int now){
    if(passWord.size() == L){
        if(vNum >=1 && cNum >= 2){
            printPass(passWord);
        }
        return;
    }

    // bool checkV = false;
    for(int i = now;i<C;i++){
        bool checkV = false;
        for(auto it : vowel){
            if(arr[i] == it){
                vNum++;
                checkV = true;
                break;
            }
        }
        if(!checkV)
            cNum++;
        passWord.push_back(arr[i]);
        getVowel(vNum,cNum,passWord,i+1);
        passWord.pop_back();
        
        if(!checkV){
            cNum--;
        }
        else{
            vNum--;
        }
    }

}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //수가 작은 걸로 비롯하여 시뮬레이션이나 백트랙킹으로 푸는 문제구나 싶네

    cin >> L >> C;
    char number;
    for(int i=0;i<C;i++){
        cin >> number;
        arr.push_back(number);
        if(number == 'a' || number == 'e' || number == 'i' || number == 'o' || number == 'u'){
            vowel.push_back(number);
        }
        else{
            consonant.push_back(number);
        }
    }

    // for(auto it : vowel){
    //     cout << it << " ";
    // }
    // cout << "\n";
    //처음부터 정렬해줌
    sort(arr.begin(),arr.end());
    vector<char> passWord;
    getVowel(0,0,passWord,0);

}