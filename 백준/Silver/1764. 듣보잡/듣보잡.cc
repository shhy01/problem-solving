//https://www.acmicpc.net/problem/1764

//듣도 못한 사람 명단 N, 보도 못한 사람 명단 M이 주어지면
//듣도 보도 못한 사람 명단을 구하는 프로그램 ㅋㅋ

//듣도 보도 못한 사람 명단은 사전순으로 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<string> unheard, answer; //교집합 문제를 쉽게 해결하기 위해 set 사용. set은 중복삽입X
    string person;

    for(int i=0; i<n; i++) {
        cin >> person;
        unheard.insert(person);
    }

    for(int i=0; i<m; i++) {
        cin >> person;
        if(unheard.find(person) != unheard.end()) { //person이 unheard셋에 있다면 (find는 요소가 없다면, set의 마지막 요소를 가리키는 이터레이터를 반환)
            answer.insert(person);
        }
    }

    //듣도 보도 못한 사람 명단(unheard와 unseen의 교집합) 출력
    cout << answer.size() << '\n';
    for(const auto& unknown_person : answer) { //각 요소가 변경되지 않으면서, 데이터 타입을 자동으로 추론, 참조로 받아와 메모리 사용 줄이기.
        cout << unknown_person << '\n';
    }

    return 0;
}