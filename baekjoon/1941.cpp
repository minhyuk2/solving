#include <bits/stdc++.h>

using namespace std;

char classRoom[5][5];
int answer;
vector<vector<int>> accessed(5,vector<int>(5,0));
set<vector<vector<int>>> mat;
int nums[] = {-1,0,1,0};
int nums2[] = {0,1,0,-1};
int counting;


void princess(int X,int Y,int sizes,vector<pair<int,int>> &vec){
    
    if(sizes == 0){
        if(counting >=4){
            mat.insert(accessed);
        }
        return;
    }
    accessed[X][Y] = 1;
    for(auto it : vec){
        for(int p =0; p < 4; p++){
            if(it.second+nums[p] < 0 || it.first+nums2[p] < 0||it.second+nums[p]>=5||it.first+nums2[p]>=5)continue;
            if(accessed[it.first+nums2[p]][it.second+nums[p]]==1)continue;
            accessed[it.first+nums2[p]][it.second+nums[p]] = 1;
            if(classRoom[it.first+nums2[p]][it.second+nums[p]] == 'S'){
                counting++;
            }
            vec.push_back({it.first+nums2[p],it.second+nums[p]});
            princess(it.first+nums2[p],it.second+nums[p],sizes-1,vec);
            accessed[it.first+nums2[p]][it.second+nums[p]] = 0;
            if(classRoom[it.first+nums2[p]][it.second+nums[p]] == 'S'){
                counting--;
            }
            vec.pop_back();
         }   
    }

}


void getPrin(){
    vector<pair<int,int>> vec;
        for(int i =0; i< 5;i++){
            for(int t = 0 ; t < 5; t++){
                counting = 0;
                for(int q = 0 ; q< 5;q++){
                    fill(accessed[q].begin(),accessed[q].end(),0);
                }
                vec.clear();
                vec.push_back({i,t});
                princess(i,t,6,vec);
            }
        }
}


//4명 이상의 S를 보유하고 있어야 한다.


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i< 5; i++){
        for(int t = 0 ; t < 5 ; t++){
            cin >> classRoom[i][t];
        }
    }

    getPrin();
    cout << mat.size() <<"\n";

}
//     for(auto it = mat.begin(); it !=mat.end(); ++it){

//     const vector<vector<int>>& matrix = *it; // vector<vector<int>>를 참조
//         for (int i = 0; i < matrix.size(); i++) {
//             for (int t = 0; t < matrix[i].size(); t++) {
//                 cout << matrix[i][t] << " ";
//             }
//             cout << "\n";
//         }
//     }
// }