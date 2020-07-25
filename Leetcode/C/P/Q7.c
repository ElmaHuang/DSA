/*
5. 求第九個bit值是多少
ex : int a = 0xfafc; //print 0
return （a >> 8）&1;
*/

#include <stdio.h>
 
int main()
{
    int a;
    printf("enter Hex val : ");
    scanf("%x", &a);
    a = (a>>8) & 1;
    printf("print 9 bit: %d", a);
    return 0;
}
