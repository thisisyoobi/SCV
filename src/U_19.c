#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : Finger 서비스 비활성화
            Finger 서비스 활성화시 취약, 비활성화시 양호 */

void U_19() {
   FILE* fp1, * fp2;
   char arr[BUF_SIZE];
   char setting[BUF_SIZE] = "0";
   int ret;
   system("ls -alL /etc/xinetd.d/* 2> /dev/null| wc -l > output19_1.txt");
   if ((fp1 = fopen("output19_1.txt", "r")) == NULL) {
      printf("[U-19] Finger 서비스 비활성화(상) : 점검 오류\n");
      return;
   }
   fgets(arr, sizeof(arr), fp1);
   ret = strcmp(arr, setting);
   // output19_1의 결과가 0이면 xinetd.d가 설치되지 않은것, 점검오류  
   if (ret == 10) {
      printf("[U-19] Finger 서비스 비활성화(상) : 점검 오류\n"); // xinetd.d 설치 필요 ( sudo apt-get install xinetd.d ) 
      system("rm -f output19_1.txt");
      return;
   }
   else {
      system("ls -alL /etc/xinetd.d/* | egrep \"echo finger\" | wc -l > output19_2.txt");
      // 결과가 0이면 작동중이 아닌것 = > 양호 0이아니면 작동중, 취약
      if ((fp2 = fopen("output19_2.txt", "r")) == NULL) {
         printf("[U-19] Finger 서비스 비활성화(상) : 점검 오류\n");
         return;
      }
      fgets(arr, sizeof(arr), fp2);
      ret = strcmp(arr, setting);
      if (ret == 10)
         printf("[U-19] Finger 서비스 비활성화(상) : 양호\n");
      else
         printf("[U-19] Finger 서비스 비활성화(상) : 취약\n");

      system("rm -f output19_1.txt");
      system("rm -f output19_2.txt");
   }
}
