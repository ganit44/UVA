#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int m,x;
    float down_payment, loan_amount, car_value, n, y;
    std::vector<std::pair<int, float>> v1;
    int month;
    float depreciation, installment;
    bool condition_met = false;

    while(1)
    {
        std::cin >> m >> down_payment >> loan_amount >> n;

        if(m < 0)
            break;

        v1.clear();

        while(n--)
        {
            std::cin >> x >> y;
            v1.push_back(std::make_pair(x,y));
        }

        condition_met = false; 
        month = 0;
 
        car_value = loan_amount + down_payment;
        installment = loan_amount/m; 

        for(auto iter = v1.begin(); iter != v1.end(); ++iter)
        {
            while(month <= iter->first)
            {
                if(month == iter->first)
                    depreciation = iter->second;
                car_value = car_value - (depreciation * car_value);
                if(month > 0) 
                    loan_amount = loan_amount - installment;
                if(loan_amount < car_value)
                {
                    condition_met = true;
                    break;
                }
                ++month;
            }

            if(condition_met == true)
                break;
        }

        while(loan_amount > car_value)
        {
                car_value = car_value - (depreciation * car_value);
                loan_amount = loan_amount - installment;
                if(loan_amount < car_value)
                    break;
                ++month;
        }

        std::cout << month << " month";
        if(month != 1)
            std::cout << "s";
        std::cout << std::endl;
    }
}
