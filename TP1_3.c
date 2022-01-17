#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define lecturesize 100
const char Bienvenue[] = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.";
const char Aurevoir[] = "Bye bye...\n$\n";
const char prompt[]= "\nenseash %";
const char exit1[]="exit";
int main(){
	char lecture[lecturesize];
	pid_t pid;
	write(STDOUT_FILENO,Bienvenue,sizeof(Bienvenue));
	while(1){
		write(STDOUT_FILENO,prompt,sizeof(prompt));
		int lec =read(STDOUT_FILENO,lecture,lecturesize);
		lecture[lec-1]='\0';
		if(strncmp(lecture,exit1,lecturesize)== 0 || lec == 0 ){//permet la sortie du shell si on ecrit exit on si on ecrit ctrl d
			write(STDOUT_FILENO,Aurevoir,sizeof(Aurevoir));
			break;}
			else {
				pid=fork();
				if(pid == 0){ 
					//on est dans le processus fils
					execlp(lecture,lecture,( char * )NULL);
					exit(EXIT_FAILURE);
					}
					else{ 
						wait(NULL);
	                    }
                 }
             }
exit(EXIT_SUCCESS);
}

