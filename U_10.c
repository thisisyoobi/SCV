#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* /etc/inetd.conf 파일 소유자 및 권한 설정 */

void U_10()
{
	struct stat buf;
	
	if((fp =fopen("/etc/inetd.conf", "r")) == NULL){
		printf("[U-10] /etc/inetd.conf 파일 소유자 및 권한 설정(상): 점검 오류\n");
		return;
	}
	
	stat("/etc/inetd.conf", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR){
			printf("[U-10] /etc/inetd.conf 파일 소유자 및 권한 설정 (상) : 양호\n");
		}
		else
			printf("[U-10] /etc/inetd.conf 파일 소유자 및 권한 설정 (상) : 취약\n");
		
	}
	else
		printf("[U-10] /etc/inetd.conf 파일 소유자 및 권한 설정 (상) : 취약\n");
		
}
