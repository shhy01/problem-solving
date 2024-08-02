#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> map;
    for(auto num: nums) {
        map[num] += 1;
    }
    
    return min(map.size(), nums.size()/2);
}