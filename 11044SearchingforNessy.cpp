#include <iostream>
#include <cmath>

int main()
{
    int t;
    int m, n;

    std::cin >> t;

    while(t--)
    {
        std::cin >> m >> n;

        m = m - 2;
        n = n - 2;

        std::cout <<  (int)(ceil((double)n/3) * ceil((double)m/3)) << std::endl;
    }
}
