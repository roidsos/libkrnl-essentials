#include "ezgdt.h"

struct GDT DefaultGDT = {
    {0, 0, 0, 0b00000000, 0b00000000, 0}, // null
    {0, 0, 0, 0b10011010, 0b10100000, 0}, // ring 0 code segment
    {0, 0, 0, 0b10010010, 0b10100000, 0}, // ring 0 data segment
    {0, 0, 0, 0b10111010, 0b10100000, 0}, // ring 1 code segment
    {0, 0, 0, 0b10110010, 0b10100000, 0}, // ring 1 data segment
    {0, 0, 0, 0b11011010, 0b10100000, 0}, // ring 2 code segment
    {0, 0, 0, 0b11010010, 0b10100000, 0}, // ring 2 data segment
    {0, 0, 0, 0b11111010, 0b10100000, 0}, // ring 3 code segment
    {0, 0, 0, 0b11110010, 0b10100000, 0}  // ring 3 data segment
};