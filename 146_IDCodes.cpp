#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string s1;
    while(std::cin >> s1)
    {
        if(s1 == "#")
            break;


        if(std::next_permutation(s1.begin(), s1.end()))
            std::cout << s1 << "\n";
        else
            std::cout << "No Successor\n"; 

    }
}


