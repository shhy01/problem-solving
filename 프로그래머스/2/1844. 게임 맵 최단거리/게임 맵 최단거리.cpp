#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();    //행의 수
    int m = maps[0].size(); //열의 수
    
    // 방향 벡터 (상,하,좌,우)
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    queue<pair<int, int>> q; // BFS를 위한 큐
    q.push({0, 0});          // (row, col) 위치와 현재까지의 거리 저장
    
    maps[0][0] = 1; //초기 위치는 1로 설정 (이미 방문한 곳)
    
    
    while (!q.empty()) {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        int distance = maps[curr_row][curr_col];
        q.pop();
        
        //도착 지점에 도달한 경우
        if (curr_row == (n-1) && curr_col == (m-1)) {
            return distance;
        }
        
        //상하좌우 탐색
        for(int i=0; i<4; i++) {
            int temp_row = curr_row + dy[i];
            int temp_col = curr_col + dx[i];
            
            if(temp_row >=0 && temp_row < n && temp_col >= 0 && temp_col < m && maps[temp_row][temp_col] == 1) {
                maps[temp_row][temp_col] = distance + 1;
                q.push({temp_row, temp_col});
            }
        }
    }
    
    return -1;
}