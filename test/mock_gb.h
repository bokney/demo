
#ifndef MOCK_GB_H
#define MOCK_GB_H

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

extern uint8_t BGP_REG;

void wait_vbl_done(void);
void delay(uint16_t d);

#endif