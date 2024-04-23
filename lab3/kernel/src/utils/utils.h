#ifndef UTILS_H
#define UTILS_H

#include "base.h"

void utils_delay(unsigned long cycle);

unsigned long utils_atoi(const char *s, int char_size);
void utils_align(void *size, unsigned int s);
int utils_strncmp(const char* str1, const char* str2, unsigned int len);
U32 utils_transferEndian(U32 value);
U32 utils_align_up(U32 size, int alignment);
U64 utils_strlen(const char *s);

#endif