// https://softeer.ai/practice/6247
// 주어진 요소 n개의 집합에서 서로 다른 3개를 선택했을 때 중간값이 mi가 나올 수 있는 가지수를 q번 출력

#include <bits/stdc++.h>

using namespace std;

int n, q;

int binary_search(const vector<int>& cars, int mi);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> cars;

    // 입력
    cin >> n >> q;
    int temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        cars.push_back(temp); //자동차 각 연비 입력. (서로 다름을 가정)
    }
    sort(cars.begin(), cars.end()); // 정렬 : O(n logn)

    // 정렬된 값에서, 중앙값이 맞는지 아닌지 T/F가 되는 지점이 딱 구분되므로
    // 이진 탐색을 통해 O(q logn)으로 찾을 수 있다.

    for(int i=0; i<q; i++) {
        int mi;
        cin >> mi;

        // 예외 처리 : 주어진 연비 외에 값을 mi로 입력한 경우
        int idx = binary_search(cars, mi);
        if (idx == -1) {
            cout << 0 << '\n';
        } else {
            int ans = idx * ((n-1) - idx);
            cout << ans << '\n';
        }
    }
}

int binary_search(const vector<int>& cars, int mi) {
    //효율성을 위해 vector<int>를 값 복사 대신 참조로 전달
    int left=0, right=cars.size();
    
    while(left < right) {
        int mid = (left+right)/2;
        if (cars[mid] == mi)
            return mid;
        else if (cars[mid] < mi)
            left = mid + 1;
        else if (cars[mid] > mi)
            right = mid;
    }
    return -1; // 주어진 연비 외의 값을 mi로 지정한 경우
}