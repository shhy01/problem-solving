#include <string>
#include <vector>

using namespace std;

int answer = 51;
bool visited[50] = {};

void DFS(int step, string begin, string target, vector<string> words) {
    if(begin == target) {
        if (step < answer) {
            answer = step;
        }
        return;
    }
    
    for(int i=0; i<words.size(); i++) {
        if(visited[i]) {
            continue;
        }
        
        int diffCount = 0;
        for(int j=0; j<begin.size(); j++) {
            if(begin[j] != words[i][j]) {
                diffCount++;
            }
        }
        
        if(diffCount == 1) {
            visited[i] = true;
            DFS(step+1, words[i], target, words);
            visited[i] = false; //원상복귀
        }        
    }
}

int solution(string begin, string target, vector<string> words) {
    //만약 words 중에 target이 없다면, 바로 종료
    bool targetExists = false;
    for(string word : words) {
        if(word == target) {
            targetExists = true;
            break;
        }
    }
    if(!targetExists) {
        return 0;
    }
    
    //DFS 탐색
    DFS(0, begin, target, words);
    return answer == 51 ? 0 : answer;
}