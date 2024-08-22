#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<int>> DP(8);

int getNN(int N, int idx) {
    int result = N;
    for (int i=1;i<=idx;i++) {
        result = result*10 + N;
    }
    return result;
}

int solution(int N, int number) {
    if (N == number) return 1;
    
    for(int k=0;k<8;k++) {
        DP[k].insert(getNN(N, k)); //DP[k]에 NNN...(k+1)만큼 반복한 형태 삽입
        
        //DP[k]에 사칙연산 결과도 삽입
        for(int j=0; j<k; j++) {
            for(auto a : DP[j]) {
                for (auto b : DP[k-j-1]) {
                    DP[k].insert(a+b);
                    DP[k].insert(a*b);
                    if(a - b >0) DP[k].insert(a-b);
                    if(b != 0) DP[k].insert(a/b);
                }
            }
        }
        if (DP[k].find(number)!=DP[k].end())
            return k+1;
    }
    
    return -1;
}