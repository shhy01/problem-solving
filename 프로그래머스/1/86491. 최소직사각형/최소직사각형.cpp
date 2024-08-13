#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int num_1 = 0;
    int num_2 = 0;
    
    for(int i=0; i<sizes.size() ; i++) {
        num_1 = max(num_1, max(sizes[i][0], sizes[i][1]));
        num_2 = max(num_2, min(sizes[i][0], sizes[i][1]));
    }
    
    return num_1 * num_2;
}