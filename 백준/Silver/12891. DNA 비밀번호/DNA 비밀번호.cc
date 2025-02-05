#include <bits/stdc++.h>
using namespace std;

char type[4] = {'A', 'C', 'G', 'T'};
map<char, int> minValue; //부분 문자열에 포함되어야 할 {'A', 'C', 'G', 'T'} 최소 개수

//조건에 맞는 부분 문자열인지 확인하는 함수 정의
bool check(map<char, int> temp) {
    for(auto iter = minValue.begin(); iter != minValue.end(); ++iter) {
        if(iter->second != 0) {
            if(temp.find(iter->first) != temp.end()) {
                if((iter->second) <= temp[iter->first]) continue;
                else return false;
            } else return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    
    //input
    int S, P; 
    cin >> S; //임의로 만들 문자열 길이 S
    cin >> P; //비밀번호로 사용할 부분문자열 길이 P
    
    string str;
    cin >> str; //임의로 만든 문자열
    
    for (int i=0; i<4; i++) {
        cin >> minValue[type[i]]; //부분 문자열에 포함되어야 할 {'A', 'C', 'G', 'T'} 최소 개수
    }
    
    //calc
    //1. 임시 부분 문자열의 {문자, 개수} counting 
    map<char, int> substringCount; //조건을 만족하는 지 확인할 임시 부분 문자열의 {문자, 개수}
    for(int i=0; i<P; i++) { // inital 부분 문자열 : str[0] ~ str[P-1]
        substringCount[str[i]] += 1;
    }
    
    //2. 임시 부분 문자열이 조건을 만족하면 ans++;
    if(check(substringCount)) ans++;
    
    //3. 주어진 str을 한 문자씩 오른쪽으로 sliding window
    for(int i=P; i<S; ++i) { //initial 부분 문자열 str[0] ~ str[P-1]에서 오른쪽으로 한 문자씩 sliding window
        substringCount[str[i-P]] -= 1; //기존 window의 가장 왼쪽 문자는 sliding window를 하면서 개수 카운팅을 취소
        substringCount[str[i]] += 1; //새로 window에 해당하게 된 문자는 개수 카운팅
        if(check(substringCount)) ans++; //다시 조건 확인 후 ans++;
    }
    
    cout << ans;

    return 0;
}