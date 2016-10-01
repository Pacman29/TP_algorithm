/*
 * ​Дан массив целых чисел А[0..n­1]. Известно, что на интервале [0, m] значения массива строго
 * возрастают, а на интервале [m, n­1] строго убывают. Найти m за O(log m). 2 ≤ n ≤ 10000.
 */
#include <cstdio>
#include <cstdlib>

int bin_search(int left,int right, int *a, int flag)
{
    int mid = 0;
    while(left<=right)
    {
        if( !(left-1) && a[left-1] > a[left])
            return left-1;
        if( flag && a[right]>a[right-1])
            return right;
        mid = (left+right)/2;

        if(a[mid]>a[mid-1] && a[mid] > a[mid+1])
            return mid;
        else
            if(a[mid-1] > a[mid+1])
                right = mid-1;
            else
                left = mid+1;
    }
    return -1;
}

int search(int *a, int n)
{
    int rez = 0;
    int left = 1, right = 2;
    int flag = 0;
    while(left<=n && right <=n)
        if((rez = bin_search(left,right,a,flag)) != -1)
            return rez;
        else
        {
            left *= 2;
            right *= 2;
            if(right > n)
            {
                right = n-1;
                flag = 1;
            }
        }
    return 0;
}


int main(void)
{
    int n = 0;
    if(scanf("%d",&n)!=1)
        return 0;
    int *a = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; ++i)
        if(scanf("%d",a+i)!=1)
            return 0;

    printf("%d",search(a,n));
    free(a);
    return 0;
}
