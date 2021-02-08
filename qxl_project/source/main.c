#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "homework.h"


int main()
{
    printf("请选择需要验证的功能 ：\n");
    printf("1.判断一个是是否为素数  ：\n");
    printf("2.判断 s 是否为 t 的子序列 ：\n");
    printf("3.将一个10进制整数转换为16进制数 ：\n");

    int select;
    scanf("%d",&select);

    switch(select) {

        case 1:{
            int maxNum;
            printf("请输入一个正整数\n");
            maxNum=isInt();
            int ret = primeNum(maxNum);
            printf("There are %d primes within %d\n",ret,maxNum);
            printf("\n");
            break;
        }

        case 2: {
            char t[128] ;
            char s[128] ;
            printf("请输入一个字符串和他的子字符串:\n");
            scanf("%s%s",&t,&s);

            if(subString(t,s)) {
                printf("string %s is the substring of string %s\n",s,t);
            } else {
                printf("string %s is not the substring of string %s\n",s,t);
            }
            break;
        }

        case 3:{
            printf("请输入一个整数\n");
            int ten ;
            ten = cheakInput();
            char * a = tenTosixteen(ten);
            printf("十进制数%d转换为十六进制为0x%s \n",ten,a);
            //printf("十进制数%d转换为十六进制为0x%x \n",ten,ten);
            break;
            }

        default:printf("error\n");
         }

    return 0;
}
