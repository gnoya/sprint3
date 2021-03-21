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

void eeprom_read_state(int *state)
{
  uint8_t receiveData[2];
  uint8_t address[2] = {0x00, 0x00};
  i2c_writeNBytes(EEPROM_DEVICE_ADDRESS, address, 2);
  i2c_readNBytes(EEPROM_DEVICE_ADDRESS, receiveData, sizeof(receiveData));
  *state = receiveData[0];
}

void eeprom_write_state(int state)
{
  uint8_t sendData[3] = {0x00, 0x00, 0x00};
  sendData[2] = state;
  i2c_writeNBytes(EEPROM_DEVICE_ADDRESS, sendData, sizeof(sendData));
  __delay_ms(20);
}