#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 512
#define TRUE 1
#define FALSE 0

int* UID_list;
int size = 0;
int searchUID(int uid);
int U_52()
{
	FILE* fp;
	char buf[LINE];
	
	UID_list = (int*)malloc(sizeof(int));
	if((fp = fopen("/etc/group", "r")) == NULL) {
                printf("[U-52] 동일한 UID 금지 (중) : 점검 오류 (파일 탐색 불가)\n");
                return 0;
        }
	
	while( fgets(buf, LINE, fp) ) {
		int uid, i = 0, check = 0;
		while( check !=2 ) {
			if( buf[i] == ':')
				check++;
			i++;
		}

		uid = atoi(&buf[i]);
		if( searchUID(uid) == FALSE ) {
			printf("[U-52] 동일한 UID 금지 (중) : 취약\n");
			fclose(fp);
			return 2;
		}

		UID_list = (int*)realloc(UID_list, sizeof(int)*(++size));
		UID_list[size-1] = uid;	
	}
	printf("[U-52] 동일한 UID 금지 (중) : 양호\n");
	fclose(fp);
	return 1;
}

int searchUID(int uid)
{
	for(int i=0; i<size; i++) {
		if( UID_list[i] == uid )
			return FALSE;
	}
	return TRUE;
}

