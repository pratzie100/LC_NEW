#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> getWordsInLongestSubsequence(int n, std::vector<std::string>& words, std::vector<int>& groups) {
        std::vector<int> wordLengths(n, 1);
        std::vector<int> predecessors(n, 0);

        std::vector<std::vector<int>> wordDifferences(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int differenceCount = 0;
                if (words[i].size() == words[j].size()) {
                    for (int k = 0; k < words[i].size(); k++) {
                        if (words[i][k] != words[j][k]) {
                            differenceCount++;
                        }
                    }
                    wordDifferences[i][j] = differenceCount;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            predecessors[i] = i;
            for (int prevIdx = 0; prevIdx < i; prevIdx++) {
                if (groups[prevIdx] != groups[i] && words[i].size() == words[prevIdx].size() && wordDifferences[i][prevIdx] == 1 && 1 + wordLengths[prevIdx] > wordLengths[i]) {
                    wordLengths[i] = 1 + wordLengths[prevIdx];
                    predecessors[i] = prevIdx;
                }
            }
        }

        int maxSubsequenceLength = 0;
        int maxSubsequenceIdx = 0;

        for (int i = 0; i < n; i++) {
            if (wordLengths[i] > maxSubsequenceLength) {
                maxSubsequenceLength = wordLengths[i];
                maxSubsequenceIdx = i;
            }
        }

        std::vector<std::string> result;
        while (maxSubsequenceLength > 0) {
            result.push_back(words[maxSubsequenceIdx]);
            maxSubsequenceIdx = predecessors[maxSubsequenceIdx];
            maxSubsequenceLength--;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
