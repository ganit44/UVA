#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>


void
PRINT_VECTOR(const std::vector<int> &v1)
{
    for(auto it = v1.begin(); it != v1.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

int main()
{
    int n, val;
    std::vector<int> v1;

    n = 0;
    bool odd = false;

    while(std::cin >> val)
    {
        v1.push_back(val);
        std::sort(v1.begin(), v1.end());

        //PRINT_VECTOR(v1);
        ++n;

        odd = !odd;

        if(odd) 
            std::cout << (long int) v1[((n-1)/2)];
        else  //even
            std::cout << (long int) (v1[n/2] + v1[(n/2) - 1])/2;

        std::cout << "\n";
    } 
}
