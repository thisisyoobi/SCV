#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int U_13()
{
	char output[100];
	FILE *p = popen("find / -perm -4000 2> /dev/null", "r");
	FILE *ep = popen("find / -perm -4000 2>&1 1> /dev/null", "r");
	FILE *fw = fopen("./U-13_find_result.txt", "w");
	fprintf(fw, "\n################################\n");
	fprintf(fw, "$ find / -perm -4000\n");
	fprintf(fw, "위 명령어를 실행시킨 결과입니다.\n");
	fprintf(fw, "################################\n\n");

	fprintf(fw, "#### 표준 출력 결과 ####\n");
	if(p != NULL){
		while(fgets(output, sizeof(output), p) != NULL)
			fprintf(fw, "%s", output);
	}
	
	fprintf(fw, "\n\n#### 표준 에러 결과 ####\n");
	if(ep != NULL){
		while(fgets(output, sizeof(output), ep) != NULL)
			fprintf(fw, "%s", output);
	}


	printf("[U-13] SUID, SGID, Sticky bit 설정 파일 점검 (상) : 수동 확인\n");
	return 3;
}
