#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void print_PCB()
{
printf("PPID: %d\n", getppid());
printf("PID: %d\n", getpid());
printf("UID: %d\n", getuid());
printf("GID: %d\n", getgid());

}
int main()
{
pid_t ret = fork();
if ( ret != 0){ 
printf("I am the father:");

printf("\n");

} else {
printf("I am the child:");
printf("\n");
}
print_PCB();
return 0;
exit(EXIT_SUCCESS);
}
