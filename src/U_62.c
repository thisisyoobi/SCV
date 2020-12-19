#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : FTP 서비스가 활성화 되어있는지 점검 
            일반 ftp서비스 , vsftpd or ProFtp서비스 활성화시 취약, 비활성화시 양호*/

int U_62() {
   FILE* fp1, * fp2;
   int n1, n2;
   char count1[BUF_SIZE], count2[BUF_SIZE];
   char checkarr[BUF_SIZE] = "2";  /*( grep과 system call에의해서 2가 default )*/
   int ret1, ret2;

   system("ps -ef | grep ftp | wc -l > output62_1.txt");
   system("ps -ef | egrep \"vsftpd|proftp\" | wc -l > output62_2.txt");
   if ((fp1 = fopen("output62_1.txt", "r")) == NULL) {
      printf("[U-62] ftp 서비스 확인(하) : 점검 오류 (파일 탐색 불가)\n");
      system("rm -f output62_1.txt");
      return 0;
   }
   if ((fp2 = fopen("output62_2.txt", "r")) == NULL) {
      printf("[U-62] ftp 서비스 확인(하) : 점검 오류 (파일 탐색 불가)\n");
      system("rm -f output62_1.txt");
      system("rm -f output62_2.txt");
      return 0;
   }

   fgets(count1, sizeof(count1), fp1);
   fgets(count2, sizeof(count2), fp2);

   ret1 = strcmp(count1, checkarr);
   ret2 = strcmp(count2, checkarr);
   system("rm -f output62_1.txt");
   system("rm -f output62_2.txt");
   if (ret1 == 10 && ret2 == 10){
      printf("[U-62] ftp 서비스 확인(하) : 양호\n");
      return 1;
   }
   else{
      printf("[U-62] ftp 서비스 확인(하) : 취약\n");
      return 2;
   }

}
