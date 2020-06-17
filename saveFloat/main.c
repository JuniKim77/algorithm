#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE (64)
#define MANTISSA_BIT_SIZE (23)
#define EXPONENT_BIT_SIZE (8)
#define HEXA_BIT_SIZE (8)
#define TOTAL_BIT_SIZE (32)

void printBitFloat(float num);

int main(void)
{
	float num = 0;
	printf("Input a float number: ");
	scanf_s("%f", &num);
	printBitFloat(num);
	return 0;
}

void printBitFloat(float num)
{
	char sign = '1';
	if (num > 0) {
		sign = '0';
	}
	char integerArr[BUFFER_SIZE + 1];
	char floatArr[MANTISSA_BIT_SIZE + 1];
	int exp = (int)num;
	float floatingPart = num - exp;

	int index = 0;

	for (int i = 0; i < MANTISSA_BIT_SIZE; ++i) {
		floatArr[i] = '0';
	}

	floatArr[MANTISSA_BIT_SIZE] = '\0';

	while (exp != 0) {
		char bit = exp % 2 == 1 ? '1' : '0';
		integerArr[index++] = bit;
		exp /= 2;
	}

	int index2 = 0;
	int firstNoneZeroIndex = 0;
	while (floatingPart != 0.0 && index2 < MANTISSA_BIT_SIZE)
	{
		floatingPart *= 2;
		char bit = (int)floatingPart == 1 ? '1' : '0';
		floatArr[index2++] = bit;
		if (bit == '1' && firstNoneZeroIndex == 0)
		{
			firstNoneZeroIndex = index2;
		}
		floatingPart -= 1;
	}
	if (index > 0) {
		for (int i = MANTISSA_BIT_SIZE - 1 - (index - 1); i >= 0; --i) {
			floatArr[i + (index - 1)] = floatArr[i];
		}
	}
	else {
		for (int i = 0; i < MANTISSA_BIT_SIZE - 1 - firstNoneZeroIndex; ++i) {
			floatArr[i] = floatArr[i + firstNoneZeroIndex];
		}
	}
	
	int exponent = 0;
	if (index > 0)
	{
		exponent = index - 1 + 127;
	} else {
		exponent = 127 - firstNoneZeroIndex;
	}

	char exponentArr[EXPONENT_BIT_SIZE + 1];
	for (int i = 0; i < EXPONENT_BIT_SIZE; ++i) {
		exponentArr[i] = exponent % 2 == 1 ? '1' : '0';
		exponent /= 2;
	}

	exponentArr[EXPONENT_BIT_SIZE] = '\0';

	for (int i = index - 2, j = 0; i >= 0; --i, ++j) {
		floatArr[i] = integerArr[j];
	}

	char totalArr[TOTAL_BIT_SIZE + 1];
	totalArr[TOTAL_BIT_SIZE] = '\0';
	sprintf_s(totalArr, TOTAL_BIT_SIZE + 1, "%c%s%s", sign, exponentArr, floatArr);

	char hexaArr[HEXA_BIT_SIZE + 3];
	hexaArr[0] = '0';
	hexaArr[1] = 'x';
	hexaArr[HEXA_BIT_SIZE + 2] = '\0';
	int hexaIndex = 2;

	for (int i = 0; i < TOTAL_BIT_SIZE; i += 4) {
		int num = 0;
		int bitnum = 8;
		for (int j = 0; j < 4; ++j) {
			num += (totalArr[i + j] - '0') * bitnum;
			bitnum /= 2;
		}
		char temp;
		if (num < 10) {
			temp = '0' + num;
		}
		else {
			temp = 'A' + num - 10;
		}

		hexaArr[hexaIndex++] = temp;
	}

	char float1[4];
	float1[3] = '\0';
	for (int i = 0; i < 3; ++i) {
		float1[i] = floatArr[i];
	}
	char float2[5];
	float2[4] = '\0';
	for (int i = 0; i < 4; ++i) {
		float2[i] = floatArr[i + 3];
	}
	char float3[5];
	float3[4] = '\0';
	for (int i = 0; i < 4; ++i) {
		float3[i] = floatArr[i + 7];
	}
	char float4[5];
	float4[4] = '\0';
	for (int i = 0; i < 4; ++i) {
		float4[i] = floatArr[i + 11];
	}
	char float5[5];
	float5[4] = '\0';
	for (int i = 0; i < 4; ++i) {
		float5[i] = floatArr[i + 15];
	}
	char float6[5];
	float6[4] = '\0';
	for (int i = 0; i < 4; ++i) {
		float6[i] = floatArr[i + 19];
	}

	printf("%s\n", hexaArr);
	printf("+---+----------+------------------------------+\n");
	printf("| S | Exponent |            Mantisa           |\n");
	printf("+---+----------+------------------------------+\n");
	printf("| %c | %s | %s %s %s %s %s %s |\n", sign, exponentArr, float1, float2, float3, float4, float5, float6);
	printf("+---+----------+------------------------------+\n");
}