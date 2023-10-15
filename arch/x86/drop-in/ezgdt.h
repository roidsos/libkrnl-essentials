#ifndef GDT_H
#define GDT_H
#include <types/stdtypes.h>

struct GDTDescriptor {
    uint16_t Size;
    uint64_t Offset;
} __attribute__((packed));

struct GDTEntry {
    uint16_t Limit0;
    uint16_t Base0;
    uint8_t Base1;
    uint8_t AccessByte;
    uint8_t Limit1_Flags;
    uint8_t Base2;
}__attribute__((packed));
struct GDTEntryTSS {
    uint16_t Limit0;
    uint16_t Base0;
    uint8_t Base1;
    uint8_t AccessByte;
    uint8_t Limit1_Flags;
    uint8_t Base2;
    uint32_t MoerBase;
    uint32_t zero;
}__attribute__((packed));

struct TSS{
    uint32_t zero0;
    uint64_t rsp_ring_0;
    uint64_t rsp_ring_1;
    uint64_t rsp_ring_2;
    uint64_t zero1;
    uint64_t IST[7];
    uint64_t zero3;
    uint16_t zero4;
    uint16_t IOBP;
}__attribute__((packed));

struct GDT {
    struct GDTEntry Null; //0x00
    struct GDTEntry Ring0Code; //0x08
    struct GDTEntry Ring0Data; //0x18
    struct GDTEntry Ring1Code; //0x20
    struct GDTEntry Ring1Data; //0x28
    struct GDTEntry Ring2Code; //0x30
    struct GDTEntry Ring2Data; //0x38
    struct GDTEntry Ring3Code; //0x40
    struct GDTEntry Ring3Data; //0x48
    struct GDTEntryTSS TSSEntry; //0x50
} __attribute__((packed));

void load_default_gdt();
#endif
