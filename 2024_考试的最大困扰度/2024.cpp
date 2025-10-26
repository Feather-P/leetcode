#include <string>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int max_length_t = 0;
        int max_length_f = 0;
        int current_length = 0;
        int left = 0;
        int limit = k;
        for (int right = 0; right < answerKey.size(); right++) {
            // 先计算T:
            if (answerKey.at(right) != 'T') {
                limit--;
            }
            current_length++;
            while (limit < 0) {
                if (answerKey.at(left) != 'T') {
                    limit++;
                }
                current_length--;
                left++;
            }
            max_length_t = max(max_length_t, current_length);
        }

        left = 0;
        current_length = 0;
        limit = k;
        for (int right = 0; right < answerKey.size(); right++) {
            // 再计算T:
            if (answerKey.at(right) != 'F') {
                limit--;
            }
            current_length++;
            while (limit < 0) {
                if (answerKey.at(left) != 'F') {
                    limit++;
                }
                current_length--;
                left++;
            }
            max_length_t = max(max_length_t, current_length);
        }
        
        return max(max_length_f, max_length_t);
    }
};