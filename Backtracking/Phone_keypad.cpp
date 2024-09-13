#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void find(vector<string>& answer, string& current, int index, string& digits, string map[]) {
        if (index >= digits.length()) {
            answer.push_back(current);
            return;
        }
        
        int store = digits[index] - '0'; 
        string value = map[store];
        
        for (char c : value) {
            current.push_back(c);
            cout << current << endl;
            find(answer, current, index + 1, digits, map);
            cout << "POP" << endl;
            current.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string current;
        int index = 0;
        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if (digits.empty()) {
            return answer;
        }
        
        find(answer, current, index, digits, map);
        
        return answer;
    }
};

int main() {
    Solution sol;
    
    // Example usage:
    string digits = "23";
    vector<string> combinations = sol.letterCombinations(digits);
    
    // Output the combinations
    cout << "Letter combinations for digits " << digits << ":" << endl;
    for (string comb : combinations) {
        cout << comb << " ";
    }
    cout << endl;
    
    return 0;
}
