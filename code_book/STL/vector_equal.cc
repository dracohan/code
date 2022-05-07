#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> v1 = { 1, 2, 3, 5, 4, 5 };
    std::vector<int> v2 = { 1, 2, 3, 5, 4, 5 };
 
    if (v1 == v2) {
        std::cout << "Both vectors are equal" << std::endl;
    }
    else {
        std::cout << "Both vectors are not equal" << std::endl;
    }
 
    return 0;
}