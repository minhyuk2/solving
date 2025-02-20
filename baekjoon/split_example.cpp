#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, string sep){
  vector<string> ret;
    int pos = 0;
    int next_pos = 0;
    while(next_pos < s.size()){
        string temp;
        next_pos = s.find(sep,pos);
        if(next_pos==-1){
            temp = s.substr(pos,s.size());
        }
        temp = s.substr(pos,next_pos-pos); //그렇네 substr의 두번쨰 인자는 끝나는 인덱스가 아니라 길이
        ret.push_back(temp);
        pos = next_pos + sep.size();
    }
  return ret;
}

int main(){
  string s = "hello";
  s += " BKD!"; // hello BKD!
  cout << s.size() << '\n'; // 10
  cout << s.substr(2, 3) << '\n'; // llo
  cout << s[1] << '\n'; // e
  s.replace(6, 4, "guys"); // hello guys
  cout << s << '\n';
  int it = s.find("guys"); // 6
  s.replace(it, 4, "everyone"); // hello everyone
  cout << s << '\n';
  s.erase(7, 6); // hello ee
  cout << s << '\n';
  s[6] = 'm'; // hello me
  cout << s << '\n';
  s.insert(0, "say ");// say hello me
  cout << s << '\n';
  if(s.find("to") == string::npos) // string::npos == -1
    cout << "'to' is not in string 's'\n";
  vector<string> chunks1 = split("welcome to the black parade", " ");
  // welcome/to/the/black/parade/
  for(auto chunk : chunks1) cout << chunk << '/';
  cout << '\n';
  vector<string> chunks2 = split("b*!*ac*!**!*e*!*y*!*", "*!*");
  // b/ac/a/y/
  for(auto chunk : chunks2) cout << chunk << '/';
}