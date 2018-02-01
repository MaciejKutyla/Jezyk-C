compile: saper.c 
	gcc -o saper -std=c11 -Wall -pedantic -Wextra -Werror saper.c -I.
run: saper.c
	./saper
clean: saper.c 
	rm saper
