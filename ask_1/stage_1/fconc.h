/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : fconc.h

* Last Modified : Thu Nov 24 11:37:08 2011

* Created By : Greg Liras <gregliras@gmail.com>

* Created By : Vasilis Gerakaris <vgerak@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#ifndef FCONC_H
#define FCONC_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif //BUFFER_SIZE

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <sysexits.h>
#include <string.h>

void doWrite(int fd, const char *buff, int len);
void write_file(int fd, const char *infile);
#endif //FCONC_H
