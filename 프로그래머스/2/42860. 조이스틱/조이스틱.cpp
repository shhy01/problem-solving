#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int move = n - 1; //커서 이동 횟수
    
    for(int i=0; i<n; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1); //알파벳 이동. A라면 0으로 반환됨.
        //커서 이동 방향 결정 (greedy)
        int next = i + 1;
        while(next < n && name[next]=='A') {
            next++;    //A가 아닌 점의 위치
        }
        move = min(move, min(i, n-next)+(i+n-next)); //커서 이동
        //그대로 이동하거나,
        //i 위치까지의 최소 이동 거리 + (i 위치에서 원점을 거쳐, 문자열 끝에서부터 next 위치로 탐색하는 경우)
    }
    answer += move;
    return answer;
}