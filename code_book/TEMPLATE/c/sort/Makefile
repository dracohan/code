# INCLUDE := -I /home/withon/github/code/code_book/TEMPLATE/c/header/utils.h
CC=gcc -Wall -c -g
LD=gcc

quicksort: quicksort.o utils.o
	$(LD) $^ -o $@
quicksort.o: quicksort.c ../common_header/utils.h
	$(CC) $< -o $@
utils.o: ../utils/utils.c ../common_header/utils.h
	$(CC) $< -o $@

.PHONY : clean
clean:
	del quicksort.exe quicksort.o utils.o