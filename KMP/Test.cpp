#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cstring>
using namespace std;

int* buildNext(string str)
{
	int* next = new int[str.length()];
	next[0] = 0;
	int prefix_len = 0;
	int i = 1;
	while (i < str.length())
	{
		if (str[prefix_len] == str[i])
		{
			prefix_len++;
			next[i] = prefix_len;
			i++;
		}
		else
		{
			if (prefix_len == 0) 
			{ 
				next[i] = 0; 
				i++;
			}
			else
			{
				prefix_len = next[prefix_len - 1];
			}
		}
	}
	/*for (int i = 0; i < str.length(); i++)
	{
		cout << next[i] << " ";
	}
	cout << endl;*/
	return next;
}
//»ù´¡Ñ§Ï°
bool kmp(string str, string substr)
{
	int* next = buildNext(substr);
	int i = 0, j = 0;
	while (i<str.length())
	{
		if (str[i] == substr[j])
		{
			i++;
			j++;
		}
		else if (j > 0)
		{
			j = next[j - 1];
		}
		else
		{
			i++;
		}
		if (j == substr.length())
		{
			cout << "true" << endl;
			break;
		}
	}
	delete[] next;
	if (j == substr.length())
	{
		return true;
	}
	cout << "false" << endl;
	return false;
}

void call()
{
	string str, substr;
	cin >> str;
	cin >> substr;
	kmp(str, substr);
	buildNext(substr);
}





int main()
{
	call();
	return 0;
}

