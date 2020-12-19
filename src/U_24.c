#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검 기준 : NFS 서비스 비활성화 
            NFS 서비스 데몬이 활성화되면 취약, 비활성화시 양호*/

void U_24() {
   FILE* fp;
   int n1;
   char count1[BUF_SIZE];
   char setting[BUF_SIZE] = "2"; /*( grep과 system call에의해서 2가 default )*/
   int ret1;

   system("ps -ef | egrep \"nfs|statd|lockd\" | wc -l > output24.txt");

   if ((fp = fopen("output24.txt", "r")) == NULL) {
      printf("[U-24] NFS 서비스 비활성화(상) : 점검 오류\n");
      return;
   }
   fgets(count1, sizeof(count1), fp);
   ret1 = strcmp(count1, setting);
   if (ret1 == 10)
      printf("[U-24] NFS 서비스 비활성화(상) : 양호\n");
   else
      printf("[U-24] NFS 서비스 비활성화(상) : 양호\n");

   system("rm -f output24.txt");
}

