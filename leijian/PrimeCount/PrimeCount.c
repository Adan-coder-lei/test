/*
 *Author  ： leijian
 *Date    :  2020/12/22

 *题目描述：
 *输入一个正整数N（N < 2^32），输出 (0, N] 范围内的所有质数；
 *输入：n = 10
 *输出：4
 *解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 */

 #include <stdio.h>
 #include <stdbool.h>
 #include <math.h>
 #include <stdlib.h>
 #include <ctype.h>

 #define IPUT_MAX 4294967295  //允许输入的最大正整数，是一个十位的整数
 #define MAX_LEN 10   // 有效输入的最大正整数的位数
 #define SIZE 15  //字符串大小

 long long int InputCheck(const char* str);  //输入检测
 int PrimeCount(long long int n);  //统计(0,n]范围内的质数个数
 bool IsPrime(long long int k);  //判断k是否是质数
 void PrimePrint(long long int n); //打印范围内的各个质数

 int main()
{
	char str[SIZE]; //输入的正整数以字符串的形式保存
	//printf("%lu\n",sizeof(str));
	//size_t 64位是long unsigned int 类型

	printf("请用十进制的形式输入一个小于2^32(既 4294967296）的正整数，比如 100 ：\n");
	fgets(str,sizeof(str),stdin);
	//gets(str);
	//scanf("%s",str);

	// 这里使用scanf字符串不包含空格，使用gets警示危险。
	// 使用这两个函数，如果输入字符串很长，超出定义的数组长度，溢出
	// 这里使用fgets函数，能够提供一个长度保证，不允许输入除了十进制字符外的任何字符（包括空格）
	//fgets原型
	//char *fgets(char *s, int size, FILE *stream);

	int CountOfPrime = 0;  //统计质数个数
	long long int ret = InputCheck(str);  //输入检查的返回值

	if(ret != 0) {  //输入合理，统计区间内质数个数
		CountOfPrime = PrimeCount(ret);
		printf("(0,%lld]范围内的质数一共有%d个\n", ret, CountOfPrime);
		if(CountOfPrime != 0) {//打印范围内的各个质数
			PrimePrint(ret);
		}
	}
	else {  //输入检查的结果为0，视为不合理输入
		printf("输入错误！请按照要求重新输入！请不要输入除了十进制数字（0-9）外的任何字符，包括空格、其他进制数等！\n");
	}
	return 0;
}

 //字符串转整数，可以考虑库函数strtoul、strtol、atol、atoi
 //long int 在64位系统中占8字节，因此strtoul、strtol、atol是可以的，atoi范围不够
 long long int InputCheck(const char* str)
{
	//assert(str != NULL);
	if(NULL == str) {
		return 0;
	}

	long long int sum = 0;  //输入正整数的值
	int length = 0; //记录输入正整数的长度,使用了fgets暂不考虑strlen

	while(*str != '\0') {
		if(isdigit(*str)) { //输入的字符串中所有的字符必须是十进制数字字符，否则视为不合理输入
			sum = sum * 10 + (*str - '0');
		}
		else {
			if(*str == '\n') { //使用fgets，当输入较短时，会把输入的回车键'\n'也保存进字符串中
				str++;
				continue;
				//break;  //在这里字符串中出现\n可以看成是字符串结束了
			}
			return 0;
		}
		length++;
		if(length > MAX_LEN) {
			return 0;
		}
		str++;
	}

	if(sum > IPUT_MAX) //超出允许的最大正整数，视为不合理输入
		return 0;
	return sum;
}

int PrimeCount(long long int n)
{
	int count = 0;
    long long int i;
	for(i = 1; i <= n; i++) {
		if(IsPrime(i)) {  //在这里i是质数，可以打印，后面实现PrimePrint是为了贴合题目要求和使用体验
			count++;
		}
	}
	return count;
}

bool IsPrime(long long int k)
{
	if(k < 2) {
		return false;
	}
    long long int i;
	for(i = 2; i <= sqrt(k); i++) {  //这里使用了数学函数，在链接的时候要加上 -lm
		if(k % i == 0) {
			return false;
		}
	}
	return true;
}

void PrimePrint(long long int n)
{
	printf("它们是 ");
	long long int i;
	for(i = 2; i <= n; i++) {
		if(IsPrime(i)) {
			printf(" %lld",i);
		}
	}
	printf("\n");
}