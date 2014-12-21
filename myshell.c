// Kyle Vickers
// CS620 Assignment 2
// Shell with out history support

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include "myshell.h"

int main(int argc, char const *argv[]) {
    char * cmds[MAX_ARGS_LENGTH]; 
    while( TRUE ) {
        printf("myshell> ");
        read_in(cmds);
        execute(cmds);
    }
    return 0;
}

//-------------------------------------------------
// read_in
// Read in a command from stdin.
// This function also removes the white space
// And tokenizes the string.
void read_in(char *arr[]) {
    char cmds[MAX_CMD_SIZE];
    fgets(cmds, MAX_CMD_SIZE, stdin); 
    remove_white_space(cmds);
    tokenize_string( arr, cmds ); 
}

//-------------------------------------------------
// tokenize_string
// Takes a 2d array as a destination and a string
// of cmds and tokenizes the string of commands
// and puts them into the 2d array. 
void tokenize_string( char** arr, char*cmds) {
    int i = 0;
    arr[i] = strtok(cmds," ");
    while( arr[i] != NULL && i < MAX_ARGS_LENGTH) {
      i++;
      arr[i] = strtok(NULL," ");
    }
}

//-------------------------------------------------
// remove_white_space
// Takes a string and removes white space by adding
// the c style end string character to the array
void remove_white_space(char*s) {
    int end = strlen( s ) - 1;
    while( isspace( s[end]) ) {
      s[end] = '\0';
      end--;
    }
}

//-------------------------------------------------
// execute
// Takes a 2d array and executes the command with
// the given arguments
void execute(char *arr[]) {
    if(arr[0]==NULL)
      return; 
    if (!strcmp(arr[0],"quit"))
        exit(0);
    
    pid_t pid = fork();
    if (pid < 0){
        perror("An error has occurred");
    } else if ( pid > 0 ) { 
        int status;
        wait(&status);
    } else { 
        execvp( arr[0], arr );
        /////////////////////////////////////////////////////////
        // If beyond here there was an unknown command present //
        // Enables quit to be used after bad commands          //
        /////////////////////////////////////////////////////////
        printf ( "Unknown command: %s\n", arr[0] ); 
        abort ();
    }
}
