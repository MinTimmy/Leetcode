
[problem link](https://leetcode.com/problems/check-distances-between-same-letters/)
[answer link](https://zxi.mytechroad.com/blog/category/hashtable/)

```
function Sloution(s, distance)
    Input: string s, consisting of only lowercase English letters, where each letter in s appears exactly twice; list distance the number of letters between the two occurrences of the ith letter
    Output: Return true if s is a well-spaced string, otherwise return false.

    m = [-1, -1, ... , -1](list containing 26 -1s)
    len is the length of string s
    for i=0 upto len:
        c = s[i]
        if(m[c] >= 0 && i - m[c] - 1 != distance[c]) return false
        m[c] = i
    return true
```