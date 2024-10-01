//https://www.acmicpc.net/problem/11724

#include <bits/stdc++.h>
using namespace std;

//양방향 그래프가 주어질 때, 연결 요소의 개수를 구하는 프로그램 작성하기
//입력 : 정점 개수 N(1~1000), 간선 개수 M(1~N*(N-1)/2) / 간선의 양 끝 점 u, v를 M번 주어진다.
//출력 : 연결 요소의 개수를 출력한다.

//그래프는 인접행렬 혹은 인접리스트로 구현하면 된다.
//인접리스트로 구하는 것이, 공간복잡도 면에서 유리할 것이다. O(N+M)

void DFS(int node, vector<vector<int>>&graph, vector<bool>& visited) {
    visited[node] = true; // 현재 노드를 방문 표시
    
    //현재 노드와 연결된 모든 노드 탐색
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1); //1부터 n까지 노드를 사용.
    vector<bool> visited(N+1, false); //방문 여부를 확인할 벡터 선언

    //주어진 간선들에 연결된 노드 입력 받기
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans=0;

    //모든 노드에 대해 DFS 수행
    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            DFS(i, graph, visited); //현재 노드 i와 연결된 모든 노드 탐색
            ans++;
        }
    }
    cout << ans;
    return 0;
}