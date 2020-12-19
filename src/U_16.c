#define BUF_SIZE 1024

/* 점검기준 : /dev에 존재하지 않는 device 파일 점검 
           존재하지 않는 디바이스가 "dev" 디렉토리에 있으면 취약 없으면 양호*/

int U_16() {
   FILE* fp;
   int n1;
   char count1[BUF_SIZE];
   char setting[BUF_SIZE] = "0";
   int ret1;

   system("find /dev -type f -exec ls -l {} \\; | wc -l > output16.txt");

   if ((fp = fopen("output16.txt", "r")) == NULL) {
      printf("[U-16] /dev에 존재하지 않는 device 파일 점검(상) : 점검 오류 (파일 탐색 불가)\n");
      return 0;
   }
   fgets(count1, sizeof(count1), fp);
   ret1 = strcmp(count1, setting);
   system("rm -f output16.txt");
   if (ret1 == 10){
      printf("[U-16] /dev에 존재하지 않는 device 파일 점검(상) : 양호\n");
              return 1;
   }
   else{
      printf("[U-16] /dev에 존재하지 않는 device 파일 점검(상) : 취약\n");
              return 2;
   }
}
