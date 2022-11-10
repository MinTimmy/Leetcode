
[problem link](https://leetcode.com/problems/most-frequent-even-element/)
[answer link](https://zxi.mytechroad.com/blog/category/hashtable/)

```
function Sloution(nums)
    Input:  list nums, containing integers
    Output: Return the most frequent even element.

    m is unorder map
    integer ans, initialized as -1, is the finial most frequent even element
    integer best, initialized as 0, is the number of the most frequent even element
    
    for all element x in nums:
        if(x & 1) continue  // check whether x is odd or not
        cur = m[x] + 1
        if(cur > best):
            best = cur
            ans = x
        else if(cur == best && x < ans):
            ans = x
    
    return ans
```