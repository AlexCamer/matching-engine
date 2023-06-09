#pragma once

struct OrderBase;

struct Trade {
    char symbol[8];
    u64 buyOrderID;
    u64 sellOrderID;
    u32 buyUserID;
    u32 sellUserID;
    u32 volume;
    u32 price;
};

void Trade_Handle(struct Trade *trade);
//void Trade_Construct(struct Trade *trade, struct OrderBase *order1, struct OrderBase *order2);
