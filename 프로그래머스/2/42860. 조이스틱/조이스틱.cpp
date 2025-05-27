#include <bits/stdc++.h>


using namespace std;




int solution(string name) {
    int answer = 0;
    string temp = "";
    for(int i = 0; i< name.size();i++){
        temp += 'A';  
    }
    
    for(int i = 0; i< name.size();i++){
        //왼쪽으로 가는 것에 대한 고려가 제일 귀찮을 것 같은데,, 흠
        //따로 따로 이동시키기 어차피 위로 만들기랑 옆으로 보내기 어떤게 더 클지를 거기서 갈리니가
        if(name[i] >= 'A' && name[i] <= 'M'){
            answer += (name[i] - 'A');
        }else{
            answer += (abs(name[i]-'Z')+1);
        }
    }
    
    int minX = name.size()-1;
    int n = name.size();
    //이 방향이동에 대해서 고려할게 좀 생기네
    for(int i = 0; i< name.size();i++){
        int y = i + 1;
        
        while(name[y] == 'A' &&  y < name.size()) y++;
        minX = min( minX,  i+i+(n-y) );
        minX = min(minX, i+ (n-y) + (n-y));
    }
    
    answer += minX;
    
    //JPAAAAAAN 같은게 해결이 안되네 지금 내 코드는 한 쪽으로만 쭉 가니까
    //현재 위치에서의 비용을 고려해야함
    
    
    
    return answer;
}