#include<iostream>

int main()
{
    std::string s1;

    bool flag = false; 

    while(std::getline(std::cin, s1))
    {
       for(auto iter = s1.begin(); iter != s1.end(); ++iter)
       {
           if(*iter == '"')
           {
               if(flag == false)
                   std::cout << "``";
               else
                   std::cout << "''";
               flag = !flag;
           }
           else
               std::cout << *iter;
       }
        std::cout << std::endl; 
        s1.clear();
    }
}
