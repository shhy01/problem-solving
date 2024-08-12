#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(pq.size()>1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        answer++;
        pq.push(first + second*2);
    }
    
    if(!pq.empty() && pq.top() < K) return -1;
    return answer;
}