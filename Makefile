cc = gcc -std=c99 




make:
	$(cc) ./*.c -o calc

debug:
	$(cc) -g ./*.c  -o calc
