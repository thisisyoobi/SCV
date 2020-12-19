#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 512
#define SESSION_TIMEOUT "TMOUT"
/*점검기준 : Session Timeout 설정 */
int U_54()
{
	FILE *fp;
	char buf[LINE];
	
	if((fp =fopen("/etc/profile", "r")) == NULL){
		printf("[U-54]Session Timeout 설정(하) : 점검 오류(파일 탐색 불가)\n");
		return 0;
	}
	
	while(fgets(buf, sizeof(buf), fp)){
		if(strncmp(SESSION_TIMEOUT, buf, 5) ==0){
			printf("[U-54] Session Timeout 설정 (하) : 양호\n");
			fclose(fp);
			return 1;
		
		}
	}
	printf("[U-54] Session Timeout 설정 (하) : 취약\n");
	return 2;
}


