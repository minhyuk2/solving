#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int temp;
    int count;
    for(int t=0;t<=citations.size();t++)
    {
        count = 0;
        for(int i=0;i<citations.size();i++){
            if(citations[i] >= t){
                count++;
            }
        }
        if(count >= t){
            answer = t;
        }
    }
    
    return answer;
}