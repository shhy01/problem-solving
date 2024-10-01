//https://www.acmicpc.net/problem/14940

//n(세로)*m(가로)의 지도가 주어진다.
//0:갈 수 없음 1:갈 수 있음 2:목표 지점

//상하좌우로만 움직일 수 있다고 할 때,
//각 지점에서 목표지점까지의 거리로 지도를 다시 출력

#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int n, m;
int MAP[MAX][MAX] = {0};
int ANSWER[MAX][MAX] = {0};
int target_x, target_y;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void BFS(int a, int b) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b)); //처음 방문한 정점을 Q에 push

    while(!q.empty()) {
        //큐에서 원소 하나를 뽑아 출력
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i=0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx>=0 && ny>=0 && nx<n && ny<m) {
                if(ANSWER[nx][ny] == 0 && MAP[nx][ny] != 0) {
                    ANSWER[nx][ny] = ANSWER[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void solve() {
    //BFS탐색
    
    BFS(target_x, target_y);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(MAP[i][j] != 0) {
                cout << ANSWER[i][j] - 1 << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << '\n';
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int num;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> num;
            if(num == 2) { //목표지점의 위치를 저장해두어서, 탐색 시작 위치로 설정할 것이다.
                target_x = i;
                target_y = j;
            }
            MAP[i][j] = num;
        }
    }

    //탐색 결과를 위한 ANSWER 맵 사용.
    //탐색을 하지 않은 곳은 0, 탐색 시작 위치를 1
    ANSWER[target_x][target_y] = 1; 
    //BFS 탐색이 된 곳은 시작 위치로부터 거리만큼 1씩 증가하도록 ANSWER 맵 설정.
    //결과는 탐색이 되지 않은 곳은 그대로 0 출력, 탐색이 된 곳은 1 감소한 값(목표 지점과의 거리)으로 반환.
    solve();

    return 0;
}