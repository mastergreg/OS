/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : fconc.c

* Purpose :

* Creation Date : 20-12-2008

* Last Modified : Thu 10 Nov 2011 04:06:34 PM EET

* Created By : Greg Liras <gregliras@gmail.com>
 
* Created By : Vasilis Gerakaris <vgerak@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <unistd.h>
#include <fcntl.h>

#include "fconc.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

int main(int argc, char ** argv)
{
  int OUT;
  int W_FLAGS = O_CREAT | O_WRONLY | O_TRUNC;
  int C_PERMS = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ;
  if (argc < 3)
  {
    print_me("Usage: ./fconc infile1 infile2 [outfile (default:fconc.out)]\n");
    return -1;
  }
  if (argc > 3)
  {
    OUT = open(argv[3],W_FLAGS,C_PERMS);
  }
  else
  {
    OUT = open("fconc.out",W_FLAGS,C_PERMS);
  }
  if (OUT < 0)
  {
//    printf("Error handling output file\n");
    return -1;
  }


  write_file(OUT,argv[1]);
  write_file(OUT,argv[2]);


  return 0;
}

void doWrite(int fd,const char *buff,int len)
{
  if ( write(fd,buff,len) != len)
  {
//    printf("Error in writing\n");
  }
  
}


void write_file(int fd,const char *infile)
{
  int A;
  char buffer[BUFFER_SIZE];
  int chars_read=0;
  A = open(infile,O_RDONLY);
  if (A ==-1)
  {
//    printf("%s: No such file or directory\n",infile);
    return;
  }
  //time to read
  while( (chars_read = read(A,buffer,BUFFER_SIZE)) > 0)
  {
    doWrite(fd,buffer,chars_read);
  }
  if ( chars_read == -1 )
  {
    write(1,"Read Error\n",11);
  }

  if ( close(A) == - 1 )
  {
//    printf("Close Error\n");
  }

  
}

void print_me(const char *p)
{
  int len = 0;
  char *b = p;
  while( *b++ != '\0' ) len++;
  write(1,p,len);
}
