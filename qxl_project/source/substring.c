#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>

/****************************************************
函数名：primeNum（）
功能：判断needle是否为haystack的子串
输入参数：两个字符串
返回值：bool
*****************************************************/
bool subString(char * haystack, char * needle)
{
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    int temp;
    int i;

    if (* needle == 0) {
        return false;
    }

    if (* haystack == 0) {
        return false;
    }

    for (i=0;i<haystackLen; i++) {
        temp = i;
        int j = 0;
        while(haystack[temp++] == needle[j++]){
            if (j == needleLen) {
            return true;
            }
        }
    }
    return false;
}
