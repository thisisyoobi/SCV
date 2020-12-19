#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : Anonymous FTP 비활성화 점검 
          "passwd" 파일에서 ftp계정이 존재하면 취약, 없으면 양호 */

void U_20() {
   FILE* fp;
   int n1;
   char count1[BUF_SIZE];
   char setting[BUF_SIZE] = "0";
   int ret1;

   system("cat /etc/passwd | grep \"ftp\" | wc -l > output20.txt");

   if ((fp = fopen("output20.txt", "r")) == NULL) {
      printf("[U-20] Anonymous FTP 비활성화(상) : 점검 오류\n");
      return;
   }
   fgets(count1, sizeof(count1), fp);
   ret1 = strcmp(count1, setting);
   if (ret1 == 10)
      printf("[U-20] Anonymous FTP 비활성화(상) : 양호\n");
   else
      printf("[U-20] Anonymous FTP 비활성화(상) : 취약\n");

   system("rm -f output20.txt");
}
