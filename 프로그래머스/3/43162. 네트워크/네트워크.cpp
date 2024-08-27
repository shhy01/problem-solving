/*
    인접행렬로 구성된 그래프를 생각하자.
    이는 무방향의 n*n 2차원 배열로 표현된다.
    예1)  예2)
    110   110
    110   111
    001   011
    
    인접행렬은 구현이 쉽고, 연결 유무를 확인하는데 O(1).
    단, 전체 노드 개수 V와 간선 개수 E에 대해서, 노드 i에 연결된 모든 노드 방문 -> adj[i][1] ~ adj[1][V]로 O(V).
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

void BFS(vector<vector<int>> computers, int v) {
    visited[v] = true; // 현재 vertex 방문처리
    
    queue<int> q;
    q.push(v); //시작 vertex 삽입
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        //v와 인접한 vertex 탐색
        for(int i=0; i<computers.size(); i++){
            if(visited[i]==false && computers[front][i]==1) {
                visited[i] = true; //해당 노드 방문 표시
                q.push(i); //해당 노드와 연결된 다른 노드들을 차례차례 넣기
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    // visited 벡터를 통해 노드 방문 추적.
    // n크기 벡터를 false로 초기화
    visited = vector<bool>(n, false);
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            BFS(computers, i);
            //DFS(i);
            answer++;
        }
    }
    
    return answer;
}