#include <bits/stdc++.h>
using namespace std; 
#define OUT 0 
#define IN 1 
unsigned cw(char *s) 
{ 
	int flag = OUT; 
	unsigned c = 0; 
	while (*s) 
	{ 
		if (*s == ' ' || *s == '\n' || *s == '\t') 
			flag = OUT; 
		else if (flag == OUT) 
		{ 
			flag = IN; 
			++c; 
		} 
		++s; 
	} 

	return c; 
} 

int main() 
{ 
	int x=0,i;
	char s[100]; 
	gets(s);
	for( i=0; s[i] != '\0'; i++){
		x++;
    }
    cout<<x<<endl;
	cout<<cw(s); 
	return 0; 
} 



