// adapted from shutterbug2000 and zoogie's memory pit

#include "payload.h"

typedef unsigned char u8;
typedef unsigned short u16;

int main() {
    u8 *payload_dest = (u8 *)0x02200000;

    for (int i = 0; i < sizeof(pit_loader); i++) {
        payload_dest[i] = pit_loader[i];
    }

    *(u16 *)0x400006C = 0;  // MASTER_BRIGHT SUB & TOP
    *(u16 *)0x400106C = 0;  //""

    ((void (*)())payload_dest)();
}