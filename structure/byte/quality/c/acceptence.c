/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Acceptence test for CIA_BYTE data structure in C Programming Language.
 */

#include <stdio.h>
#include "include/headers/c/debug.h"
#include "structure/byte/definition/c/header.h"

enum CIA_STATUS acceptence_test(void)
{
  enum CIA_STATUS status;
  CIA_BYTE *byte;
  uint8_t value;

  CIA_DEBUG_ENTER("Running acceptence test for CIA_BYTE data structure")

  CIA_DEBUG("Creating a new CIA_BYTE object with initial value 0x30")
  byte = CIA_BYTE_CLASS.new(&CIA_BYTE_CLASS, 0x30);

  if (byte == NULL)
  {
    CIA_ERROR("Failed to create CIA_BYTE object")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Validating initial value in CIA_BYTE object")
  value = byte->get(byte);
  CIA_DEBUG("Initial value: %d", value);

  if (value != 0x30)
  {
    CIA_ERROR("Initial value not as expected")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Setting value in CIA_BYTE object to 0x40")
  status = byte->set(byte, 0x40);
  value = byte->get(byte);
  CIA_DEBUG("Value after update: %d", value);

  if (status != CIA_SUCCESS)
  {
    CIA_ERROR("Failed to update value in CIA_BYTE object")
    return CIA_FAILURE;
  }

  if (value != 0x40)
  {
    CIA_ERROR("Value not as expected after update")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Setting value in CIA_BYTE object to 0x105")
  status = byte->set(byte, 0x105);
  value = byte->get(byte);
  CIA_DEBUG("Value after update: %d", value);

  if (status != CIA_SUCCESS)
  {
    CIA_ERROR("Failed to update value in CIA_BYTE object")
    return CIA_FAILURE;
  }

  if (value != 0x05)
  {
    CIA_ERROR("Value not as expected after update")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Freeing CIA_BYTE object")
  status = byte->free(byte);

  if (status != CIA_SUCCESS)
  {
    CIA_ERROR("Failed to free CIA_BYTE object")
    return CIA_FAILURE;
  }

  CIA_DEBUG_EXIT("Finished acceptence test for CIA_BYTE data structure")

  return CIA_SUCCESS;
}
