#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
/*
brown  = 2 * (row + col) + 4;
yellow = (row - 2) * (col - 2);

sum = ((brown - 4) / 2) - 4;    // (row-2) + (col-2)
mul = yellow;                   // (row-2) * (col-2)
*/
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer; //가로, 세로
    vector<int> divisor; //약수
    
    // 1. 약수 구하기
    for(int i=1 ; i<=sqrt(yellow); ++i) {
        if(yellow%i==0) {
            divisor.push_back(i);
            if (i != yellow/i)
                divisor.push_back(yellow/i);
        }
    }
    
    // 2. 약수를 작은 순서대로 정렬
    sort(divisor.begin(), divisor.end());
    
    // 3. row, col 구하기
    for(int i=0;i<divisor.size();i++) {
        int height = divisor[i];
        int weight = yellow / divisor[i];
        
        if ((weight + 2) * (height + 2) == (brown+yellow)) {
            answer.push_back(weight+2);
            answer.push_back(height+2);
            break;
        }
    }
    return answer;
}