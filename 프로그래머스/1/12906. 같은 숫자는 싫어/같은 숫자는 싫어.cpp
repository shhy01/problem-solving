#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int temp = arr[0];
    answer.push_back(temp);
    for(auto num : arr) {
        if (temp != num) {
            answer.push_back(num);
            temp = num;
        }
    }
    return answer;
}