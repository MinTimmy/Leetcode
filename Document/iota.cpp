// std::iota  Store increasing sequence 

#include <iostream> // std::cout 
#include <numeric> // std::iota 
  
// Driver code 
int main() 
{ 
    int numbers[10]; 
    // Initailising starting value as 100 
    int st = 100; 
  
    std::iota(numbers, numbers + 10, st); 
  
    std::cout << "Elements are:"; 
    for (auto i:numbers) 
        std::cout << ' ' << i; 
    // Output: Elements are: 100 101 102 103 104 105 106 107 108 109
    std::cout << '\n'; 
  
    return 0; 
}