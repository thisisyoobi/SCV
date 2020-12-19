#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define DENY "ALL:ALL"
#define ALLOW "sshd:192.168.0.148,192.168.0.6"
#define SUCCESS 2

int U_18()
{
	FILE *deny_fp, *allow_fp;
        char buf[LINE];
	int check = 0;

        if((deny_fp = fopen("/etc/hosts.deny", "r")) == NULL || 
			(allow_fp = fopen("/etc/hosts.allow", "r")) == NULL) {
                printf("[U-18] 접속 IP 및 포트 제한 (상) : 취약\n");
                return 2;
        }
	
	while( fgets(buf, LINE, deny_fp) ) {
		if ( strcmp(DENY, DeleteSpace(buf)) == 0 )
			check++;
	}
	while( fgets(buf, LINE, allow_fp) ) {
                if ( strcmp(ALLOW, DeleteSpace(buf)) == 0 )
                        check++;
        }
	
	if( check == SUCCESS ) {
		printf("[U-18] 접속 IP 및 포트 제한 (상) : 양호\n");
		fclose(deny_fp);
		fclose(allow_fp);
		return 1;
	}
	else {
		printf("[U-18] 접속 IP 및 포트 제한 (상) : 취약\n");
		fclose(deny_fp);
		fclose(allow_fp);
		return 2;
	}
}


