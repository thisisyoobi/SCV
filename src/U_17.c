#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
/* $HOME/.rhosts, hosts.equiv 사용 금지 */
// commit change1
void U_17()
{
	FILE *fp, *fp1;
	struct stat buf;
	struct stat buf1;
	char a,b;
	if((fp =fopen("/etc/hosts.equiv", "r")) == NULL){
		printf("[U-17] $HOME/.rhosts, hosts.equiv 사용 금지(상): 점검 오류\n");
		return;
	}
	if((fp1 =fopen("$HOME/.rhosts", "r")) == NULL){
		printf("[U-17] $HOME/.rhosts, hosts.equiv 사용 금지(상): 점검 오류\n");
		return;
	}
	
	stat("/etc/hosts.lpd", &buf);
	stat("$HOME/.rhosts", &buf1);
	
	if(buf.st_uid == 0 && buf1.st_uid){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf1.st_mode &S_IRUSR && buf1.st_mode &S_IWUSR){
			while(!feof(fp)){
				a = fgetc(fp);
				if(a == '+'){
				printf("[U-17] $HOME/.rhosts, hosts.equiv 사용 금지(상) : 취약\n");
				exit(0);
				}
			}
			while(!feof(fp1)){
				b = fgetc(fp1);
				if(b == '+'){
				printf("[U-17] $HOME/.rhosts, hosts.equiv 사용 금지(상) : 취약\n");
				exit(0);
				}
			}
			printf("[U-17] $HOME/.rhosts, hosts.equiv 사용 금지(상) : 양호\n");					
					
		}
		else
			printf("[U-17] $HOME/.rhosts, hosts.equiv 사용 금지(상) : 취약\n");
		
	}
	else
		printf("[U-17] $HOME/.rhosts, hosts.equiv 사용 금지(상): : 취약\n");		
}
