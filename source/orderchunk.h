#pragma once

#include "config.h"

struct Level;
struct Order;

struct OrderChunk {
    struct Level *level;
    struct OrderChunk *next, *prev;
    struct OrderNode {
        u64 orderID;
        u32 userID;
        u32 volume;
    } orders[ORDER_CHUNK_CAPACITY];
    u8 size, queue[ORDER_CHUNK_CAPACITY];
};

#define OrderChunk_Empty(chunk) ((chunk)->size == 0)
#define OrderChunk_Full(chunk) ((chunk)->size == ORDER_CHUNK_CAPACITY)

struct OrderChunk *OrderChunk_New(struct Level *level);
void OrderChunk_Delete(struct OrderChunk *chunk);
void OrderChunk_Add(struct OrderChunk *chunk, struct Order *order);
void OrderChunk_Pop(struct OrderChunk *chunk);
struct OrderNode *OrderChunk_Peek(struct OrderChunk *chunk);
