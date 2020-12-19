#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : Dos 공격에 취약한 서비스 비활성화
            /etc/xinetd.d/ dir 내에서 echo,discard, daytiem, chargen 파일에서
            disable = yes로 설정되어있으면 양호, 그렇지않으면 취약  */

int U_23() {
   FILE* fp1, * fp2;
   char arr[BUF_SIZE];
   char setting[BUF_SIZE] = "0";
   char setting2[BUF_SIZE] = "2";
   int count = 0;
   int ret;
   system("ls -alL /etc/xinetd.d/* 2> /dev/null| wc -l > output23_0.txt");
   if ((fp1 = fopen("output23_0.txt", "r")) == NULL) {
      printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 점검 오류 (파일 탐색 불가)\n");
      system("rm -f output23_0.txt");
      return 0;
   }
   fgets(arr, sizeof(arr), fp1);
   ret = strcmp(arr, "0");
   // output23_0의 결과가 0이면 xinetd.d가 설치되지 않은것, 점검오류  
   if (ret == 10) {
      printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 점검 오류 (파일 탐색 불가)\n"); // xinetd.d 설치 필요 ( sudo apt-get install xinetd.d ) 
      system("rm -f output23_0.txt");
      return 0;
   }
   else {
      //echo 
      system("cat -T /etc/xinetd.d/echo > output23_1.txt");
      system("grep -r \'disable^I^I= yes\' output23_1.txt | wc -l > output23_1_2.txt");
      // 결과가 2이면 yes로 설정되어있는것  = > 양호 2가 아니면 yes로 설정되어있지 않는것, 취약
      if ((fp2 = fopen("output23_1_2.txt", "r")) == NULL) {
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 점검 오류 (파일 탐색 불가)\n");
         system("rm -f output23_1.txt");
         system("rm -f output23_1_2.txt");
         return 0;
      }
      fgets(arr, sizeof(arr), fp2);
      ret = strcmp(arr, setting2);
      system("rm -f output23_1.txt");
      system("rm -f output23_1_2.txt");
      if (ret == 10)
         count++;
      else {
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 취약\n");
         return 2;
      }

      system("rm -f output23_1.txt");
      system("rm -f output23_1_2.txt");

      //discard
      system("cat -T /etc/xinetd.d/discard > output23_1.txt");
      system("grep -r \'disable^I^I= yes\' output23_1.txt | wc -l > output23_1_2.txt");
      // 결과가 2이면 yes로 설정되어있는것  = > 양호 2가 아니면 yes로 설정되어있지 않는것, 취약
      if ((fp2 = fopen("output23_1_2.txt", "r")) == NULL) {
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 점검 오류 (파일 탐색 불가)\n");
         return 0;
      }
      fgets(arr, sizeof(arr), fp2);
      ret = strcmp(arr, setting2);
      system("rm -f output23_1.txt");
      system("rm -f output23_1_2.txt");
      if (ret == 10)
         count++;
      else {
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 취약\n");
         return 2;
      }

      system("rm -f output23_1.txt");
      system("rm -f output23_1_2.txt");

      //daytime
      system("cat -T /etc/xinetd.d/daytime > output23_1.txt");
      system("grep -r \'disable^I^I= yes\' output23_1.txt | wc -l > output23_1_2.txt");
      // 결과가 2이면 yes로 설정되어있는것  = > 양호 2가 아니면 yes로 설정되어있지 않는것, 취약
      if ((fp2 = fopen("output23_1_2.txt", "r")) == NULL) {
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 점검 오류 (파일 탐색 불가)\n");
         return 0;
      }
      fgets(arr, sizeof(arr), fp2);
      ret = strcmp(arr, setting2);
      system("rm -f output23_1.txt");
      system("rm -f output23_1_2.txt");
      if (ret == 10)
         count++;
      else {
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 취약\n");
         return 2;
      }

      system("rm -f output23_1.txt");
      system("rm -f output23_1_2.txt");

      //chargen
      system("cat -T /etc/xinetd.d/chargen > output23_1.txt");
      system("grep -r \'disable^I^I= yes\' output23_1.txt | wc -l > output23_1_2.txt");
      // 결과가 2이면 yes로 설정되어있는것  = > 양호 2가 아니면 yes로 설정되어있지 않는것, 취약
      if ((fp2 = fopen("output23_1_2.txt", "r")) == NULL) {
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 점검 오류 (파일 탐색 불가)\n");
         return 0;
      }
      fgets(arr, sizeof(arr), fp2);
      ret = strcmp(arr, setting2);
      system("rm -f output23_0.txt");
      system("rm -f output23_1.txt");
      system("rm -f output23_1_2.txt");
      if (ret == 10)
         count++;
      else {
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 취약\n");
         return 2;
      }

      system("rm -f output23_0.txt");
      system("rm -f output23_1.txt");
      system("rm -f output23_1_2.txt");

      if (count == 4){
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 양호\n");
         return 1;
      }
      else{
         printf("[U-23] DoS 공격에 취약한 서비스 비활성화(상) : 취약\n");
                  return 2;
      }
   }
}
