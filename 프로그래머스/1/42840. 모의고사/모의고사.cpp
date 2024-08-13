#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> correct(3,0); // 각 수험자가 맞춘 문제 비율
    //각자의 솔루션
    vector<vector<int>> sol{{1,2,3,4,5},{2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    //각자 맞출 확률
    for(int i=0; i < answers.size(); i++) {
        for(int j=0; j<3; j++) {
            if (answers[i] == sol[j][i%sol[j].size()])
                correct[j]++;
        }
    }
    //가장 많이 맞춘 점수 찾기
    int max_rate = max({correct[0], correct[1], correct[2]});
    
    //가장 많이 찾은 수험자 찾아 결과 내기
    for(int i=0; i<3; i++){
        if(correct[i] == max_rate) {
            answer.push_back(i+1);
        }
    }
    return answer;
}