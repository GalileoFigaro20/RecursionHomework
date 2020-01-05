#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int H(int x, int n)
{
    if(n == 0)
        return 1;
    else if(n == 1)
        return 2*x;
    else return 2*n*H(x, n-1) - 2*(n-1)*H(x, n-2);
}

int HH(int x, int n)
{
    int hn_1 = 1, hn = 2*x, aux;
    for(int i = 1; i < n; i++)
    {
        aux = hn;
        hn = 2*(i+1)*hn - 2*(i)*hn_1;
        hn_1 = aux;
    }
    return hn;
}

int main()
{
    printf("%d\n%d", H(1,2), HH(1,2));
}
