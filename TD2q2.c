#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (int argc, char*argv[])
{
	int fd;
	char path[] = "/etc/services";
	
	fd =  open(path, O_RDONLY);
	if(fd == 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("The file(%d) is correctly opened .\n",fd);
	exit(EXIT_SUCCESS);
	
}
