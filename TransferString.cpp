#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

char* TransferString(char* str,int capacity)
{
	char* ret = str;
	if (str == NULL || capacity <= 0)
	{
		return NULL;
	}
	int i = 0;
	int originalLen = 0;
	int numberofblank = 0;
	while (str[i])
	{
		
		if (str[i] == ' ')
		{
			numberofblank++;
		}
		originalLen++;
		i++;
	}
	int newLen = originalLen + 2 * numberofblank;
	if (newLen >= capacity)
	{
		return NULL; 
	}
	while (newLen>originalLen && originalLen >=0)
	{
		if (str[originalLen] == ' ')
		{
			str[newLen--] = '0';
			str[newLen--] = '2';
			str[newLen--] = '%';
		}
		else
		{
			str[newLen] = str[originalLen];
			newLen--;
		}
		originalLen--;
		
	}
	return ret;
}


void Test()
{
	char arr[30] = "We are happy!";
	cout << TransferString(arr,30)<<endl;
}

int main()
{
	Test();
	system("pause");
	return 0;
}