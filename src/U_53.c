#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define LINE 512

int checkMethod_1(char s[], int i);
int checkMethod_2(char s[], int i);
int U_53()
{
	FILE* fp;
	char buf[LINE];

	if((fp = fopen("/etc/passwd", "r")) == NULL) {
                printf("[U-53] 사용자 shell 점검 (하) : 점검 오류 (파일 탐색 불가)\n");
                return 0;
        }
	
	for(int i=0; i<2; i++)
		fgets(buf, LINE, fp);	
	
	int i = 0;	
	while( buf[i] != '\n' ) {
		i++;
	}
	if( checkMethod_1( buf, i-1 ) || checkMethod_2( buf, i-1 ) ) {
		printf("[U-53] 사용자 shell 점검 (하) : 양호\n");
		fclose(fp);
		return 1;
	}
	else {
		printf("[U-53] 사용자 shell 점검 (하) : 취약\n");
		fclose(fp);
		return 2;
	}	
}

int checkMethod_1(char s[], int i)
{
	char check[] = "/sbin/nologin";
	int index = 0;

	for(int j=i-12; j<i+1; j++) {
		if( check[index] != s[j] )
		       return FALSE;	
		index++;
	}
	return TRUE;
}

int checkMethod_2(char s[], int i)
{
	char check[] = "/bin/false";
	int index = 0;

	for(int j=i-9; j<i+1; j++) {
		if( check[index] != s[j] )
			return FALSE;
		index++;
	}
	return TRUE;
}
