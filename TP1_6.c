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
struct timespec tpstart,tpstop;
int state,lec;
const char * separators =" ";
struct timespec tpstop;
char *argv[lecturesize];
char lecture[lecturesize];
clockid_t clk_id;
pid_t pid;
         int main()
 {
   clk_id=CLOCK_REALTIME;
     write(STDOUT_FILENO,Bienvenue,sizeof(Bienvenue));//Affichage du message d'acceuil
     write(STDOUT_FILENO,prompt,sizeof(prompt));
   
   while(1){
           lec =read(STDOUT_FILENO,lecture,lecturesize);
           lecture[lec-1]='\0'; //on rajoute un caractère nul comme dernier caractère

        if(strncmp(lecture,exit1,lecturesize)== 0 || lec == 0 ){
	    write(STDOUT_FILENO,Aurevoir,sizeof(Aurevoir));
        break;}
        
			  pid=fork();
	          if(pid == 0){ 
				  //processus fils
		                    clock_gettime(clk_id,&tpstart);//prends une valeur de temps initial
		                    argv[0]=strtok(lecture,separators);//on extrait la première chaîne de caractères avant d'avoir le premier espace
		                    int i=0;
		while (argv[i] != NULL) {//on se déplace dans le tableau argv
			i=i+1;
			argv[i]=strtok(NULL,separators);
		}
		execvp(argv[0],argv);//on recherche argv[0] dans le path et les arguments sont tous dans un char **
		exit(EXIT_FAILURE);
	                      }
        else {
	    wait(&state);
	    clock_gettime(clk_id,&tpstop);//prends une valeur de temps final
	          if(WIFEXITED(state)) {
				  sprintf(prompt2,"enseash [exit: %d] | %ldms %%",WEXITSTATUS(state),(tpstop.tv_nsec-tpstart.tv_nsec)/conversion);//on concatènes les chaines de caractères et on mets dans prompt2 
				  write(STDOUT_FILENO,prompt2,strlen(prompt2));
	          }else if (WIFSIGNALED(state)){
		          sprintf(prompt2,"enseash [sign: %d] | %ldms %%",WTERMSIG(state),(tpstop.tv_nsec-tpstart.tv_nsec)/conversion);
		          write(STDOUT_FILENO,prompt2,strlen(prompt2));
	              }
             }
                       
          }
exit(EXIT_SUCCESS);
}
