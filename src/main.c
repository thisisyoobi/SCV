#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "head.h"

int result_checker[74];

void checking_vul();

void main()
{
	checking_vul();

	for(int i = 1; i < 74; i++)
		printf("%d : %d\n",i, result_checker[i]);

}

void checking_vul()
{
	result_checker[1] = U_01();
	result_checker[2] = U_02();
	result_checker[3] = U_03();
	result_checker[4] = U_04();
	result_checker[5] = U_05();
	result_checker[6] = U_06();
	result_checker[7] = U_07();
	result_checker[8] = U_08();
	result_checker[9] = U_09();
	result_checker[10] = U_10();
	result_checker[11] = U_11();
	result_checker[12] = U_12();
	result_checker[13] = U_13();
	result_checker[14] = U_14();
	result_checker[15] = U_15();
	result_checker[16] = U_16();
	result_checker[17] = U_17();
	result_checker[18] = U_18();
	result_checker[19] = U_19();
	result_checker[20] = U_20();
	result_checker[21] = U_21();
	result_checker[22] = U_22();
	result_checker[23] = U_23();
	result_checker[24] = U_24();
	result_checker[25] = U_25();
	result_checker[26] = U_26();
	result_checker[27] = U_27();
	result_checker[28] = U_28();
	result_checker[29] = U_29();
	result_checker[30] = U_30();
	result_checker[31] = U_31();
	result_checker[32] = U_32();
	result_checker[33] = U_33();
	result_checker[34] = U_34();
	result_checker[35] = U_35();
	result_checker[36] = U_36();
	result_checker[37] = U_37();
	result_checker[38] = U_38();
	result_checker[39] = U_39();
	result_checker[40] = U_40();
	result_checker[41] = U_41();
	result_checker[42] = U_42();
	result_checker[43] = U_43();
	result_checker[44] = U_44();
	result_checker[45] = U_45();
	result_checker[46] = U_46();
	result_checker[47] = U_47();
	result_checker[48] = U_48();
	result_checker[49] = U_49();
	result_checker[50] = U_50();
	result_checker[51] = U_51();
	result_checker[52] = U_52();
	result_checker[53] = U_53();
	result_checker[54] = U_54();
	result_checker[55] = U_55();
	result_checker[56] = U_56();
	result_checker[57] = U_57();
	result_checker[58] = U_58();
	result_checker[59] = U_59();
	result_checker[60] = U_60();
	result_checker[61] = U_61();
	result_checker[62] = U_62();
	result_checker[63] = U_63();
	result_checker[64] = U_64();
	result_checker[65] = U_65();
	result_checker[66] = U_66();
	result_checker[67] = U_67();
	result_checker[68] = U_68();
	result_checker[69] = U_69();
	result_checker[70] = U_70();
	result_checker[71] = U_71();
	result_checker[72] = U_72();
	result_checker[73] = U_73();
}
