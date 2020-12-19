#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* /etc/inetd.conf 파일 소유자 및 권한 설정 */

int U_10()
{
	FILE *fp; //변수 선언
	struct stat buf;
	
	if((fp =fopen("/etc/inetd.conf", "r")) == NULL){
		printf("[U-10] /etc/inetd.conf 파일 소유자 및 권한 설정(상): 점검 오류(파일 탐색 불가)\n");
		return 0;;
	}
	
	stat("/etc/inetd.conf", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR){
			printf("[U-10] /etc/inetd.conf 파일 소유자 및 권한 설정 (상) : 양호\n");
			return 1;
		}
		else
			printf("[U-10] /etc/inetd.conf 파일 소유자 및 권한 설정 (상) : 취약\n");
			return 2;
	}
	else
		printf("[U-10] /etc/inetd.conf 파일 소유자 및 권한 설정 (상) : 취약\n");
		return 2;
}
