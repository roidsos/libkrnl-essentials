#include "ezgdt.h"
struct TSS tss = {
    0,                  //zero0
    0,0,0,              //the RSPs
    0,                  //zero1
    {0,0,0,0,0,0,0},    //IST(aka useless garbage)
    0,                  //zero2
    0,                  //zero3
    0                   //IOPB, no clue wtf it does
};

struct GDT DefaultGDT = {
    {0, 0, 0, 0b00000000, 0b00000000, 0}, // null
    {0, 0, 0, 0b10011010, 0b10100000, 0}, // ring 0 code segment
    {0, 0, 0, 0b10010010, 0b10100000, 0}, // ring 0 data segment
    {0, 0, 0, 0b10111010, 0b10100000, 0}, // ring 1 code segment
    {0, 0, 0, 0b10110010, 0b10100000, 0}, // ring 1 data segment
    {0, 0, 0, 0b11011010, 0b10100000, 0}, // ring 2 code segment
    {0, 0, 0, 0b11010010, 0b10100000, 0}, // ring 2 data segment
    {0, 0, 0, 0b11111010, 0b10100000, 0}, // ring 3 code segment
    {0, 0, 0, 0b11110010, 0b10100000, 0}, // ring 3 data segment
    {0,0,0,0,0,0,0,0}  // the TSS
};
void gdt_preload(){
    DefaultGDT.TSSEntry.Base0        = (uint16_t)((uint64_t)&tss & 0xffff);
    DefaultGDT.TSSEntry.Base1        = (uint8_t)(((uint64_t)&tss << 16) & 0xff);
    DefaultGDT.TSSEntry.Base1        = (uint8_t)(((uint64_t)&tss << 24) & 0xff);
    DefaultGDT.TSSEntry.Limit0       = sizeof(struct TSS) & 0xffff;
    DefaultGDT.TSSEntry.Limit1_Flags = (uint16_t)(((uint64_t)sizeof(struct TSS) & 0x0f) | 0x40);
    tss.IOBP = 104;
}