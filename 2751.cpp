#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int count=0;
    cin >> count;
    // int array[count];
    // for(int i=0;i<count ; i++){
    //     cin >> array[i]; 
    // }
    vector<int> array;
    int number;
    for(int i = 0; i<count; i++){
        cin >> number;
        array.push_back(number);
    }
    sort(array.begin(),array.end());
    for(int i =0;i<count; i++){
        cout << array[i] << "\n";
    }

}