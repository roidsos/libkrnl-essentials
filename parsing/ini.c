#ifdef HEAP_ACCESSABLE
#include "ini.h"
#include <types/string.h>
#include <types/vector.h>
#include <arch/x86/essential.h>
#include <utils/heapdef.h>

vector_static(struct key_value_pair,kvps);

struct parsed_ini parse_ini(char* string)
{
    vector_init(&kvps);
    char currtag[255];
    uint8_t eqindex = 0;
    char** splitstring = split(string,'\n');
    for (size_t i = 0; splitstring[i]; i++)
    {
       if (splitstring[i][0] == '[')
       {
        for (int j = 1; j < strlen(splitstring[i]) - 1; j++)
        {
            if(splitstring[i][j] == ']'){
                currtag[j - 1] = 0;
            }else{
                currtag[j - 1] = splitstring[i][j];
            }
        }
        
       }else
       {
        struct key_value_pair kvp;
            for (int j = 0; j < strlen(splitstring[i]); j++)
            {
                 if(splitstring[i][j] == '='){
                     eqindex = i;
                     break;
                 }
            }
        kvp.key = (char*)malloc(strlen(currtag) + eqindex + 2);
        memcpy(&kvp.key,currtag,strlen(currtag));
        kvp.key[strlen(currtag)] = '.';
        memcpy(&kvp.key + strlen(currtag) + 1,splitstring[i],eqindex);
        kvp.key[eqindex] = 0;

        kvp.value = (char*)malloc(strlen(splitstring[i]) - eqindex);
        memcpy(&kvp.value,&splitstring[i][eqindex + 1],strlen(splitstring[i]) - eqindex - 1);
        kvp.value[strlen(splitstring[i]) - eqindex] = 0;

        vector_push_back(&kvps,kvp);
       }
    }
    struct parsed_ini pini;
    pini.count = vector_length(&kvps);
    pini.data = kvps.data;
    return pini;
}
#endif