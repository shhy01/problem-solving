#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1); //2차원 그래프 만드는 배열
    vector<int> counts(n+1, 0); //counter를 위한 배열
    vector<bool> visited(n+1, false); //visited 배열
    queue<int> q; //BFS 탐색을 위한 큐
    int answer = 0;
    
    //1. 인접 리스트 기반 그래프 생성
    for(int i=0; i<edge.size(); i++) {
        //양방향 그래프이므로 시작, 끝 변경해서 연결
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    //첫 노드 push
    q.push(1);
    visited[1] = true;
    
    //2. BFS
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i=0; i<graph[node].size(); i++) {
            //최단거리를 위해 방문 유무를 검사
            if(!visited[graph[node][i]]) {
                int dist = counts[node] + 1;
                visited[graph[node][i]] = true;
                
                counts[graph[node][i]] = dist;
                q.push(graph[node][i]);
            }
        }
    }
    //3. 가장 먼 노드의 개수 계산
    sort(counts.begin(), counts.end(), greater<int>());
    for(auto cnt:counts) {
        if(counts[0]!=cnt) break;
        answer++;
    }
    return answer;
}