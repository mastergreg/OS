
/*
 * monitorsem.h
 *
 * An attempt to implement
 * semaphores over monitors.
 *
 * Vasilis Gerakaris 	<vgerak@gmail.com>
 * Grigoris Liras 		<gregliras@gmail.com>
 */

#ifndef MONITORSEM_H__
#define MONITORSEM_H__

struct pipesem {
	/*
	 * Two file descriptors:
	 * one for the read and one for the write end of a pipe
	 */
	int rfd;
	int wfd;
};

/*
 * Function prototypes
 */
void pipesem_init(struct pipesem *sem, int val);
void pipesem_wait(struct pipesem *sem);
void pipesem_signal(struct pipesem *sem);
void pipesem_destroy(struct pipesem *sem);

#endif /* PIPESEM_H__ */
