//https://www.acmicpc.net/problem/18870

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N), sorted_nums(N);
    map<int, int> nums_zip;

    for(int i=0; i<N; i++) {
        cin >> nums[i]; // 입력 값을 순서대로 받는 벡터 nums
        sorted_nums[i] = nums[i]; // 이후 입력 값을 오름차순으로 정렬할 벡터 sorted_nums
    }
    sort(sorted_nums.begin(), sorted_nums.end()); //sorted_nums 오름차순 정렬

    int k=0;
    for(int i=0; i<N; i++) {
        //sorted_nums 중 중복 값을 고려하여, {기존 입력 숫자값 sorted_nums[i], 좌표 압축 값 k(순서)} 형식의 map
        if(nums_zip.find(sorted_nums[i]) != nums_zip.end()) continue; 
        nums_zip.insert({sorted_nums[i], k});
        k++;
    }

    for(int i=0; i<N; i++) {
        //입력받은 순서대로, 입력값(key)에 맞는 좌표 압축 값 k(value)를 출력한다.
        cout << nums_zip[nums[i]] << ' ';
    }

    return 0;
}