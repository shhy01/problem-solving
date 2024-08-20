#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//한번에 최대 2명이라는 전제가 있기 때문에,
//가장 무거운 사람과 가벼운 사람 조합으로 2명이 탈 수 있는지를 확인하면 됨.

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    int left = 0;
    int right = people.size() -1;
    
    while(left <= right) {
        //가장 무거운 사람과 가벼운 사람이 동시에 탈 수 있다면,
        if(people[left] + people[right] <= limit) {
            left++; //가장 가벼운 사람도 탑승
        }
        right--; //가장 무거운 사람 탑승
        answer++; //구명보트 개수 증가
    }

    return answer;
}