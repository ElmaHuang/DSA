/*
https://www.cnblogs.com/oomusou/archive/2011/02/16/bit_control.html
https://openhome.cc/Gossip/CGossip/Datatype.html
型態            大小（bytes）
short           2
int             4
long            4
float           4
double          8
long double     12
char            1

3. 寫function 把某個數的第x個bit改成1或0 
(改成1直接用or、改成0用mask 之後and)
*/
#include <stdio.h>
#define MASK 0x2 //change bit 1 //0010

//.Q5 100
int main(int argc, char *argv[])
{
	//int val = 100;
	int val = argv[1];
	//set 1
	val |= MASK;
	//set 0
	val &= ~MASK;
	return val;
}