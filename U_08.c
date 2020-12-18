#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* /etc/shadow 파일 소유자 및 권한 설정 */

void U_08()
{
	FILE *fp; //변수 선언
	struct stat buf;
	if((fp =fopen("/etc/shadow", "r")) == NULL){
		printf("[U-08] /etc/shadow 파일 소유자 및 권한 설정 (상) : 점검 오류\n");
		return;
	}
	stat("/etc/shadow", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR){
			printf("[U-08] /etc/shadow 파일 소유자 및 권한 설정 (상) : 양호\n");
		}
		else
			printf("[U-08] /etc/shadow 파일 소유자 및 권한 설정 (상) : 취약\n");
		
	}
	else
		printf("[U-08] /etc/shadow 파일 소유자 및 권한 설정 (상) : 취약\n");
		
}
