/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * @header Header file for STANDARD implementation of CIA_BYTEARRAY.
 */

#ifndef CIA_BYTEARRAY_H
#define CIA_BYTEARRAY_H

#include "common.h"

typedef struct __CIA_BYTEARRAY__ CIA_BYTEARRAY;
typedef struct __CIA_BYTEARRAY_CLASS__ __CIA_BYTEARRAY_CLASS;

// Instance definition for CIA_BYTEARRAY.
typedef struct __CIA_BYTEARRAY__
{
  uint8_t *buffer;
  size_t size;

  /**
   * Retrieve the data stored in the CIA_BYTEARRAY buffer.
   * @param obj The CIA_BYTEARRAY object.
   * @param start The start index of the buffer.
   * @param end The end index of the buffer.
   * @return The data stored in the buffer.
   *
   * @note start and end are inclusive.
   * @note The caller is responsible for freeing the memory allocated to the buffer.
   */
  uint8_t *(*get)(const CIA_BYTEARRAY *obj, const size_t start, const size_t end);

  /**
   * Update the data stored in the CIA_BYTEARRAY buffer.
   * @param obj The CIA_BYTEARRAY object.
   * @param start The start index of the buffer.
   * @param data The data to be stored in the buffer.
   * @param size The size of the buffer.
   * @return The status of the operation.
   */
  enum CIA_STATUS (*set)(CIA_BYTEARRAY *obj, const size_t start, const uint8_t *data, const size_t size);

  /**
   * Free the memory allocated to the CIA_BYTEARRAY object.
   * @param obj The CIA_BYTEARRAY object.
   * @return The status of the operation.
   */
  enum CIA_STATUS (*free)(CIA_BYTEARRAY *obj);

  /**
   * Create a view from the CIA_BYTEARRAY object.
   * @param obj The CIA_BYTEARRAY object.
   * @param start The start index of the view.
   * @param end The end index of the view.
   * @return The view of the CIA_BYTEARRAY object.
   */
  CIA_BYTEARRAY *(*view)(const CIA_BYTEARRAY *obj, const size_t start, const size_t end);
} CIA_BYTEARRAY;

// Class definition for CIA_BYTEARRAY.
typedef struct __CIA_BYTEARRAY_CLASS__
{
  /**
   * Create a new instance of CIA_BYTEARRAY object with the given data
   * @param cls The class definition.
   * @param size The size of the data.
   * @param [data] The data to be stored in the object.
   * @return The newly created CIA_BYTEARRAYARRAY object.
   */
  CIA_BYTEARRAY *(*new)(const __CIA_BYTEARRAY_CLASS *cls, const size_t size, const uint8_t *data);
} __CIA_BYTEARRAY_CLASS;

// Global instance of CIA_BYTEARRAY_CLASS.
extern const __CIA_BYTEARRAY_CLASS CIA_BYTEARRAY_CLASS;

#endif // CIA_BYTEARRAY_H
