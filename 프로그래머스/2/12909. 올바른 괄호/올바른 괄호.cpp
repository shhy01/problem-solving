#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> check_pair;
    for(char temp : s) {
        if (temp == '(') {
            check_pair.push(temp);
        }
        else {
            if (!check_pair.empty() && check_pair.top() == '(') {
                check_pair.pop();
            }
            else {
                return false; //짝이 맞지 않다면 false.
            }
        }
    }
    
    return check_pair.empty(); //모든 짝이 맞아 스택이 비어있다면 true.
}