#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 512
#define SESSION_TIMEOUT "TMOUT"
/*점검기준 : Session Timeout 설정 */
void U_54()
{
	FILE *fp;
	char buf[LINE];
	
	if((fp =fopen("/etc/profile", "r")) == NULL){
		printf("[U-54]Session Timeout 설정\n");
		return;
	}
	
	while(fgets(buf, sizeof(buf), fp)){
		if(strncmp(SESSION_TIMEOUT, buf, 5) ==0){
			printf("[U-54] Session Timeout 설정 (중) : 양호\n");
			fclose(fp);
			exit(0);
		
		}
	}
	printf("[U-54] Session Timeout 설정 (중) : 취약\n");
}


