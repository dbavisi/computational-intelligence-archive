/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Acceptence test for CIA_BYTEARRAY data structure in C Programming Language.
 */

#include <stdio.h>
#include "include/headers/c/debug.h"
#include "structure/byteArray/definition/c/header.h"

enum CIA_STATUS acceptence_test(void)
{
  enum CIA_STATUS status;
  CIA_BYTEARRAY *byteArray;
  CIA_BYTEARRAY *viewLeft;
  CIA_BYTEARRAY *viewRight;
  uint8_t *buffer;
  int value;

  CIA_DEBUG_ENTER("Running acceptence test for CIA_BYTEARRAY data structure")

  CIA_DEBUG("Creating a new CIA_BYTEARRAY object with initial size 5")
  byteArray = CIA_BYTEARRAY_CLASS.new(&CIA_BYTEARRAY_CLASS, 5, NULL);

  if (byteArray == NULL)
  {
    CIA_ERROR("Failed to create CIA_BYTEARRAY object")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Validating initial size of CIA_BYTEARRAY object")
  value = byteArray->size;
  CIA_DEBUG("Initial size: %d", value);

  if (value != 5)
  {
    CIA_ERROR("Initial size not as expected")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Validating initial buffer of CIA_BYTEARRAY object")

  if (byteArray->buffer == NULL)
  {
    CIA_ERROR("Initial buffer not as expected")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Validating initial buffer values of CIA_BYTEARRAY object")

  for (int i = 0; i < byteArray->size; i += 1)
  {
    if (byteArray->buffer[i] != 0)
    {
      CIA_ERROR("Initial buffer value not as expected")
      return CIA_FAILURE;
    }
  }

  CIA_DEBUG("Setting value in CIA_BYTEARRAY object [2] to 0x40, [3] to 0x50")
  buffer = byteArray->get(byteArray, 2, 3);
  buffer[0] = 0x40;
  buffer[1] = 0x50;
  status = byteArray->set(byteArray, 2, buffer, 2);

  if (status != CIA_SUCCESS)
  {
    CIA_ERROR("Failed to update value in CIA_BYTEARRAY object")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Validating buffer values after update")
  value = byteArray->buffer[2];
  CIA_DEBUG("Value at index 2: %d", value);

  if (value != 0x40)
  {
    CIA_ERROR("Value not as expected after update")
    return CIA_FAILURE;
  }

  value = byteArray->buffer[3];
  CIA_DEBUG("Value at index 3: %d", value);

  if (value != 0x50)
  {
    CIA_ERROR("Value not as expected after update")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Creating view of CIA_BYTEARRAY object from index 1 to 3")
  viewLeft = byteArray->view(byteArray, 0, 2);

  if (viewLeft == NULL)
  {
    CIA_ERROR("Failed to create view of CIA_BYTEARRAY object")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Creating view of CIA_BYTEARRAY object from index 2 to 4")
  viewRight = byteArray->view(byteArray, 2, 4);

  if (viewRight == NULL)
  {
    CIA_ERROR("Failed to create view of CIA_BYTEARRAY object")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Setting value at index [2] to 0x60")
  buffer[0] = 0x60;
  status = viewLeft->set(viewLeft, 2, buffer, 1);

  if (status != CIA_SUCCESS)
  {
    CIA_ERROR("Failed to update value in CIA_BYTEARRAY object")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Validating buffer values after update")

  value = byteArray->buffer[2];
  CIA_DEBUG("Value at index 2: %d", value);

  if (value != 0x60)
  {
    CIA_ERROR("Value not as expected after update")
    return CIA_FAILURE;
  }

  value = viewLeft->buffer[2];
  CIA_DEBUG("Value at index 2: %d", value);

  if (value != 0x60)
  {
    CIA_ERROR("Value not as expected after update")
    return CIA_FAILURE;
  }

  value = viewRight->buffer[0];
  CIA_DEBUG("Value at index 0: %d", value);

  if (value != 0x60)
  {
    CIA_ERROR("Value not as expected after update")
    return CIA_FAILURE;
  }

  CIA_DEBUG("Freeing CIA_BYTEARRAY object")
  status = byteArray->free(byteArray);

  if (status != CIA_SUCCESS)
  {
    CIA_ERROR("Failed to free CIA_BYTEARRAY object")
    return CIA_FAILURE;
  }

  CIA_DEBUG_EXIT("Finished acceptence test for CIA_BYTEARRAY data structure")

  return CIA_SUCCESS;
}
