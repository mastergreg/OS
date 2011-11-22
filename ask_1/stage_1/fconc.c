/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : fconc.c

 * Last Modified : Fri 18 Nov 2011 09:25:21 PM EET

 * Created By : Greg Liras <gregliras@gmail.com>

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include "fconc.h"

int main(int argc, char ** argv)
{
   int OUT;
   int TMP;
   int i;
   const char * output;
   int duplicate = 0;
   int W_FLAGS = O_CREAT | O_WRONLY | O_TRUNC;
   int C_PERMS = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ;
   struct flock lock;

   if (argc == 3)
   {
      output = "fconc.out";
   }
   else if (argc == 4)
   {
      output = argv[3];
   }
   else
   {
      perror("Usage: ./fconc infile1 infile2 [outfile (default:fconc.out)]\n");
      exit(EX_USAGE);
   }

   for (i=1; i<3; i++)
   {
      if (strcmp (argv[i], output) == 0)
      {
         duplicate = 1;
         break;
      }
   }

   if (duplicate)               //if outfile matches an infile, work on a tempfile
   {
      TMP = open("/tmp/fconc.out.tmp",W_FLAGS,C_PERMS);
      if (TMP < 0)
      {
         perror("Error opening tmp file, is another instance running?\n");
         exit(EX_TEMPFAIL);
      }

      fcntl(TMP,F_GETLK,lock);  //get lock info on fd
      lock.l_type = F_WRLCK;    //set lock to write lock
      fcntl(TMP,F_SETLK,lock);  //set the lock on fd
      write_file(TMP,argv[1]);  //write on fd
      write_file(TMP,argv[2]);
      lock.l_type = F_UNLCK;    //set lock to unlock
      fcntl(TMP,F_SETLK,lock);  //set the lock on fd
      close(TMP);               //close fd
      OUT = open(output,W_FLAGS,C_PERMS);

      if (OUT < 0)
      {
         perror("Error handling output file\n");
         exit(EX_IOERR);
      }
      fcntl(OUT,F_GETLK,lock);
      lock.l_type = F_WRLCK;
      fcntl(OUT,F_SETLK,lock);

      write_file(OUT,"/tmp/fconc.out.tmp");
      lock.l_type = F_UNLCK;
      fcntl(OUT,F_SETLK,lock);
      close (OUT);
      if (unlink("/tmp/fconc.out.tmp") != 0)
      {
         perror("Error deleting temporary file, please remove /tmp/fconc.out.tmp\n");
         exit(EX__BASE);
      }
   }

   else
   {
      OUT = open(output,W_FLAGS,C_PERMS);
      if (OUT < 0)
      {
         perror("Error handling output file\n");
         exit(EX_IOERR);
      }
      fcntl(OUT,F_GETLK,lock);
      lock.l_type = F_WRLCK;
      fcntl(OUT,F_SETLK,lock);

      {
         write_file(OUT,argv[1]);
         write_file(OUT,argv[2]);
      }
      lock.l_type = F_UNLCK;
      fcntl(OUT,F_SETLK,lock);
      close(OUT);
   }

   exit(EXIT_SUCCESS);
}

void doWrite(int fd,const char *buff,int len)
{
   int written = 0;
   int current = 0;
   do
   {
      if ( (current = write(fd,buff+written,len-written)) < 0 )
      {
         perror("Error in writing\n");
         exit(EX_IOERR);
      }
      written+=current;
   } while(written < len );
}


void write_file(int fd,const char *infile)
{
   int A;
   char buffer[BUFFER_SIZE];
   int chars_read=0;
   struct flock lock;
   A = open(infile,O_RDONLY);
   if (A ==-1)
   {
      char error_message[BUFFER_SIZE];
      sprintf(error_message,"%s",infile);
      perror(error_message);
      exit(EX_NOINPUT);
   }
   fcntl(A,F_GETLK,lock);  //get lock info on A
   lock.l_type = F_RDLCK;  //set lock to read lock
   fcntl(A,F_SETLK,lock);  //set lock on A
   //time to read
   while( (chars_read = read(A,buffer,BUFFER_SIZE)) > 0)
   {
      //and write
      doWrite(fd,buffer,chars_read);
   }
   if ( chars_read == -1 )
   {
      perror("Read Error\n");
      exit(EX_IOERR);
   }
   lock.l_type = F_UNLCK;  //set lock to unlock
   fcntl(A,F_SETLK,lock);  //set lock on A
   //ok close
   if ( close(A) == - 1 )
   {
      perror("Close Error\n");
      exit(EX_IOERR);
   }
}

