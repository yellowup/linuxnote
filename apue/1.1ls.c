#include"apue.h"
#include<dirent.h>
int main (int argc,char *argv[])
{
  DIR *dp;
  struct dirent *dirp;

  if (argc != 2)
    err_quit ("usage:ls directory_name");

  if ((dp = opendir (argv[1])) == NULL)
    /* opendir() function return a DIR struct type */
    err_sys ("Can't open %s",argv[1]);

  while ((dirp = readdir (dp)) != NULL)
    {
      printf ("%s\n", dirp->d_name);
      /* char d_name[256]; and not include limits.h(why)*/
      printf ("type is %s,\n reclen is %d\n",&dirp->d_type, &dirp->d_reclen);
      /* what's means of d_type and d_reclen */
    }
  closedir(dp);
  
  exit(0);
}
