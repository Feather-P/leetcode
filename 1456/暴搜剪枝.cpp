#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool isVowel(char n){
        unordered_set<char> vowels = 
        {'a', 'e', 'i', 'o', 'u'};
        return vowels.count(n) > 0;
    }
    int maxVowels(string s, int k) {
        int max = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i] == false)) continue;
            else {
                int tmp = 0;
                for(int j = i; j < i + k; j++){
                    if (j >= s.size()) continue;
                    if(isVowel(s[j])){
                        tmp++;
                        if(tmp > max) {
                            max = tmp;
                        }
                    }
                }
            }
        }
        return max;
    }
};