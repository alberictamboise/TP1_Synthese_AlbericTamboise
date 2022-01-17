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
while(1) 
if (ret != 0){ 
	sleep(55);
return 0;
} else {
printf("I am the child:");
print_PCB();
printf("\n");
}
return 0;
exit(EXIT_SUCCESS);

}
