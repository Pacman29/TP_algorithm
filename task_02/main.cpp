#include <cstdio>
#include <cstdlib>
/*
 * ​Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k.
 * Найти количество таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
 * n, m ≤ 100000.
 * Указание. Обходите массив B от конца к началу.
 */
int get_numb(int *a,int n, int *b, int m,int k)
{
    int i = 0,  j = m-1, rez = 0;
    while(i != n && j != -1)
    {
        if(a[i] + b[j] == k)
        {
            i++;
            j--;
            rez++;
        }
        else
            if(a[i]+b[j] < k)
                i++;
            else
                j--;
    }
    return rez;
}

int main(void)
{
    int n = 0,m = 0,k = 0;
    int *a = NULL, *b = NULL;

    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n;++i)
        scanf("%d",a+i);
    scanf("%d",&m);
    b = (int*)malloc(m*sizeof(int));
    for(int i = 0; i<m;++i)
        scanf("%d",b+i);

    scanf("%d",&k);
    printf("%d",get_numb(a,n,b,m,k));
    free(a);
    free(b);
    return 0;
}
