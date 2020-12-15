#include <stdio.h>
#include <stdlib.h>

#define LINE 512
#define TRUE 1
#define FALSE 0

int checkRoot(char s[], int i);
void U_50()
{
	FILE* fp;
	char buf[LINE];
	int check = 0, i = 0;

	if((fp = fopen("/etc/group", "r")) == NULL) {
                printf("[U-50] 관리자 그룹에 최소한의 계정 포함 (하) : 점검 오류\n");
                return;
        }

	fgets( buf, LINE, fp );
	while( check != 3 ) {
		if(buf[i] == ':')
			check++;
		i++;
	}
	if( buf[i] == '\n' )
		printf("[U-50] 관리자 그룹에 최소한의 계정 포함 (하) : 양호\n");
	else if( checkRoot(buf, i) ) {
		if( buf[i+4] == '\n' )
			printf("[U-50] 관리자 그룹에 최소한의 계정 포함 (하) : 양호\n");
		else
			printf("[U-50] 관리자 그룹에 최소한의 계정 포함 (하) : 취약\n");	
	}
	else
		printf("[U-50] 관리자 그룹에 최소한의 계정 포함 (하) : 취약\n");
	fclose(fp);
}

int checkRoot(char s[], int i)
{
	if( s[i] == 'r' && s[i+1] == 'o' && s[i+2] == 'o' && s[i+3] == 't' )
		return TRUE;
	return FALSE;
}
