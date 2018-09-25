#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>

const unsigned long int MAXM = 1000001;

typedef enum Direction
{
    Left,
    Up,
    Right,
    Down
}Direction;

void changeDirection(Direction &d)
{
    if(d == Up)
        d = Left;
    else if(d == Left)
        d = Down;
    else if(d == Down)
        d = Right;
    else if(d == Right)
        d = Up;
}


std::pair<long int,long int> 
getNewCoordinates(std::pair<long int, long int> &old_cord, Direction &d1, long int step)
{
    if(d1 == Up)
    {
        return std::make_pair(old_cord.first+step, old_cord.second);
    } 
    else if(d1 == Left)
    {
        return std::make_pair(old_cord.first, old_cord.second-step);
    }
    else if(d1 == Down)
    {
        return std::make_pair(old_cord.first-step, old_cord.second);
    }
    else //d1 == Right
    {
        return std::make_pair(old_cord.first, old_cord.second+step);
    }

}

void PRINT_VECTOR(std::vector<std::tuple<long int, Direction, long int, long int>> &v)
{
    unsigned long int total = MAXM * 2 + 1;
    unsigned long int i;
    for(i=0; i<(int)MAXM*2; i++)
    {
        std::cout << std::get<0>(v[i]) << " COORD : " << std::get<1>(v[i]) << " " 
            << std::get<2>(v[i]) << " " << std::get<3>(v[i]) <<"\n";
    } 
    std::cout << "\n\n";
}

void setup(std::vector<std::tuple<long int, Direction, long int, long int>> &v1)
{
   unsigned long int total = (unsigned long int)MAXM * 2;
   Direction d;
   long int nextstep,step,i, pindex, number;
   std::pair<long int,long int> tp1;

   //v1[0] = std::make_tuple(1, (MAXM+1)/2, (MAXM+1)/2);

   tp1 = std::make_pair((MAXM+1)/2, (MAXM+1)/2);
   step = 0;
   d = Right; 
   pindex = 0;
   number = 1;

   for(i=0;i<total;i++)
   {
       //save tp1
       v1[pindex] = std::make_tuple(number, d, tp1.first, tp1.second);
       
       //change direction
       changeDirection(d); 
       if(d == Up || d == Down)
          step = step + 1;
      
       //get Next coordinates
       tp1 = getNewCoordinates(tp1, d, step); 
       number += step;  

       ++pindex;
   }

   //Last jump does not increment
   --std::get<0>(v1[pindex-1]);
   --std::get<2>(v1[pindex-1]);
}

bool IsNumberGreaterEqualTo(const std::tuple<long int, Direction, long int, long int> &p1,
                            const std::tuple<long int, Direction, long int, long int> &p2)
{
    return (std::get<0>(p1) < std::get<0>(p2));
}


std::tuple<long int, long int> 
getCorrectPosition(long int p, const std::tuple<long int, Direction, long int, long int> &tp) 
{
    long int number, x, y;
    Direction d;

    std::tie(number, d, x, y) = tp;

    if(d == Left)
    {
        y = y + (number - p);
    }
    else if(d == Up)
    {
        x = x - (number - p);
    }
    else if(d == Right)
    {
        y = y - (number -p);
    }
    else if(d == Down)
    {
        x = x + (number -p);
    }

    return std::make_tuple(x,y);
}

int main()
{
    long int sz, p, id, x, y, correction;
    unsigned long int total;
    std::vector<std::tuple<long int, Direction, long int, long int>> v1;

    std::vector<std::tuple<long int, Direction, long int, long int>>::iterator it;

    std::tuple<long int, Direction, long int, long int> tp;

    total = (unsigned long int)MAXM * 2;
    v1.reserve(total);

    //when using reserve, end will be same as begin

    setup(v1);
    
    //PRINT_VECTOR(v1);

    while(std::cin >> sz >> p)
    {
        if(sz==0 && p==0)
            break;

        tp = std::make_tuple(p, Up, 0, 0);

        it = std::lower_bound(v1.begin(), v1.begin() + total , tp, 
                                  IsNumberGreaterEqualTo) ;

        //std::cout << p << " : " << " " << std::get<0>(*it) << " " <<  std::get<1>(*it)
        //          << " " << std::get<2>(*it) << " " << std::get<3>(*it) <<'\n';


        correction = (MAXM - sz)/2;

        if(p == std::get<0>(*it))
        {
            std::cout << "Line = " << std::get<2>(*it) - correction << ", column = " << std::get<3>(*it) - correction << ".\n";
        }
        else // p is less that number
        {
            std::tie(x,y) = getCorrectPosition(p, *it);
            std::cout << "Line = " << x - correction << ", column = " << y - correction << ".\n";
        }
        
    } 
}

