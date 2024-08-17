#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n, 1);
    
    for(auto e : lost)
        --student[e-1]; //도난당한 학생이라면 0
    for(auto e : reserve)
        ++student[e-1]; //여분이 있는 학생이라면 +2 (여분이 있는 학생이 도난당했다면 1으로 처리.)
    //즉, 빌려야하는 학생은 0, 빌려줄 수 있는 학생은 2로 처리.

    //도난당한 학생들이 체육복을 빌릴 수 있는지 확인
    for(int i=0; i<n; ++i) {
        if (student[i] == 0) {
            if (i > 0 && student[i - 1] == 2) { // 앞 번호 학생부터 빌려준다.
                --student[i - 1];
                ++student[i];
            } else if (i + 1 < n && student[i + 1] == 2) {
                --student[i + 1];
                ++student[i];
            }
        }
    }
    int answer = 0;
    for (int i=0; i<n; i++) {
        if (student[i] >= 1)
            ++answer;
    }
    return answer;
}