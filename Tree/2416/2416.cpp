#include <vector>
#include <iostream>
#include <string>

const int ALPHABET_SIZE = 26;

struct Trie{
    Trie* ch[26] = {};
    int cnt = 0;
    void insert(std::string s){
        Trie* cur = this;
        for(const char c : s){
            int i = c - 'a';
            if(!cur->ch[i])
                cur->ch[i] = new Trie();
            cur = cur->ch[i];
            cur->cnt++;
        }
    }
    int query(std::string s){
        Trie* cur = this;
        int ans = 0;
        for(const char c : s){
            cur = cur->ch[c - 'a'];
            ans += cur->cnt;
        }
        return ans;
    }
};
class Solution {
public:
    std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
        Trie* root = new Trie();
        for (const std::string& w : words)
            root->insert(w);
        std::vector<int> ans;
        for(const std::string& w : words)
        ans.push_back(root->query(w));
        return ans;
    }
};
int main()
{
    std::vector<std::string> words = {
        std::string("abc"),
        std::string("ab"),
        std::string("bc"),
        std::string("b")
    };

    Solution* S = new Solution;
    std::vector<int> ans = S->sumPrefixScores(words);

    for (const int& a : ans){
        std::cout << a << " ";
    }
    std::cout << '\n';
    return 0;
    
}