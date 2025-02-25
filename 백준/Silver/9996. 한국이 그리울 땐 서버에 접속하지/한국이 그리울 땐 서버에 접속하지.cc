#include <bits/stdc++.h>

using namespace std;

int N;


vector<string> vec;

void getStandard(string starts){
    int index;
    // cout << starts << "\n";
    index = starts.find('*');
    if(index == -1){
        index = starts.find(' ');
    }
    string st1;
    string st2;
    st1 = starts.substr(0,index);
    st2 = starts.substr(index+1,-1);
    vec.push_back(st1);
    vec.push_back(st2);
    // cout << st1 <<  " " << st2 << "\n";
}

void findStandard(string temp){
    bool finds = true;
    
    for(int i =0;i<vec[0].size();i++){
        // cout << temp[i] <<  " " << vec[0][i] << "\n";
        if(temp.size() > i){
            if(temp[i] != vec[0][i]){
                // cout << "here1\n";
                finds = false;
            }

        }else{
            finds = false;
            break;
        }
    }

    for(int i =0; i<vec[1].size(); i++){
        // cout << temp.size() << "\n";
        // cout << temp[temp.size()-1-i] <<  " " << vec[1][vec[1].size()-1-i] << "\n";
        if(temp.size()-vec[0].size() < vec[1].size()){
            finds = false;
            break;
        }

        if(temp.size()-1-i >=0){
            if(temp[temp.size()-1-i] != vec[1][vec[1].size()-1-i]){

                // cout << "here2\n";
                finds = false;
            }

        }
        else{
            // cout << "here\n";
            finds = false;
            break;
        }
    }

    if(finds){
        cout << "DA\n";
    }else{
        cout << "NE\n";
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    string starts;
    string thrash;
    // getline(cin,thrash);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,starts);
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // getline(cin,thrash);
    // cin >> starts;
    getStandard(starts);
    string temp;
    for(int i =0; i<N;i++){
        cin >> temp;
        // getline(cin,temp);
        // getline(cin,thrash);
        findStandard(temp);
    }



}