#ifndef __ENCODER_H
#define __ENCODER_H


void EncoderInit(void);
// 返回每次的变化值
uint16_t EncoderDiff_Get(void);

#endif
