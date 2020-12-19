#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 512
#define RESTRICTION "PrivacyOptions=authwarnings, noexpn, novrfy"
/*점검기준 : expn, vrfy 명령어 제한 */
int U_71()
{
	FILE *fp;
	char buf[LINE];

	if((fp =fopen("/etc/mail/sendmail.cf", "r")) == NULL){
		printf("[U-71] expn, vrfy 명령어 제한(중) : 양호(미사용)\n");
		return 1;
	}

	while(fgets(buf, sizeof(buf), fp)){
		if(strcmp(RESTRICTION, buf) ==0){
			printf("[U-71] expn, vrfy 명령어 제한(중) : 양호\n");
			fclose(fp);
			return 1;

		}
	}
	printf("[U-71] expn, vrfy 명령어 제한(중) : 취약\n");
	return 2;
}


