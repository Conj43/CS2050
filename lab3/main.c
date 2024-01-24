#include"lab3.h"
int main(void)
{
    char*source;
    char*dest;
    source = strAlloc(11);
    dest = strAlloc(11);

    char * staticSource = {"HELLOHELLO"};
    char * staticDest = {"ABCDEFGHIJ"};
    for (int i = 0; i<11; i++)
    {
        source[i] = staticSource[i];
        dest[i] = staticDest[i];
    }

    printf("The size of source is %d\n", strLen(source));
    printf("The size of dest is %d\n", strLen(dest));

    printf("Here is the source string: ");
    for(int i = 0; i<11; i++)
    {
        printf("%c", source[i]);
    }
    printf("\n");
    printf("Here is the dest string: ");
    for(int i = 0; i<11; i++)
    {
        printf("%c", dest[i]);
    }
    printf("\n");

    strCpy(source, dest);

    printf("Here is the source string after copying: ");
    for(int i = 0; i<11; i++)
    {
        printf("%c", source[i]);
    }
    printf("\n");
    printf("Here is the dest string after copying: ");
    for(int i = 0; i<11; i++)
    {
        printf("%c", dest[i]);
    }
    printf("\n");
    printf("Return value for strcmp is %d\n", strCmp(source, dest));
/*
    printf("This is the return value of strcmp: %d", strCmp(source, dest));
*/
    strFree(source);
    strFree(dest);


}