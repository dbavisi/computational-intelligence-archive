/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Standard implementation of BitMap data structure in C Programming Language.
 */

#include "structure/bitMap/definition/c/header.h"

/**
 * Set the bit at the specified index in the CIA_BITMAP buffer.
 * @param obj The CIA_BITMAP object.
 * @param index The index of the bit to be set.
 * @return The status of the operation.
 */
enum CIA_STATUS __CIA_BITMAP__set(CIA_BITMAP *const obj, const size_t const index)
{
  if (obj == NULL)
  {
    return CIA_FAILURE;
  }
  if (index < 0 || index >= obj->size)
  {
    return CIA_FAILURE;
  }
  const size_t byteIndex = index / 8;
  const size_t bitMask = 1 << (index % 8);
  obj->buffer[byteIndex] |= bitMask;
  return CIA_SUCCESS;
}

/**
 * Clear the bit at the specified index in the CIA_BITMAP buffer.
 * @param obj The CIA_BITMAP object.
 * @param index The index of the bit to be cleared.
 * @return The status of the operation.
 */
enum CIA_STATUS __CIA_BITMAP__clear(CIA_BITMAP *const obj, const size_t const index)
{
  if (obj == NULL)
  {
    return CIA_FAILURE;
  }
  if (index < 0 || index >= obj->size)
  {
    return CIA_FAILURE;
  }
  const size_t byteIndex = index / 8;
  const size_t bitMask = 1 << (index % 8);
  obj->buffer[byteIndex] &= ~bitMask;
  return CIA_SUCCESS;
}

/**
 * Test the bit at the specified index in the CIA_BITMAP buffer.
 * @param obj The CIA_BITMAP object.
 * @param index The index of the bit to be retrieved.
 * @return The bit at the specified index.
 */
uint8_t __CIA_BITMAP__test(const CIA_BITMAP *const obj, const size_t const index)
{
  if (obj == NULL)
  {
    return 0;
  }
  if (index < 0 || index >= obj->size)
  {
    return 0;
  }
  const size_t byteIndex = index / 8;
  const size_t bitMask = 1 << (index % 8);
  return (obj->buffer[byteIndex] & bitMask) != 0;
}

/**
 * Free the memory allocated to the CIA_BITMAP object.
 * @param obj The CIA_BITMAP object.
 * @return The status of the operation.
 */
enum CIA_STATUS __CIA_BITMAP__free(CIA_BITMAP *const obj)
{
  if (obj == NULL)
  {
    return CIA_FAILURE;
  }
  free(obj->buffer);
  free(obj);
  return CIA_SUCCESS;
}

/**
 * Create a new instance of CIA_BITMAP.
 * @param size The size of the buffer.
 * @return The new instance of CIA_BITMAP.
 */
CIA_BITMAP *__CIA_BITMAP_CLASS__new(const __CIA_BITMAP_CLASS *const cls, const size_t const size)
{
  if (size <= 0)
  {
    return NULL;
  }
  CIA_BITMAP *const obj = (CIA_BITMAP *)malloc(sizeof(CIA_BITMAP));
  if (obj == NULL)
  {
    return NULL;
  }
  obj->buffer = (uint8_t *)malloc(size);
  if (obj->buffer == NULL)
  {
    free(obj);
    return NULL;
  }
  obj->size = size;
  obj->set = &__CIA_BITMAP__set;
  obj->clear = &__CIA_BITMAP__clear;
  obj->test = &__CIA_BITMAP__test;
  obj->free = &__CIA_BITMAP__free;
  return obj;
}

// Class instance of CIA_BITMAP_CLASS.
const __CIA_BITMAP_CLASS const CIA_BITMAP_CLASS = {
    .new = &__CIA_BITMAP_CLASS__new,
};
