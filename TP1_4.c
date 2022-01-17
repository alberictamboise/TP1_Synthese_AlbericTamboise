#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#define lecturesize 100
const char Bienvenue[] = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.";
const char Aurevoir[] = "Bye bye...\n$\n";
const char prompt[]= "\nenseash %";
const char exit1[]="exit";
char prompt2[lecturesize];
int state,lec;
int main(){
	char lecture[lecturesize];
	pid_t pid;
	write(STDOUT_FILENO,Bienvenue,sizeof(Bienvenue));
	write(STDOUT_FILENO,prompt,sizeof(prompt));
	       while(1){
			   lec =read(STDOUT_FILENO,lecture,lecturesize);
			   lecture[lec-1]='\0';
			   if(strncmp(lecture,exit1,lecturesize)== 0 || lec == 0 ){
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
								   wait(&state);
								   if(WIFEXITED(state)) {
									   sprintf(prompt2,"enseash [exit: %d]  %%",WEXITSTATUS(state));
									   write(STDOUT_FILENO,prompt2,strlen(prompt2));
									   }else if (WIFSIGNALED(state)){
									   sprintf(prompt2,"enseash [sign: %d]  %%",WTERMSIG(state));
									   write(STDOUT_FILENO,prompt2,strlen(prompt2));
	                                   }
                                    }
                     }
                    }
exit(EXIT_SUCCESS);
}
