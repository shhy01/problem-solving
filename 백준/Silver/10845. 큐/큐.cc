//https://www.acmicpc.net/problem/10845

//정수를 저장하는 큐를 구현한다음,
//입력으로 주어진 명령을 처리하는 프로그램을 작성하시오.

//push X : 정수 X를 큐에 넣는 연산
//pop : 가장 앞에 있는 정수를 빼고, 그 수를 출력. 없는 경우 -1
//size : 큐에 들어있는 정수의 개수를 출력
//empty : 큐가 비어있으면 1, 아니면 0을 출력
//front : 큐의 가장 앞에 있는 정수를 출력. 없는 경우 -1
//back : 큐의 가장 뒤에 있는 정수를 출력. 없는 경우 -1

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N; //명령의 수
    queue<int> Q;
    
    string cmd;
    for(int i=0; i<N; i++) {
        //명령어가 주어지면, 한 줄에 하나씩 출력을 진행.
        cin >> cmd;
        if (cmd == "push") {
            int X;
            cin >> X;
            Q.push(X);
        } else if (cmd == "pop") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if (cmd == "size") {
            cout << Q.size() << '\n';
        } else if (cmd == "empty") {
            cout << Q.empty() << '\n';
        } else if (cmd == "front") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
            }
        } else if (cmd == "back") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.back() << '\n';
            }
        }
    }
}