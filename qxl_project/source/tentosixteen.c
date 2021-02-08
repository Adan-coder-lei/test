#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>

/****************************************************
函数名：tenTosixteen(int num)
功能：将一个10进制数转换为16进制数
输入参数：int
返回值：返回一个字符串，表示转换之后的数
*****************************************************/
char * tenTosixteen(int num)
{
    unsigned int number = num;
    int count = 0;
    int i = 0;
    int sixteen = 16;
    char sixteenTable[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    char *changeNumber = (char *)malloc(sizeof(char)*10);//保存16进制数

    if (num == 0) {
        changeNumber[0]='0';
        changeNumber[1]='\0';
        return changeNumber;
    }

    while (number != 0) {
        int t = number%sixteen;
        changeNumber[count] = sixteenTable[t];
        number = number/sixteen;
        count++;
    }

    for (i = 0; i < count/2; i++) {
        char tmp;
        tmp = changeNumber[i];
        changeNumber[i] = changeNumber[count-1-i];
        changeNumber[count-1-i] = tmp;
    }

    changeNumber[count] = '\0';

    return changeNumber;
}
