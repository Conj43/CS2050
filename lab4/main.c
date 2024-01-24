#include"lab4.h"
int main(void)
{
    InventoryItem array[5] = {{1, 56.76, 7, 2},
                             {2, 65.787, 6, 4},
                              {3, 65.876, 7, 4},
                             {4, 4353.65, 7, 4},
                              {5, 12.3, 6, 2},
    };

    InventoryItem * p = makeArray(5, sizeof(InventoryItem));
    for(int i = 0; i<5; i++)
    {
        p[i].ID = array[i].ID;
        p[i].weight = array[i].weight;
        p[i].stockCount = array[i].stockCount;
        p[i].colors = array[i].colors;
    }
    for(int i = 0; i<5; i++)
    {
        printf("ID[%d] = %d   ",i, p[i].ID);
        printf("weight[%d] = %.3f   ",i, p[i].weight);
        printf("stockCount[%d] = %d   ",i, p[i].stockCount);
        printf("colors[%d] = %d   ",i, p[i].colors);
        printf("\n");
    }
    printf("\n");
    printf("the size of the array is %d\n", getSize(p));
    printf("there are %d elements with a colorCount of 2\n", countWithColors(p, 2));
    freeArray(p);
}