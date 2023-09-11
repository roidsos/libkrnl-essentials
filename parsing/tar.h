#ifndef __TAR_H__
#define __TAR_H__

#ifndef HEAP_ACCESSABLE
#error "The tar parser requires the heap to work, sowwy :P"
#endif

#include <types/stdtypes.h>

struct tar_header
{
    uint8_t filename[100];
    uint8_t mode[8];
    uint8_t UID[8];
    uint8_t GID[8];
    uint8_t size[12];
    uint8_t mtime[12];
    uint8_t chksum[8];
    uint8_t typeflag;
};

struct tar_contents
{
    uint8_t hdr_num;
    struct tar_header** headers;
};

struct tar_header* find_file(struct tar_contents* findin,uint8_t* name);
struct tar_contents parse_tar(struct tar_header* header,uint64_t file_size);


#endif // __TAR_H__