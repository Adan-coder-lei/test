/*
 *Author :   leijian
 *Date   :   2020/12/24

 *给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用补码运算方法。
 *注意:
 *十六进制中所有字母(a-f)都必须是小写。
 *十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。
 *给定的数确保在32位有符号整数范围内。
 *不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
 *输入:26
 *输出:"1a"
 *输入:-1
 *输出:"ffffffff"
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <assert.h>
#include <malloc.h>

#define MIN_NUM -2147483648  //32位有符号整数最小值
#define MAX_NUM 2147483647  //32位有符号整数最大值
#define NUM_LEN 15  //读取的字符串长度
#define INPUT_MAXLEN 11  //有效输入的最大字符个数
#define SIZE 9 //十六进制字符串大小

char* DectoHexStr(char* str, int num);    //将十进制数转换成一个十六进制字符串
bool InputCheck(const char* str, int length);   //输入是否有效检测

int main()
{
	char str[NUM_LEN];
	memset(str, 0, sizeof(str)); //初始化
	printf("请输入一个整数，要求在-2147483648~2147483647之间 ：\n");
	fgets(str,sizeof(str),stdin);

	//fgets读取的字符串后如果有换行符'\n'，剔除
	if(str[strlen(str) - 1] == '\n') {
		str[strlen(str) - 1] = '\0';
	}

	//给十六进制字符串分配内存空间
	char* StrHex = (char*)malloc(sizeof(char) * SIZE);
	if (NULL == StrHex) {
		return 0;
	}
	//assert(StrHex != NULL);
	//这里不建议使用assert

	//printf("malloc_usable_size(StrHex):%lu\n", malloc_usable_size(StrHex));
	//malloc_usable_size函数返回分配的内存空间大小，返回不一定等于需要的大小

	//bzero(StrHex,SIZE);
	memset(StrHex, 0, SIZE);  //字符串置零
	bool Input_Error = false;  //输入无效标志
	long int num = 0;

	if(InputCheck(str, INPUT_MAXLEN)) {
		num = atol(str);
		if((num < MIN_NUM) || (num > MAX_NUM)) {  //输入超出32位有符号整数的范围
			Input_Error = true;
		}
	}
	else {
		Input_Error = true;
	}

	if(!Input_Error) {
		DectoHexStr(StrHex, (int)num);
		printf("%s\n", StrHex);
	}
	else {
		printf("输入有误！请按照要求输入-2147483648~2147483647之间的整数！\n");
	}

	free(StrHex);
	StrHex = NULL;
	return 0;
}

bool InputCheck(const char* str, int length)
{
	if(NULL == str || strlen(str) > length || strlen(str) <= 0) {//长度不符合要求（空字符串也无效）
		return false;
	}
	if(*str == '-' || *str == '+') {//输入第一个字符可能是'-'、'+'
		str++;
	}

	while(*str != '\0') {
		if(isdigit(*str) == 0) {
			return false;
		}
		str++;
	}
	return true;
}

char* DectoHexStr(char* str, int num)
{
	//char* pHex = str;
	if(0 == num) {  //数字0特殊处理
		str[0] = '0';
		return str;
	}
	//使用数组模拟栈的功能
	int StackLike[SIZE];
	int top = 0;  //top指向下一入栈的位置

	unsigned int temp = (unsigned int)num;
	unsigned int NumOfHex = 15;
	int i;

	//每次取低四位的值，保存在“栈”中，“栈”顶的值为高位，应在字符串首
	for(i = 0; i < 8; i++) {
		StackLike[top++] = (temp & NumOfHex);
		temp >>= 4;
	}

	// 十六进制字符集
	char Hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

	top--;
	int k = 0;
	while(top != -1) {
		int cnt = StackLike[top--];
		if(cnt == 0 && k == 0)  //剔除十六进制的前导零
			continue;
		str[k++] = Hex[cnt];
	}
	return str;
}