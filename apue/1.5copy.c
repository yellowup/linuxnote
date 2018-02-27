#include "apue.h"
#define BUFFSIZE 4096
int main (void)
{
  int n;
  char buf[BUFFSIZE];

  while ((n=read(STDIN_FILENO,buf,BUFFSIZE)) > 0)
    /* read() function 返回读取的字节数
     当到达文件的末尾时，返回 0，读取错误但会 -1.*/


    /* stdout_FILENO and STDIN_FILENO defined in unistd.h
     it's value is 0 and 1 STDERR_FILENO is 2 . */
    {
      if (write (STDOUT_FILENO,buf,n) != n)
        err_sys ("Write error");
    }

  if (n < 0)
    err_sys ("read error");
  exit (0);
}
