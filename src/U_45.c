#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define LINE 512
#define PAM_MODULE "authrequiredpam_wheel.so\n"
#define PAM_MODE 1
#define GROUP_MODE 2

int FileOpen(char fname[], char s[], int mode);
void U_45()
{
	if( FileOpen( "/etc/pam.d/su", PAM_MODULE, PAM_MODE) == FALSE ) {
		printf("[U-45] root 계정 su 제한 (하) : 취약\n");
		return;
	}

	if( FileOpen( "/etc/group", "wheel", GROUP_MODE) == FALSE ) {
		printf("[U-45] root 계정 su 제한 (하) : 취약\n");
                return;
	}
	
	printf("[U-45] root 계정 su 제한 (하) : 양호\n");
}

int FileOpen(char fname[], char s[], int mode)
{
	FILE *fp;
	char buf[LINE];
	int check = FALSE;

	if((fp = fopen(fname, "r")) == NULL) {
                printf("[U-45] root 계정 su 제한 (하) : 점검 오류\n");
                exit(1);
        }
	while( fgets(buf, LINE, fp) ) {
                if( mode == PAM_MODE && strcmp(s, DeleteSpace(buf)) == 0 ) {
                        check = TRUE;
                        break;
                }
		if( mode == GROUP_MODE && strncmp(s, buf, 5) == 0 ) {
			check = TRUE;
			break;
		}
        }
	fclose(fp);
	return check;
}


