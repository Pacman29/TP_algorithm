/*
 * Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков
 * пирамиду.
 * Формат входных данных: На вход подается количество кубиков N.
 * Формат выходных данных: Вывести число различных пирамид из N кубиков.
 * 6_1.​ Высокая пирамида. ​Каждый вышележащий слой пирамиды должен быть не больше нижележащего.
 * N ≤ 200.
 */

#include <cstdio>
#include <cstdlib>

long long int** createCached(int n)
{
    long long int** result = (long long int**)malloc(sizeof(long long int*)*n);
    for(int i = 0; i<n; ++i)
        result[i] = (long long int*)malloc(sizeof(long long int)*n);
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            result[i][j] = -1;
    return result;
}

void deleteCached(long long int** memory,int n)
{
    for(int i = 0; i<n; ++i)
        free(memory[i]);
    free(memory);
}

long long int high_Pyramid(int current_n, int cubes,long long  int** cache)
{
    long long int sum = 0;
    for(int new_layer = current_n; new_layer <= cubes; ++new_layer)
    {
        int remainingCubes = cubes - new_layer;
        if(!remainingCubes || remainingCubes == new_layer)
            sum++;
        else
            if (remainingCubes > new_layer)
            {
               long long int cached = cache[new_layer][remainingCubes];
               if(cached == -1)
               {
                   cached = high_Pyramid(new_layer,remainingCubes,cache);
                   cache[new_layer][remainingCubes] = cached;
               }
               sum+= cached;
            }
    }
    return sum;

}

long long int calculate_high_Pyramyd(int n)
{
    if(!n)
        return 0;

    long long int** cache = createCached(n);
    long long int sum = 1;
    for(int i = 1; i<n; ++i)
        sum += high_Pyramid(i,n-i,cache);
    deleteCached(cache,n);
    return sum;
}

int main(void)
{
    int n = 0;
    if(scanf("%d",&n) != 1)
        return 1;
    printf("%lld",calculate_high_Pyramyd(n));
    return 0;
}
