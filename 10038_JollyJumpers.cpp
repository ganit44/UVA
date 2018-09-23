#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <climits>

std::vector<bool> v1;

int main()
{
    int input, i, n, prev;

    v1.resize(UINT_MAX);

    bool missing = false;

    while(std::cin >> n)
    {
        std::cin >> prev;

        v1.assign(n, false);

        missing = false;

        for(i=1; i<n; i++)
        {
            std::cin >> input;

            v1[(unsigned int)abs(input - prev)] = true;

            prev = input;
        }

        for(i=1; i<= n-1; i++)
        {
            if(v1[i] == false)
            {
                missing = true;
                break;
            }
        }

        if(missing == false)
            std::cout << "Jolly\n";
        else
            std::cout << "Not jolly\n";
    }
}
