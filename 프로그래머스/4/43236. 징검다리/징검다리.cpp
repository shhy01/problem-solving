#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int distance, vector<int> rocks, int n) {    
    long long min = 1;
    long long max = distance;
    long long mid;
    int answer = 0;
    int cnt, prev;
    
    sort(rocks.begin(), rocks.end());
    while(min <= max) {
        mid = (min+max)/2;
        cnt = 0;
        prev = 0;
        //0번째부터 돌 사이 간격 확인
        //(따라서, 출발지점~첫번째돌 비교부터 시작됨)
        for(int i=0; i<rocks.size(); i++) {
            if(mid > (rocks[i] - prev)) //돌 사이의 간격이 mid보다 작다면, i번째 바위를 제거한다.
                cnt++; //제거한 바위 수 증가
            else
                prev = rocks[i]; //다음 조건 확인을 위해 prev 업데이트
        }
        
        if(mid > distance - prev) //마지막 돌과 도착지점 비교
            cnt++;
        
        //제거한 돌 개수 결과에 따라, min max 조정
        if(cnt > n) { //(*조건)돌을 더 많이 제거한다면
            max = mid - 1;
        }
        else { //돌을 같거나 덜 제거했다면
            min = mid + 1;
            answer = mid; //(*조건)정확히 제거한 바위가 n개일 때의 최소 거리들 중 최댓값을 찾아야 한다.
        }
    }
    return answer;
}