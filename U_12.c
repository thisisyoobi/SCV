#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LINE 512

void U_12()
{
	int fd;
	char buf[LINE];

	if( (fd = open("/etc/gshadow", O_RDONLY)) == -1 ) {
		printf("[U-12] 계정이 존재하지 않는 GID 금지 (하) : 양호\n");
                exit(0);
        }

	if( read(fd, buf, sizeof(buf) ) )
		printf("[U-12] 계정이 존재하지 않는 GID 금지 (하) : 양호\n");
	else
		printf("[U-12] 계정이 존재하지 않는 GID 금지 (하) : 취약\n");
	close(fd);
}
