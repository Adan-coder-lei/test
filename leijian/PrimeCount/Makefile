#只使用显式规则的简单makefile
#显式规则：
#目标文件：依赖文件
#[Tab]指令
PrimeCount : PrimeCount.o
	gcc -Wall -o PrimeCount PrimeCount.o -lm
PrimeCount.o : PrimeCount.c
	gcc -Wall -c PrimeCount.c
.PHONY : clean
clean:
	rm PrimeCount PrimeCount.o