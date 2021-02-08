#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/****************************************************
函数名：bool num(char  *str)
功能：判读一个字符串是否为数字
输入参数：需要判断的数
返回值：bool
*****************************************************/
bool num(char  *str)
{
    int flag = 1,i;

    for ( i = 0; i < strlen(str); i++ )
    {
        if ( str[i] >= '0' && str[i] <='9' ) {
            continue;
        } else {
            flag = 0;
            break;
        }
    }

    if ( flag == 0 ) {
        return false;
    } else {
        return true;
    }
}

/****************************************************
函数名：int atoi1(char *str)
功能：讲字符串转化为数字
输入参数：需要判断的字符串
返回值：返回转化后的数字
*****************************************************/
int atoi1(char *str)
{
    int value = 0;

    while (*str>='0' && *str<='9' )
    {
         value *= 10;
         value += *str - '0';
         str++;
     }
     return value;
}

/****************************************************
函数名：int isInt()
功能：校验输入的字符串，并将全为数字的字符串转化为数字
输入参数：需要判断的字符串
返回值：返回转化后的数字
*****************************************************/
int isInt()
{
    char c[100];
    scanf("%s",c);

    if ( num(c) ) {
        return atoi1(c);
    } else {
        printf("输入非法,请输入一个大于0的整数\n");
        isInt();
    }
}

/****************************************************
函数名：int isInt()
功能：从输入中接受一个数判断是否为整数
输入参数：需要判断的字符串
返回值：返回转化后的数字
*****************************************************/
int cheakInput()
{
    int num;

    setbuf(stdin, NULL);  //清空输入缓存

    if (scanf("%d",&num) != 0) {
        return num;
    } else {
        printf("输入非法,请输入一个的整数\n");
        cheakInput();
    }
}
