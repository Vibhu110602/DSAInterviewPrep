class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        
        if (s.empty() || words.empty()) {
            return result;
        }
        
        int n = s.size();
        int m = words.size();
        int wordLen = words[0].size();
        int windowSize = m * wordLen;
        
        unordered_map<string, int> wordCount;
        
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> currentWindow;
            int wordsFound = 0;
            
            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;
                
                if (wordCount.find(word) != wordCount.end()) {
                    currentWindow[word]++;
                    wordsFound++;
                    
                    while (currentWindow[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentWindow[leftWord]--;
                        wordsFound--;
                        left += wordLen;
                    }
                    
                    if (wordsFound == m) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        currentWindow[leftWord]--;
                        wordsFound--;
                        left += wordLen;
                    }
                } else {
                    currentWindow.clear();
                    wordsFound = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};
