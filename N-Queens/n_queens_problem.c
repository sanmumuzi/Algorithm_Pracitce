#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>  // ʹ��abs
#include<string.h>  // ʹ��memset

bool Place(int a, int b, int *result)  // �ж������ʺ��Ƿ���ͬһ�л�ͬһб����
{
    for (int i = 0; i < a; i++)  // ����֮ǰ��ÿһ��
        if (result[i] == b || (abs(result[i] - b) == abs(i - a)))  // �������ͬ,�����к��еĲ����к��еĲ���ͬ,��ʧ��
            return false;
    return true;
}

void NQueens(int a, int b, int *result)  // a��b��
{
    for (int i = 0; i < b; i++)  // ��������ÿһ��
    {
        if (Place(a, i, result))  // ������Է���  Լ������
        {
            result[a] = i;
            if (a == b - 1)  // �������һ��
            {
                for (int i = 0; i < b; i++)
                    printf("%d ", result[i]);  // ������
                printf("\n");
            }
            else NQueens(a + 1, b, result);  // ������Ƚ�����һ��
        }
    }
}

int main()
{
    int n;  // n�ʺ�
    scanf("%d", &n);
    int result[n];  // n ��ʾ����, result[n] ��ʾ��
    memset(result, 0, sizeof(int)*n);  // ��ʼ��
    NQueens(0, n, result);
    return 0;
}
