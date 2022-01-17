#include <stdlib.h>
#include <unistd.h>
const char Bienvenue[] = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'. \n";
const char prompt[]= "enseash % \n";
int main()
{
  write(STDOUT_FILENO,Bienvenue,sizeof(Bienvenue));
  write(STDOUT_FILENO,prompt,sizeof(prompt));    
}
