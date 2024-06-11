/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Definition of BitMap data structure in C Programming Language.
 */

#ifndef CIA_BITMAP_H
#define CIA_BITMAP_H

#include "common.h"

typedef struct __CIA_BITMAP__ CIA_BITMAP;
typedef struct __CIA_BITMAP_CLASS__ __CIA_BITMAP_CLASS;

// Definition for instance of CIA_BITMAP.
typedef struct __CIA_BITMAP__
{
  uint8_t *buffer;
  size_t size;

  /**
   * Set the bit at the specified index in the CIA_BITMAP buffer.
   * @param obj The CIA_BITMAP object.
   * @param index The index of the bit to be set.
   * @return The status of the operation.
   */
  enum CIA_STATUS (*set)(CIA_BITMAP *const obj, const size_t const index);

  /**
   * Clear the bit at the specified index in the CIA_BITMAP buffer.
   * @param obj The CIA_BITMAP object.
   * @param index The index of the bit to be cleared.
   * @return The status of the operation.
   */
  enum CIA_STATUS (*clear)(CIA_BITMAP *const obj, const size_t const index);

  /**
   * Test the bit at the specified index in the CIA_BITMAP buffer.
   * @param obj The CIA_BITMAP object.
   * @param index The index of the bit to be retrieved.
   * @return The bit at the specified index.
   */
  uint8_t (*test)(const CIA_BITMAP *const obj, const size_t const index);

  /**
   * Free the memory allocated to the CIA_BITMAP object.
   * @param obj The CIA_BITMAP object.
   * @return The status of the operation.
   *
   * @note Freeing the object will also free the memory allocated to the buffer.
   */
  enum CIA_STATUS (*free)(CIA_BITMAP *const obj);
} CIA_BITMAP;

// Definition for class of CIA_BITMAP.
typedef struct __CIA_BITMAP_CLASS__
{
  /**
   * Create a new instance of CIA_BITMAP.
   * @param size The size of the buffer.
   * @return The new instance of CIA_BITMAP.
   */
  CIA_BITMAP *(*new)(const __CIA_BITMAP_CLASS *const cls, const size_t const size);
} __CIA_BITMAP_CLASS;

// Global instance of CIA_BITMAP_CLASS.
extern const __CIA_BITMAP_CLASS CIA_BITMAP_CLASS;

#endif // CIA_BITMAP_H
