#include <stdio.h>

#define TRUE 1
#define FALSE 0

int check_overlap_string(char string[])
{
    int i;
    char temp[256] = {0,};

    for (i = 0; string[i] != '\0'; ++i){
	
	if (temp[string[i]] == 1) {
	    return TRUE;
	}
	else {
	    temp[string[i]] = 1;
	}
    }

    return FALSE;
}

int main()
{
    char string[] = {"abcdaefg"};
    printf("%d\n", check_overlap_string(string));

    return 0;
}
