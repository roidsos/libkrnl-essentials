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

struct GDT {
    struct GDTEntry Null; //0x00
    struct GDTEntry Ring0Code; //0x08
    struct GDTEntry Ring0Data; //0x10
    struct GDTEntry Ring1Code;
    struct GDTEntry Ring1Data;
    struct GDTEntry Ring2Code;
    struct GDTEntry Ring2Data;
    struct GDTEntry Ring3Code;
    struct GDTEntry Ring3Data;
} __attribute__((packed));

void load_default_gdt();
#endif
