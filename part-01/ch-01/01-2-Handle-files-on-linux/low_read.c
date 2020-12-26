#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 100
void error_handling(char* message);

int main(void)
{
	int fd;
	char buf[BUF_SIZE];
	int read_result;

	fd = open("data.txt", O_RDONLY); 
	if(fd == -1) 
		error_handling("open() error!");
	printf("file descriptor: %d \n", fd);

	read_result = read(fd, buf, sizeof(buf));
	if(read_result == -1)
		error_handling("read() error!");
	printf("fild data: %s", buf);
	printf("read result: %d", read_result);
	close(fd);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
