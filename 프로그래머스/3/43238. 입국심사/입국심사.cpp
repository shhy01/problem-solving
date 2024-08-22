#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    //가장 큰 값을 뽑기 위해 정렬
    sort(times.begin(), times.end());
    
    long long min = 1;
    long long max = n * (long long)times.back();
    
    //입국 심사 최소 수 조건을 만족하는가 T F가 갈리는 시점이 존재하며, 시간은 정렬되어 있다.
    //따라서, 심사를 받는 데 걸리는 '최소 시간'을 구하는 방법으로, 이분 탐색을 사용할 수 있다.
    
    //최대, 최소가 바뀌는 구간이 '최소 시간'이 된다.
    while(min <= max) {
        long long avg = (min+max)/2;
        long long tmp = 0;
        
        //현재 시간(avg)로
        //각 심사위원이 처리한 입국심사 수의 합(tmp) 계산
        for (int i=0; i<times.size(); i++) {
            tmp += avg / (long long)times[i];
        }
        //입국 심사를 더 처리하는 경우
        if (tmp >= n) {
            max = avg - 1;
            answer = avg;
        }
        //입국 심사를 덜 처리하는 경우
        else {
            min = avg + 1;
        }
    }
    return answer;
}