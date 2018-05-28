#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>  // 使用abs
#include<string.h>  // 使用memset

bool Place(int a, int b, int *result)  // 判断两个皇后是否在同一列或同一斜线上
{
    for (int i = 0; i < a; i++)  // 遍历之前的每一行
        if (result[i] == b || (abs(result[i] - b) == abs(i - a)))  // 如果列相同,或者行和行的差与列和列的差相同,则失败
            return false;
    return true;
}

void NQueens(int a, int b, int *result)  // a行b列
{
    for (int i = 0; i < b; i++)  // 遍历该行每一列
    {
        if (Place(a, i, result))  // 如果可以放置  约束函数
        {
            result[a] = i;
            if (a == b - 1)  // 到达最后一行
            {
                for (int i = 0; i < b; i++)
                    printf("%d ", result[i]);  // 输出结果
                printf("\n");
            }
            else NQueens(a + 1, b, result);  // 深度优先进入下一层
        }
    }
}

int main()
{
    int n;  // n皇后
    scanf("%d", &n);
    int result[n];  // n 表示行数, result[n] 表示列
    memset(result, 0, sizeof(int)*n);  // 初始化
    NQueens(0, n, result);
    return 0;
}
