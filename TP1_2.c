#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define lecturesize 100
const char Bienvenue[] = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.";
const char Aurevoir[] = "Bye bye...\n $";
const char prompt[]= "\nenseash %";
const char exit1[]="exit";
int lec;
char lecture[lecturesize];

int main(){
	write(STDOUT_FILENO,Bienvenue,sizeof(Bienvenue));
	  while(1){
		  write(STDOUT_FILENO,prompt,sizeof(prompt));
		  lec =read(STDOUT_FILENO,lecture,lecturesize);
		  lecture[lec-1]='\0';//on rajoute un caractère nul comme dernier caractère
              }
         exit(EXIT_SUCCESS);
}

