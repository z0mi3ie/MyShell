#cs620 Assignment 2 Makefile

myshell:	myshell.c myshell.h
	gcc -Wall myshell.c -o myshell
myhistory: myhistory.c myhistory.h
	gcc -Wall myhistory.c -o myhistory
				
