main:main.o inputcheck.o substring.o tenTosixteen.o
	gcc  *.o -o main
%.o:%.c
	gcc -c $< -o  $@
clean:
	rm -f *.o main
