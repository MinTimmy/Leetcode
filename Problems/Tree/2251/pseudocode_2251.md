# Peseudocode
[problem link](https://leetcode.com/problems/number-of-flowers-in-full-bloom/)
[answer link](https://zxi.mytechroad.com/blog/category/tree/)

```
procedure Solution_1( .. ) {
    Input:  ...
    Output: ...

   
}


```


Input: flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
Output: [1,2,2,2]

```c++
for (const auto& f : flowers)
    ++m[f[0]], --m[f[1]+1];
```
|m->first    |m->second|
|------------|---------|
|0           |0|
|1           |1|
|2           |0|
|3           |1|
|4           |0|
|5           |1|
|6           |0|
|7           |-1|
|8           |-1|
|9           |1|
|10          |0|
|11          |0|
|12          |0|
|13          |-1|
|14          |-1|
===============================
```c++
for(std::map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    iter->second = sum += iter->second;
```
|m->first    |m->second|
|-----------|----------|
|0           |0|
|1           |1|
|2           |1|
|3           |2|
|4           |3|
|5           |2|
|6           |2|
|7           |2|
|8           |1|
|9           |2|
|10          |2|
|11          |2|
|12          |2|
|13          |1|
|14          |0|

```c++
for (int t : persons)
    ans.push_back(std::prev(m.upper_bound(t)) -> second);
```

|m->first    |m->second|
|-----------|----------|
|0           |0|
|1           |1|
|**2**         |  **1**|
|**3**         |  **2**|
|4           |3|
|5           |2|
|6           |2|
|**7**         |  **2**|
|8           |1|
|9           |2|
|10          |2|
|**11**        |  **2**|
|12          |2|
|13          |1|
|14          |0|