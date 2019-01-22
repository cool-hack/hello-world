#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
FILE *read_fp;
char buffer[BUFSIZ + 1];
int chars_read;
memset(buffer, ‘\0’, sizeof(buffer));
read_fp = popen(“uname -a”, “r”);
if (read_fp != NULL) {
chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
if (chars_read > 0) {
printf(“Output was:-\n%s\n”, buffer);
}
pclose(read_fp);
exit(EXIT_SUCCESS);
}
exit(EXIT_FAILURE);
}


/* output- 
Output was:-
Linux suse103 2.6.20.2-2-default #1 SMP Fri Mar 9 21:54:10 UTC 2007 i686 i686 i386
GNU/Linux

*/
