#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    int a[] = {2,0,0,2};
    std::vector<int> edges(a, a + sizeof(a) / sizeof(int));
    const int n = edges.size();
    std::vector<long> s(n);
    for (int i = 0; i < n; ++i)
      s[edges[i]] += i;

    std::cout << std::max_element(s.begin(), s.end()) - s.begin();
}