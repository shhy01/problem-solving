#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day;
    int max_day = 0;
    for (int i=0; i<progresses.size(); ++i) {
        day = (99 - progresses[i]) / speeds[i] + 1; //개발되는 데 필요한 날짜 계산
        
        if (answer.empty() || max_day < day) { //앞 순서의 기능 개발보다 오래 걸린다면, 추가 배포
            answer.push_back(1);
            max_day = day;
        }
        else { //앞 순서의 기능 개발보다 짧게 걸린다면, 배포될 때 기능 수 추가
            answer.back()++;
        }
    }
    return answer;
}