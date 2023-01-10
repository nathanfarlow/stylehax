// adapted from shutterbug2000 and zoogie's memory pit

typedef unsigned char u8;
typedef unsigned short u16;

#include "payload.h"

int main() {
    u8 *payload_dest = (u8 *)0x02200000;

    for (int i = 0; i < sizeof(mini_twl_payload); i++) {
        payload_dest[i] = mini_twl_payload[i];
    }

    *(u16 *)0x400006C = 0;  // MASTER_BRIGHT SUB & TOP
    *(u16 *)0x400106C = 0;  //""

    ((void (*)())payload_dest)();
}