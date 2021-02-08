#使用变量和通配符的makefile
cc := gcc -Wall
DectoHexStr : DectoHexStr.o
	$(cc) -o $@ $<
%.o : %.c
	$(cc) -c $<
.PHONY : clean
clean :
	rm DectoHexStr *.o
