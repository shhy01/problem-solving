// https://www.acmicpc.net/problem/11723
// 비어있는 공집합 S가 주어졌을 때 아래 연산을 수행
// add, remove, check, toggle, all, empty

// 비트마스크를 이용한 구현
// 1<<0 : 1'd 0b0001
// 1<<1 : 2'd 0b0010
// 1<<2 : 4'd 0b0100
// (1<<20)-1) : 0b1111_1111_1111_1111_1111 혹은 0xFFFFF
// (1<<21)-1) : 0b1_1111_1111_1111_1111_1111 (21칸)

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, x;
    unsigned int s = 0;
    string commands = "";

    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> commands;
        if (commands == "add") {
            cin >> x;
            s |= (1<<x);
        } else if (commands == "remove") {
            cin >> x;
            s &= ~(1<<x);
        } else if (commands == "check") {
            cin >> x;
            cout << ((s & (1<<x)) ? 1 : 0) << "\n";
        } else if (commands == "toggle") {
            cin >> x;
            s ^= (1<<x);
        } else if (commands == "all") {
            s = (1<<21)-1;
        } else if (commands == "empty") {
            s = 0;
        } else {
            cout << "commands error \n";
        }
    }
}