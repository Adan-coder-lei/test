/*
 *Author  ： leijian
 *Date    :  2020/12/23

 *题目描述：
 *给定字符串 s 和 t ，判断 s 是否为 t 的子序列；
 *字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
 *（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 *示例：
 *输入：s = "abc", t = "ahbgdc"
 *输出：true
 *输入：s = "axc", t = "ahbgdc"
 *输出：false
 *提示：
 *0 <= s.length <= 100
 *0 <= t.length <= 10^4
 *两个字符串都只由小写字符组成。
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//读取长短字符串的最大内存
#define SHORT 105
#define LONG 10005

//需要的字符串最大长度
#define LEN_SHORT 100
#define LEN_LONG 10000

bool Subsequence(const char* strsub, const char* str); //判断是否是子序列
bool InputValid(const char* str, int length);  //判断输入的字符串是否有效

int main()
{
	char strsub[SHORT];
	char str[LONG];

	printf("请按要求输入字符串strsub和str，判断strsub是否为str的子序列\n");
	printf("请输入字符串strsub:（全为小写字母字符且长度不超过100）\n");
	fgets(strsub,sizeof(strsub),stdin);
	printf("请输入字符串str:（全为小写字母字符且长度不超过10000）\n");
	fgets(str,sizeof(str),stdin);

	//字符串后如果有换行符'\n'，剔除
	if(strsub[strlen(strsub) - 1] == '\n') {
		strsub[strlen(strsub) - 1] = '\0';
	}
	if(str[strlen(str) - 1] == '\n') {
		str[strlen(str) - 1] = '\0';
	}

	bool StrsubValid = InputValid(strsub, LEN_SHORT);
	bool StrValid = InputValid(str, LEN_LONG);

	if(StrsubValid && StrValid) {  //两个字符串输入都是有效的
		if(Subsequence(strsub, str)) {
			printf("true\n字符串strsub是str的子序列\n");
		}
		else {
			printf("false\n字符串strsub不是str的子序列\n");
		}
	}

	//输入无效处理
	if(!StrsubValid) {
		printf("strsub字符串输入无效！请重新按照要求输入！注意不要输入除小写字母字符（a~z）之外的任何其他字符！输入不要超过100个字符！\n");
	}
	if(!StrValid) {
		printf("str字符串输入无效！请重新按照要求输入！注意不要输入除小写字母字符（a~z）之外的任何其他字符！输入不要超过100个字符！\n");
	}
	return 0;
}

bool Subsequence(const char* strsub, const char* str)
{
	if(NULL == strsub || NULL == str) {//预防传入的指针为空指针
		return false;
	}
	if(strlen(strsub) > strlen(str)) {//strsub长度比str长，strsub一定不是str的子序列
		return false;
	}

	while((*strsub != '\0') && (*str != '\0')) {  //遍历strsub和str字符串
		if(*strsub == *str) {
			strsub++;
			str++;
		}
		else {
			str++;
		}

	if(*strsub == '\0') //strsub遍历完了，不管str是否遍历完，strsub中的字符都有序出现在str中，strsub一定是str的子序列
		return true;
	return false;  //strsub还未遍历完，说明strsub不是str的子序列
}

bool InputValid(const char* str, int length)
{
	//指针非空判断和字符串长度判断
	if(NULL == str || strlen(str) > length) {
		return false;
	}

	while(*str != '\0') {
		if(islower(*str) == 0) {//读取的字符串有效内容并非全部小写字母，视为无效输入
			return false;
		}
		str++;
	}
	return true;
}