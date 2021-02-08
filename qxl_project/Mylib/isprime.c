#include <stdio.h>
#include<string.h>
#include <stdbool.h>

/****************************************************
函数名：isPrime（）
功能：判读一个数是否为素数
输入参数：需要判断的数
返回值：bool
*****************************************************/
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    int i;
    for (i = 2; i< num; i++) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}

/****************************************************
函数名：primeNum（）
功能：找出n以内素数的个数
输入参数：最大需要判断的数
返回值：素数的个数
*****************************************************/
int primeNum(int n)
{
    int i,count=0;
    for (i = 0; i < n; i++){
        if (isPrime(i)) {
          //  printf("%d is a prime\n",i);
            count ++;
        }
    }
    return count;
}
