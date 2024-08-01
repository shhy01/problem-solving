//https://www.acmicpc.net/problem/1806

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력 받기
    int N, S;
    cin >> N >> S;
    int list[100001] = {};
    for (int i=0; i<N; i++) {
        cin >> list[i];
    }

    //계산하기
    int end_idx = 0;
    
    int sum = list[0];
    int ans = 0x7fffffff;
    for (int start_idx = 0; start_idx < N; start_idx++) {
        while((end_idx < N) && (sum < S)) {
            end_idx++;
            if (end_idx != N) sum += list[end_idx];
        }
        if(end_idx >= N) break;

        ans = min(ans, end_idx - start_idx + 1);
        sum -= list[start_idx];
    }
    if(ans == 0x7fffffff) ans = 0;
    cout << ans;
    return 0;
}