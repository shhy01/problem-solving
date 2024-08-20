#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    stack<char> S;
    int remove_count = 0;
    int answer_count = number.length() - k;
    
    //스택은 숫자가 작은 값이 위에 있도록 정렬
    //더 큰 수가 오면 교체, 작은 수가 오면 그대로 삽입.
    for(char c: number) {
        while(!S.empty() && remove_count < k && S.top()<c) {
            //스택 가장 위의 값보다, 현재 넣으려는 값이 더 크면
            S.pop(); //스택 값을 빼준다.
            remove_count++;
        }
        S.push(c); //현재 값을 넣는다.
    }
    
    //출력을 위한 코드
    //필요없는 부분 지우기
    while(remove_count < k) {
        S.pop();
        remove_count++;
    }
    //출력할 answer 완성하기
    string answer= "";
    while(!S.empty() && answer.length() < answer_count) {
        answer = S.top() + answer;
        S.pop();
    }
    return answer;
}