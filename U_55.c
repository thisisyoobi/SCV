#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* hosts.lpd 파일 소유자 및 권한 설정 */

void U_55()
{
	FILE *fp; //변수 선언
	struct stat buf;
	if((fp =fopen("/etc/hosts.lpd", "r")) == NULL){
		printf("[U-55] hosts.lpd 파일 소유자 및 권한 설정(하): 점검 오류\n");
		return;
	}
	
	stat("/etc/hosts.lpd", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR){
			printf("[U-55] hosts.lpd 파일 소유자 및 권한 설정(하) : 양호\n");
		}
		else
			printf("[U-55] hosts.lpd 파일 소유자 및 권한 설정(하): 취약\n");
		
	}
	else
		printf("[U-55] hosts.lpd 파일 소유자 및 권한 설정(하): : 취약\n");
		
}
