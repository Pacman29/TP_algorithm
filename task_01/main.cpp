/*
 * ​Дано натуральное число N. Представить N в виде A + B, так, что НОД(A, B) максимален, A ≤ B.
 * Вывести A и B. Если возможно несколько ответов ­ вывести ответ с минимальным A.n ≤ 10^7
*/
#include <cstdio>
int get(int n)
{
    for(int p = 2; p*p<n;++p)
        if(!(n%p))
            return p;
    return n;
}

int main(void)
{
    int n = 0;
    if(scanf("%d",&n) == 1)
    {    
        int tmp = n/get(n);
        printf("%d %d",tmp ,n - tmp);
    }
    return 0;
}

//ivanov.georg@gmail.com;

