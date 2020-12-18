#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define EMPTY -1
void U_60()
{
	FILE *fp_f, *fp_d;
	char check;

	if( (fp_f = popen("echo find / -type f -name \".*\"", "r")) == NULL ) {
		printf("[U-60] 숨겨진 파일 및 디렉토리 검색 및 제거 (하) : 점검 오류\n");
		return;
	}
	if( (fp_d = popen("echo find / -type d -name \".*\"", "r")) == NULL ) {
                printf("[U-60] 숨겨진 파일 및 디렉토리 검색 및 제거 (하) : 점검 오류\n");
		pclose(fp_f);
                return;
        }
	
	check = fgetc(fp_f);
	if( check != EMPTY ) {
                printf("[U-60] 숨겨진 파일 및 디렉토리 검색 및 제거 (하) : 취약\n");
		pclose(fp_f);
		pclose(fp_d);
                return;
        }
	
	check = fgetc(fp_d);
        if( check != EMPTY ) {
                printf("[U-60] 숨겨진 파일 및 디렉토리 검색 및 제거 (하) : 취약\n");
                pclose(fp_f);
      	        pclose(fp_d);
                return;
        }
	
	printf("[U-60] 숨겨진 파일 및 디렉토리 검색 및 제거 (하) : 양호\n");
	pclose(fp_f);
	pclose(fp_d);
}
