/*
 * File:   eeprom.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:43 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "eeprom.h"
#include "mcc_generated_files/mcc.h"

#define EEPROM_DEVICE_ADDRESS 0x50

void eeprom_read(int *state)
{
  // uint8_t receiveData[2];
  // uint8_t address[2] = {0x00, 0x00};
  // i2c_writeNBytes(0x50, address, 2);
  // i2c_readNBytes(0x50, receiveData, sizeof(receiveData));
}

void eeprom_write(int state)
{
  // uint8_t sendData[4] = {0x00, 0x00, 0x00, 0x00};

  // if (temp_sensor_enabled)
  // {
  //   sendData[2] = 0x01;
  // }
  // if (light_sensor_enabled)
  // {
  //   sendData[3] = 0x01;
  // }

  // i2c_writeNBytes(EEPROM_DEVICE_ADDRESS, sendData, sizeof(sendData));
  // __delay_ms(20);
}