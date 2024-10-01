//https://www.acmicpc.net/problem/2805

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N; //나무의 수 (1~1,000,000,000)
ll M; //가져갈 나무의 길이 (1~2,000,000,000)

vector<ll> trees; //전체 나무

ll mid; //이분 탐색을 위한 중간값

int valid(ll mid) {
    ll temp_sum = 0;
    for(const auto &tree:trees) {
        temp_sum += (tree > mid ? tree-mid : 0); 
        if (temp_sum >= M) return true; // 필요한 만큼 벌써 채웠다면 더 이상 계산할 필요 없음
    }
    return temp_sum >= M;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    trees.resize(N);
    ll tree;
    for(ll i=0; i<N; i++) {
        cin >> trees[i];
    }

    //정렬이 되고, 목표에 대해 true/false가 되는 지점이 정해지므로
    //이분탐색
    sort(trees.begin(), trees.end());

    ll left=0;
    ll right=*max_element(trees.begin(), trees.end());
    ll answer = 0;

    while(left <= right) {
        mid = left + (right - left)/2; //중간값 계산 시 overflow 방지 : (left+right)/2
        if(valid(mid)) {
            answer = mid; //가능한 높이 중 가장 큰 값을 mid에 갱신
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    //valid length 중 가장 큰 값 출력
    cout << answer << '\n';
    return 0;
}