#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define TRUE 1
#define FALSE 0

int homeDir(char s[], int index);
void U_59()
{
	FILE *fp;
	char buf[512];
	
	if( (fp = fopen("/etc/passwd", "r")) == NULL ) {
		printf("[U-59] 홈디렉토리로 지정한 디렉토리의 존재 관리 (중) : 점검 오류\n");
                return;
	}

	while( fgets(buf, LINE, fp) ) {
		int i = 0;
		int check = 0;
		while( check != 5 ) {
			if( buf[i] == ':' )
				check++;
			i++;
		}
		if( homeDir( buf, i )==FALSE ) {
		       	fclose(fp);
			printf("[U-59] 홈디렉토리로 지정한 디렉토리의 존재 관리 (중) : 취약\n");
			return;
		}
	}
	fclose(fp);
	printf("[U-59] 홈디렉토리로 지정한 디렉토리의 존재 관리 (중) : 양호\n");
}

int homeDir(char s[], int index)
{
	char *home = "/home";
	int j = 0;

	for( int i=index; i<index+5; i++ ) {
		if( s[i] != home[j] ) {
			return FALSE;
		}
		j++;
	}
	return TRUE;	
}	
