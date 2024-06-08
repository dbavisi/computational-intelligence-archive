/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * @header Tests for STANDARD implementation of CIA_BYTE.
 */

#include "structure/byte/standard/c/header.h"

int main(int argc, char **argv)
{
  enum CIA_STATUS status;
  CIA_BYTE *byte;
  uint8_t value;

  printf("Test for STANDARD implementation of CIA_BYTE\n");

  printf("Creating new CIA_BYTE object\n");
  byte = CIA_BYTE_CLASS.new(&CIA_BYTE_CLASS, 0x30);
  if (byte == NULL)
  {
    printf("Failed to create new CIA_BYTE object\n");
    return 1;
  }

  printf("Retrieving initial value from CIA_BYTE object\n");
  value = byte->get(byte);
  printf("Initial value: %d\n", value);
  if (value != 0x30)
  {
    printf("Initial value not as expected\n");
    return 1;
  }

  printf("Updating value in CIA_BYTE object\n");
  status = byte->set(byte, 0x40);
  value = byte->get(byte);
  printf("Value after update: %d\n", value);
  if (status != CIA_SUCCESS)
  {
    printf("Failed to update value in CIA_BYTE object\n");
    return 1;
  }
  if (value != 0x40)
  {
    printf("Value not as expected after update\n");
    return 1;
  }

  printf("Setting out-of-bounds value in CIA_BYTE object\n");
  status = byte->set(byte, 0x105);
  value = byte->get(byte);
  printf("Value after update: %d\n", value);
  if (status != CIA_SUCCESS)
  {
    printf("Failed to update value in CIA_BYTE object\n");
    return 1;
  }
  if (value != 0x05)
  {
    printf("Value not as expected after update\n");
    return 1;
  }

  printf("Freeing CIA_BYTE object\n");
  status = byte->free(byte);
  if (status != CIA_SUCCESS)
  {
    printf("Failed to free CIA_BYTE object\n");
    return 1;
  }

  return 0;
}
