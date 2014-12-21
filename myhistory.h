// Kyle Vickers
// Shell w/ History header
#ifndef MYSHELL_H
#define MYSHELL_H


const int MAX_CMD_SIZE    = 1024;
const int MAX_ARGS_LENGTH = 128;
const int TRUE            = 1;
const int FALSE           = 0;

const int MAX_HISTORY     = 100;
int hIndex                = 0; 
void addHistory(char*);
void viewHistory();

char ** history;

void read_in(char *[]);
void execute(char *[]);
void remove_white_space( char* ); 
void tokenize_string(char**,char*);

#endif
