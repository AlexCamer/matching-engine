#pragma once

#include <stdlib.h>
#include "types.h"

void *Malloc(usize size);
void *Calloc(usize size, usize elementSize);
void *Realloc(void *ptr, usize size);
void Free(void *ptr);
