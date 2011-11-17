/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : fconc.c

* Last Modified : Thu 17 Nov 2011 02:58:23 AM EET

* Created By : Greg Liras <gregliras@gmail.com>
 
* Created By : Vasilis Gerakaris <vgerak@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include "fconc.h"

int main(int argc, char ** argv)
{
  int OUT;
  int TMP;
  int W_FLAGS = O_CREAT | O_WRONLY | O_TRUNC;
  int C_PERMS = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ;
  int counter=0;
  if (argc < 3)
  {
    print_err("Usage: ./fconc infile1 infile2 [outfile (default:fconc.out)]\n");
  }
  TMP = open("/tmp/fconc.out.tmp",W_FLAGS,C_PERMS);
  if (TMP < 0)
  {
    print_err("Error handling tmp file, is another instance running?\n");
  }
  for(counter = 1 ; counter < argc-1 ; counter++ )
  {
    write_file(TMP,argv[counter]);
  }
  close(TMP);
  if (argc > 3)
  {
    OUT = open(argv[argc-1],W_FLAGS,C_PERMS);
  }
  else
  {
    OUT = open("fconc.out",W_FLAGS,C_PERMS);
  }
  if (OUT < 0)
  {
    print_err("Error handling output file\n");
  }
  write_file(OUT,"/tmp/fconc.out.tmp");
  if (unlink("/tmp/fconc.out.tmp") != 0)
  {
    print_err("Error deleting temporary file, please remove /tmp/fconc.out.tmp\n");
  }
  exit(EXIT_SUCCESS);
}

void doWrite(int fd,const char *buff,int len)
{
  int written;
  do
  {
    if ( (written = write(fd,buff,len)) < 0 )
    {
      print_err("Error in writing\n");
    }
  } while(written < len );
}


void write_file(int fd,const char *infile)
{
  int A;
  char buffer[BUFFER_SIZE];
  int chars_read=0;
  A = open(infile,O_RDONLY);
  if (A ==-1)
  {
    print_err("No such file or directory\n");
  }
  //time to read
  while( (chars_read = read(A,buffer,BUFFER_SIZE)) > 0)
  {
    //and write
    doWrite(fd,buffer,chars_read);
  }
  if ( chars_read == -1 )
  {
    print_err("Read Error\n");
  }
  //ok close
  if ( close(A) == - 1 )
  {
    print_err("Close Error\n");
  }
}

void print_err(const char *p)
{
  int len = 0;
  const char *b = p;
  while( *b++ != '\0' ) len++;
  doWrite(2,p,len); //doWrite to stderr
  exit(-1);
}
