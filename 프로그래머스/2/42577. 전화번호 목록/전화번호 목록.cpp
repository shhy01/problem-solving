#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> map;
    for(auto people:phone_book)
        map[people]++;
    
    for(int i=0; i < phone_book.size(); i++) {
        string phone_number = "";
        for(int j=0; j<phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(map[phone_number] && phone_number != phone_book[i])
                return false;
        }
    }
    
    return true;
}