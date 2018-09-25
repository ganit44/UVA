#include <iostream>
#include <vector>
#include <utility>

char a[10005][10005];
char b[10005][10005]; 

const int MAXM = 10005;

void printSmall(char s[MAXM][MAXM], int sN)
{
    int i, j;
    for(i = 0; i<sN; i++)
    {
        for(j=0;j<sN;j++)
        {
            std::cout << s[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}

int compareAndPrint(char b[MAXM][MAXM], char s[MAXM][MAXM], int bN, int sN)
{
    int upto = bN-sN;
    int matched=0;
    int i,j,p,q;
    bool matching = true;
    //row
    //
    //std::cout << bN << sN << upto;

    for(i=0; i<=upto; i++)
    {
        //column
        for(j=0; j<=upto; j++)
        {
            //compare
            matching = true;
            for(p=i;p<i+sN;p++)
            {
                for(q=j;q<j+sN;q++)
                {
                    //std::cout << p << q << p-i << q-j << std::endl;

                    if(b[p][q] != s[p-i][q-j])
                        matching = false;
                }
            } 
            if(matching == true)
                ++matched;
        }
    }

    return matched;
}

void rotateBy90(char m[MAXM][MAXM], int sN)
{
    int i,j;

    //transpose
    for(i=0; i<sN; i++)
    {
        for(j=i; j<sN; j++)
        {
            std::swap(m[i][j], m[j][i]);
        } 
    }

    //printSmall(m, sN);
    // AB   -> AC  -> CA
    // CD      BD     DB
    // Orig -> Trans -> reverse each row
  
    for(i=0;i<sN;i++)
    {
        for(j=0;j<sN/2;j++)
        {
            std::swap(m[i][j], m[i][sN-1-j]);
        }
    }

    //printSmall(m, sN);

}

int main()
{
    int i, j, bigN, smallN;

    while(std::cin >> bigN >> smallN)
    {
        if(bigN == 0 && smallN == 0)
            break;

        for(i=0; i<bigN; i++)
            for(j=0; j< bigN; j++)
                std::cin >> a[i][j];

        for(i=0; i<smallN; i++)
            for(j=0; j<smallN; j++)
                std::cin >> b[i][j];

        //printSmall(b, smallN);

        std::cout << compareAndPrint(a, b, bigN, smallN) << " ";

        rotateBy90(b, smallN);

        //printSmall(b, smallN);

        std::cout << compareAndPrint(a, b, bigN, smallN) << " ";
        
        rotateBy90(b, smallN);

        //printSmall(b, smallN);

        std::cout << compareAndPrint(a, b, bigN, smallN) << " ";
        
        rotateBy90(b, smallN);

        //printSmall(b, smallN);

        std::cout << compareAndPrint(a, b, bigN, smallN) << "\n";
    }
}

