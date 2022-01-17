#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <time.h>
#define lecturesize 100
#define conversion 1000000
const char Bienvenue[] = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.";
const char Aurevoir[] = "Bye bye...\n$\n";
const char prompt[]= "\nenseash %";
const char exit1[]="exit";
char prompt2[lecturesize];
struct timespec tpstart;
clockid_t clk_id;
int state;
struct timespec tpstop;
int main(){
	char lecture[lecturesize];
	pid_t pid;
	clk_id=CLOCK_REALTIME;
	write(STDOUT_FILENO,Bienvenue,sizeof(Bienvenue));//Affichage du message d'acceuil
    write(STDOUT_FILENO,prompt,sizeof(prompt));
    
    while(1){
		int lec =read(STDOUT_FILENO,lecture,lecturesize);
		lecture[lec-1]='\0';//on rajoute un caractère nul comme dernier caractère
		     if(strncmp(lecture,exit1,lecturesize)== 0 || lec == 0 ){
				 write(STDOUT_FILENO,Aurevoir,sizeof(Aurevoir));
				 break;}
		     else{
				 pid=fork();
	             if(pid == 0){ 
					 //on est dans le processus fils
					 clock_gettime(clk_id,&tpstart);//prends une valeur de temps initial
					 execlp(lecture,lecture,( char * )NULL);//ont traite les arguments un par un et on cherche l'executable lecture dans le path
					 exit(EXIT_FAILURE);
                             }
                             else{ 
								 wait(&state);
								 clock_gettime(clk_id,&tpstop);//prends une valeur de temps final
								 if(WIFEXITED(state)) {
									 sprintf(prompt2,"enseash [exit: %d] | %ldms %%",WEXITSTATUS(state),(tpstop.tv_nsec-tpstart.tv_nsec)/conversion);//on concatènes les chaines de caractères et on mets dans prompt2 
									 //pour avoir le message souhaité et on fais une soustraction sur les deux prises du temps pour avoir le temps d'execution
									 write(STDOUT_FILENO,prompt2,strlen(prompt2));
									 }else if (WIFSIGNALED(state)){
										 sprintf(prompt2,"enseash [sign: %d] | %ldms %%",WTERMSIG(state),(tpstop.tv_nsec-tpstart.tv_nsec)/conversion);
										 write(STDOUT_FILENO,prompt2,strlen(prompt2));
										                           }
                                  }
                 }
              }
exit(EXIT_SUCCESS);
 }
