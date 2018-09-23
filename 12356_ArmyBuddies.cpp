#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int,int>> v1;


int main()
{
    int n, b, i;
    int input1, input2;
    const int MAXM = 100002;


    v1.resize(MAXM);

    while(std::cin >> n >> b)
    {
        if (n == 0 && b == 0)
            break;

        for (i=1;i<=n;i++)
        {
            v1[i] = std::make_pair(i-1, i+1);
        }        

        v1[0] = std::make_pair(0,0);
        v1[n+1] = std::make_pair(0,0);

        for (i=0; i<b; i++)
        {
            std::cin >> input1 >> input2;

            //Both L and R and all others in b/w them are killed

            //L's left's right is now R's right
            v1[v1[input1].first].second = v1[input2].second;

            //R's right's left is now L's left
            v1[v1[input2].second].first = v1[input1].first;


            if(v1[input1].first >= 1 && v1[input1].first <= n)
                std::cout << v1[input1].first;
            else
                std::cout << "*";

            std::cout << " ";

            if(v1[input2].second >= 1 && v1[input2].second <= n)
                std::cout << v1[input2].second << std::endl;
            else
                std::cout << "*\n";

        }

        std::cout << "-\n";

    }
}


