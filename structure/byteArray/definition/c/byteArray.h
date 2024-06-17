/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Byte Array data structure definition in C Programming Language.
 */

#ifndef CIA_BYTEARRAY_H
#define CIA_BYTEARRAY_H

#include <stdint.h>
#include "include/c/ooc/ooc.h"

typedef struct __CIA_BYTEARRAY_OBJECT__ CIA_BYTEARRAY;
typedef struct __CIA_BYTEARRAY_OBJECT__
{
  CIA_OBJECT;

  uint8_t *buffer;
  size_t length;

  uint8_t isView;

  enum CIA_STATUS (*get_byte)(CIA_BYTEARRAY *const self, const size_t index, uint8_t *byte);
  enum CIA_STATUS (*set_byte)(CIA_BYTEARRAY *const self, const size_t index, const uint8_t byte);

  enum CIA_STATUS (*get_range)(CIA_BYTEARRAY *const self, const size_t begin, const size_t end, uint8_t *range);
  enum CIA_STATUS (*set_range)(CIA_BYTEARRAY *const self, const size_t begin, const size_t end, const uint8_t *range);

  CIA_BYTEARRAY *(*view)(CIA_BYTEARRAY *const self, const size_t begin, const size_t end);
} CIA_BYTEARRAY;

typedef struct __CIA_BYTEARRAY_CLASS__ __CIA_BYTEARRAY_CLASS;
typedef struct __CIA_BYTEARRAY_CLASS__
{
  CIA_CLASS;
} __CIA_BYTEARRAY_CLASS;

extern const __CIA_BYTEARRAY_CLASS const CIA_BYTEARRAY_CLASS;

#endif // CIA_BYTEARRAY_H
