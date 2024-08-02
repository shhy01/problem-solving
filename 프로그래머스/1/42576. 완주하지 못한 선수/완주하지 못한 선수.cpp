//동명이인이 있을 수 있다는 걸 고려해야 함
//return해야 하는 비완주자 한명만 찾으면 됨
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> map;
    
    for(auto player : participant)
        map[player]++;
    for(auto player : completion)
        map[player]--;
    
    for(auto player : participant)
        if(map[player] > 0) {
            answer = player;
            break;
        }
    return answer;
}