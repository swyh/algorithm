#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char s1[30];  // 크기가 30인 char형 배열을 선언하고 문자열 할당
	scanf("%s", s1);

	char *ptr = strtok(s1, "-");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

	while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
	{
		printf("%s\n", ptr);          // 자른 문자열 출력
		ptr = strtok(NULL, "-");      // 다음 문자열을 잘라서 포인터를 반환
	}

	return 0;
}