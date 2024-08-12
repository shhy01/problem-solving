#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++) {
        vector<int> sub_array;
        for(int j=commands[i][0] - 1 ; j<commands[i][1]; j++) {
            sub_array.push_back(array[j]);
        }
        sort(sub_array.begin(), sub_array.end());
        answer.push_back(sub_array.at(commands[i][2]-1));
    }
    return answer;
}