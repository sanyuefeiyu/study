#include <stdio.h>

static void create_btree(int list[], int bt[], int n) /*n��ʾlist������Ԫ�صĸ���*/
{
    int i, order;

    bt[1] = list[0];
    for (i = 1; i < n; i++)
    {
        order = 1; /*ÿ�ν����Ӹ���㿪ʼ�Ƚ�*/
        while (bt[order] != 0)
        {
            if (list[i] < bt[order])
                order *= 2;
            else
                order = order * 2 + 1;
        }
        bt[order] = list[i];
    }
}

int TestCreateBtreeByArr()
{
    int list[7] = { 30, 18, 16, 25, 34, 7, 31 };
    int bt[16] = { 0 };
    int i;

    create_btree(list, bt, 7);
    for (i = 0; i < 16; i++) /*�������*/
        //if (bt[i] != 0)
        printf("%4d", bt[i]);
    printf("\n");

    return 0;
}
