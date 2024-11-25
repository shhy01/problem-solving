// https://www.acmicpc.net/problem/11659
// 구간 합 구하기 4 : 누적합(요소들의 누적된 합을 저장해 새로운 배열을 만들어 활용)
#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int N, M;
    int i, j;
    int num, tmp_sum=0;
    vector<int> prefix_sum;
    int result;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    prefix_sum.insert(prefix_sum.begin(), 0);
    for(int idx=1; idx<=N; idx++) {
        cin >> num;
        tmp_sum += num;
        prefix_sum.insert(prefix_sum.begin()+idx, tmp_sum);
    }
    for(int idx=0; idx<M; idx++) {
        cin >> i >> j;
        result = prefix_sum[j] - prefix_sum[i-1];
        cout << result << "\n";
    }
}