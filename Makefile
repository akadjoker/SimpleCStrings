CFLAGS = -Wall -Wextra -Wall -fsanitize=address
LDFLAGS = -fsanitize=address

main: main.o
	@clear
	@gcc $(LDFLAGS) main.o -o main
	@./main 

main.o: main.c 
	gcc $(CFLAGS) -c main.c

re: clean main

clean:
	rm -f *.o main
	