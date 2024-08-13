#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<int> number_set;

int check_prime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }
    
    // 에라토스네스의 체
    for(int i=2; i<=sqrt(num); i++) {
        if (num%i == 0)
            return false;
    }
    return true;
}

void make_combination(string temp_combination, string others) {
    // 현재 조합이 비어있다면, 숫자로 변환해 number_set에 추가한다.
    if (temp_combination != "")
        number_set.insert(stoi(temp_combination));
    
    //others 문자열의 각 문자를 하나씩 선택해 조합하며,
    //선택된 i번째 문자를 제거한 새로운 문자열 생성.
    //새로운 조합과, 문자열로 재귀호출.
    for(int i=0; i<others.size(); i++) {
        make_combination(temp_combination+others[i], others.substr(0, i)+others.substr(i+1));
    }
}

int solution(string numbers) {
    make_combination("", numbers);

    int answer = 0;
    for(int num : number_set)
        if(check_prime(num))
            answer++;
            
    return answer;
}