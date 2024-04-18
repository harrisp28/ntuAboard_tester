#ifndef __THERMOMETER_H
#define __THERMOMETER_H

#include<stdint.h>

int16_t get_temperature(void);
float get_temperature_f(void);
void temp_to_char(char * buffer); 

#endif
