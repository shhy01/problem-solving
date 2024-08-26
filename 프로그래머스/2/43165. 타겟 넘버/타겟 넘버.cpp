#include <string>
#include <vector>

using namespace std;

int answer = 0;

void get_target_number(vector<int> numbers, int target, int sum, int index){
    //마지막 index때 합의 결과가 target이랑 같다면, 종료 조건 충족 -> answer 증가
    if (index == numbers.size()){
        if(sum == target){
            answer++;
        }
        //같지 않을 때도
        return;
    }
    //종료 조건이 만족되지 않으면 계속 탐색
    // (1) 더하기
    get_target_number(numbers, target, sum+numbers[index], index+1);
    // (2) 빼기
    get_target_number(numbers, target, sum-numbers[index], index+1);
}

int solution(vector<int> numbers, int target) {
    get_target_number(numbers, target, 0, 0);
    
    return answer;
}