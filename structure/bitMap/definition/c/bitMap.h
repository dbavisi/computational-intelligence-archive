/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 *  BitMap data structure definition in C Programming Language.
 */

#ifndef CIA_BITMAP_H
#define CIA_BITMAP_H

#include <stdint.h>
#include "include/c/ooc/ooc.h"

typedef struct __CIA_BITMAP_OBJECT__ CIA_BITMAP;
typedef struct __CIA_BITMAP_OBJECT__
{
  CIA_OBJECT;

  uint8_t *buffer;
  size_t size;

  enum CIA_STATUS (*set_bit)(CIA_BITMAP *const self, const size_t offset);
  enum CIA_STATUS (*clear_bit)(CIA_BITMAP *const self, const size_t offset);
  enum CIA_STATUS (*test_bit)(CIA_BITMAP *const self, const size_t offset);

  enum CIA_STATUS (*set_range)(CIA_BITMAP *const self, const size_t begin, const size_t end);
  enum CIA_STATUS (*clear_range)(CIA_BITMAP *const self, const size_t begin, const size_t end);
  enum CIA_STATUS (*test_range)(CIA_BITMAP *const self, const size_t begin, const size_t end);

} CIA_BITMAP;

typedef struct __CIA_BITMAP_CLASS__ __CIA_BITMAP_CLASS;
typedef struct __CIA_BITMAP_CLASS__
{
  CIA_CLASS;
} __CIA_BITMAP_CLASS;

extern const __CIA_BITMAP_CLASS const CIA_BITMAP_CLASS;

#endif // CIA_BITMAP_H
