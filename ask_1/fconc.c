/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : fconc.c

* Purpose :

* Creation Date : 20-12-2008

* Last Modified : Thu 10 Nov 2011 02:07:34 PM EET

* Created By : Greg Liras <gregliras@gmail.com>
 
* Created By : Vasilis Gerakaris <vgerak@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <fcntl.h>

#include "fconc.h"

int main(int argc, char ** argv)
{
  FILE *A;
  FILE *B;
  FILE *OUT;
  if (argc < 3)
  {
    printf("Usage: ./fconc infile1 infile2 [outfile (default:fconc.out)]\n");
    return -1;
  }
  A = fopen(argv[1],"r");
  if (A < 0)
  {
    printf("%s: No such file or directory\n",argv[1]);
    return -1;
  }
  B = fopen(argv[2],"r");
  if (B < 0)
  {
    printf("%s: No such file or directory\n",argv[2]);
    return -1;
  }
  if (argc > 3)
  {
    OUT = fopen(argv[3],"w");
  }
  else
  {
    OUT = fopen("fconc.out","w");
  }
  if (OUT < 0)
  {
    printf("Error handling output file\n");
    return -1;
  }

  doWrite();



  return 0;
}

