#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "head.h"

int result_checker[74];
int error_count = 0;
int good_count = 0;
int bad_count = 0;
int manual_count = 0;

void manualNotice();
void printElementInfo();
void printCount();
void getCount();
void intro();
void checking_vul();

void main()
{
	printf("################## 리눅스 버전 정보 ##################\n");
	//uname execute
	char output[100];
	FILE *p = popen("uname -a", "r");
	if(p != NULL)
	{
		while(fgets(output, sizeof(output), p) != NULL)
			printf("%s", output);
	}
	printf("\n");

	intro();
	checking_vul();

	getCount();
	printCount();

	printElementInfo();

	manualNotice();

	printf("\n\n");
//	for(int i = 1; i < 74; i++)
//		printf("%d : %d\n",i, result_checker[i]);

}

void manualNotice()
{
	sleep(1);
	printf("\n\n############ 수동 확인 설명 ############\n\n");
	printf("점검 항목 중 서버 관리자의 주관이 포함되는 항목은\n");
	printf("수동 확인 대상으로 설정하였습니다.\n\n");
	printf("#### 참고 ####\n");
	printf("[U-13] : setuid 파일을 U-13_find_result.txt 파일로 저장\n");
}

void printElementInfo()
{
	sleep(1);
	char defaultMsg[100];
	char tmp[100];
	int count = 0;
	
	printf("\n\n############ 탐지 항목 리스트 ############\n\n");
	printf("============= 양호 ==============\n");
	for(int i = 1; i < 74; i++)
	{
		if(result_checker[i] == 1)
		{
			if(i < 10)
				strcpy(defaultMsg, "[U-0");
			else
				strcpy(defaultMsg, "[U-");
			sprintf(tmp, "%d", i);
			strcat(defaultMsg, tmp);
			strcat(defaultMsg, "]");
			printf("%s ", defaultMsg);
			count++;
			if(count % 5 == 0)
				printf("\n");

		}
	}
	count = 0;
	printf("\n\n============= 취약 ==============\n");
	for(int i = 1; i < 74; i++)
	{
		if(result_checker[i] == 2)
		{
			if(i < 10)
				strcpy(defaultMsg, "[U-0");
			else
				strcpy(defaultMsg, "[U-");
			sprintf(tmp, "%d", i);
			strcat(defaultMsg, tmp);
			strcat(defaultMsg, "]");
			printf("%s ", defaultMsg);
			count++;
			if(count % 5 == 0)
				printf("\n");

		}
	}
	count = 0;
	printf("\n\n=========== 수동 확인 ===========\n");
	for(int i = 1; i < 74; i++)
	{
		if(result_checker[i] == 3)
		{
			if(i < 10)
				strcpy(defaultMsg, "[U-0");
			else
				strcpy(defaultMsg, "[U-");
			sprintf(tmp, "%d", i);
			strcat(defaultMsg, tmp);
			strcat(defaultMsg, "]");
			printf("%s ", defaultMsg);
			count++;
			if(count % 5 == 0)
				printf("\n");

		}
	}
	count = 0;
	printf("\n\n=========== 점검 오류 ===========\n");
	for(int i = 1; i < 74; i++)
	{
		if(result_checker[i] == 0)
		{
			if(i < 10)
				strcpy(defaultMsg, "[U-0");
			else
				strcpy(defaultMsg, "[U-");
			sprintf(tmp, "%d", i);
			strcat(defaultMsg, tmp);
			strcat(defaultMsg, "]");
			printf("%s ", defaultMsg);
			count++;
			if(count % 5 == 0)
				printf("\n");

		}
	}

}

void printCount()
{
	sleep(1);
	printf("\n\n############ 진단 결과 ############\n\n");
	printf("양호 : %d\n", good_count);
	printf("취약 : %d\n", bad_count);
	printf("수동 확인 : %d\n", manual_count);
	printf("점검 오류 (파일 탐색 불가) : %d\n", error_count);
}

void getCount()
{
	for(int i = 1; i < 74; i++)
	{
		if(result_checker[i] == 0)
			error_count++;
		else if(result_checker[i] == 1)
			good_count++;
		else if(result_checker[i] == 2)
			bad_count++;
		else if(result_checker[i] == 3)
			manual_count++;
	}
}

void intro()
{
	printf("###########################################\n");
	printf("####                                   ####\n");
	printf("####  Linux 서버 취약점 자동 분석 도구 ####\n");
	printf("####                                   ####\n");
	printf("####          SCV : ver.1.0.3          ####\n");
	printf("####                                   ####\n");
	printf("###########################################\n\n");
	sleep(2);
}

void checking_vul()
{
	printf("########## 서버 취약점 진단 시작 ##########\n");

	sleep(2);
	result_checker[1] = U_01();
	usleep(500000);
	result_checker[2] = U_02();
	usleep(500000);
	result_checker[3] = U_03();
	usleep(500000);
	result_checker[4] = U_04();
	result_checker[5] = U_05();
	usleep(500000);
	result_checker[6] = U_06();
	usleep(500000);
	result_checker[7] = U_07();
	usleep(500000);
	result_checker[8] = U_08();
	usleep(500000);
	result_checker[9] = U_09();
	usleep(500000);
	result_checker[10] = U_10();
	usleep(500000);
	result_checker[11] = U_11();
	usleep(500000);
	result_checker[12] = U_12();
	usleep(500000);
	result_checker[13] = U_13();
	usleep(500000);
	result_checker[14] = U_14();
	usleep(500000);
	result_checker[15] = U_15();
	usleep(500000);
	result_checker[16] = U_16();
	usleep(500000);
	result_checker[17] = U_17();
	usleep(500000);
	result_checker[18] = U_18();
	usleep(500000);
	result_checker[19] = U_19();
	usleep(500000);
	result_checker[20] = U_20();
	usleep(500000);
	result_checker[21] = U_21();
	usleep(500000);
	result_checker[22] = U_22();
	usleep(500000);
	result_checker[23] = U_23();
	usleep(500000);
	result_checker[24] = U_24();
	usleep(500000);
	result_checker[25] = U_25();
	usleep(500000);
	result_checker[26] = U_26();
	usleep(500000);
	result_checker[27] = U_27();
	usleep(500000);
	result_checker[28] = U_28();
	usleep(500000);
	result_checker[29] = U_29();
	usleep(500000);
	result_checker[30] = U_30();
	usleep(500000);
	result_checker[31] = U_31();
	usleep(500000);
	result_checker[32] = U_32();
	usleep(500000);
	result_checker[33] = U_33();
	usleep(500000);
	result_checker[34] = U_34();
	usleep(500000);
	result_checker[35] = U_35();
	usleep(500000);
	result_checker[36] = U_36();
	usleep(500000);
	result_checker[37] = U_37();
	usleep(500000);
	result_checker[38] = U_38();
	usleep(500000);
	result_checker[39] = U_39();
	usleep(500000);
	result_checker[40] = U_40();
	usleep(500000);
	result_checker[41] = U_41();
	usleep(500000);
	result_checker[42] = U_42();
	usleep(500000);
	result_checker[43] = U_43();
	usleep(500000);
	result_checker[44] = U_44();
	usleep(500000);
	result_checker[45] = U_45();
	usleep(500000);
	result_checker[46] = U_46();
	usleep(500000);
	result_checker[47] = U_47();
	usleep(500000);
	result_checker[48] = U_48();
	usleep(500000);
	result_checker[49] = U_49();
	usleep(500000);
	result_checker[50] = U_50();
	usleep(500000);
	result_checker[51] = U_51();
	usleep(500000);
	result_checker[52] = U_52();
	usleep(500000);
	result_checker[53] = U_53();
	usleep(500000);
	result_checker[54] = U_54();
	usleep(500000);
	result_checker[55] = U_55();
	usleep(500000);
	result_checker[56] = U_56();
	usleep(500000);
	result_checker[57] = U_57();
	usleep(500000);
	result_checker[58] = U_58();
	usleep(500000);
	result_checker[59] = U_59();
	usleep(500000);
	result_checker[60] = U_60();
	usleep(500000);
	result_checker[61] = U_61();
	usleep(500000);
	result_checker[62] = U_62();
	usleep(500000);
	result_checker[63] = U_63();
	usleep(500000);
	result_checker[64] = U_64();
	usleep(500000);
	result_checker[65] = U_65();
	usleep(500000);
	result_checker[66] = U_66();
	usleep(500000);
	result_checker[67] = U_67();
	usleep(500000);
	result_checker[68] = U_68();
	usleep(500000);
	result_checker[69] = U_69();
	usleep(500000);
	result_checker[70] = U_70();
	usleep(500000);
	result_checker[71] = U_71();
	usleep(500000);
	result_checker[72] = U_72();
	usleep(500000);
	result_checker[73] = U_73();
	usleep(500000);
}
