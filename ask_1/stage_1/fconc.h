/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : fconc.h

* Last Modified : Sun 13 Nov 2011 05:31:09 PM EET

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
#include <stdlib.h>

void doWrite(int fd, const char *buff, int len);
void write_file(int fd, const char *infile);
void print_err(const char *p);
#endif //FCONC_H
