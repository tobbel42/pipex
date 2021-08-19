#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *test = "/bin/cat";
	printf("%d\n", access(test, X_OK));
}