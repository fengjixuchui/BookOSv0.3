#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <sys/system.h>

void *malloc(int size);
void free(void *ptr);

void get_memory(int *size, int *free);

int execv(char *path, char *argv[]);

void exit(int status);
int _wait(int *status);

void clear();
void ps();

void reboot(int reboot_type);

int rand();
void srand(unsigned int seed);

int get_pid();
int get_ticks();
void sleep(u32 msec);



#endif
