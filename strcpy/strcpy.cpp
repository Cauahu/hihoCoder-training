#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>

using namespace std;

char * strcpy_(char * dest, const char * src)
{
	assert((dest != NULL) && (src != NULL));
	char * address = dest;
	while(*src != '\0')
		*dest++ = *src;
	return address;
}

int main()
{
	char s[] = "123456789";
	char d[] = "123";

	strcpy(d,s);
	printf("%s,%s\n",d,s);
	return 0;
}
