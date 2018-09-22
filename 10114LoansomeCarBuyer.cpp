#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int m,x;
    float down_payment, loan_amount, n, y;
    std::vector<std::pair<int, float>> v1;


    std::cin >> m >> down_payment >> loan_amount >> n;

    while(n--)
    {
        std::cin >> x >> y;
        v1.push_back(std::make_pair(x,y));
    }
}
