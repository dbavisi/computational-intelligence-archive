/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Standard implementation of BitMap data structure in C Programming Language.
 */

#include <stdint.h>
#include <stdarg.h>
#include "include/c/ooc/ooc.h"
#include "structure/bitMap/definition/c/bitMap.h"

enum CIA_STATUS __CIA_BITMAP_OBJECT__free(void *const self)
{
  CIA_BITMAP *const obj = (CIA_BITMAP *)self;
  free(obj->buffer);
  free(obj);
  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BITMAP_OBJECT__set_bit(CIA_BITMAP *const self, const size_t offset)
{
  if (offset >= self->size)
  {
    return CIA_FAILURE;
  }
  self->buffer[offset / 8] |= (1 << (7 - (offset % 8)));
  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BITMAP_OBJECT__clear_bit(CIA_BITMAP *const self, const size_t offset)
{
  if (offset >= self->size)
  {
    return CIA_FAILURE;
  }
  self->buffer[offset / 8] &= ~(1 << (7 - (offset % 8)));
  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BITMAP_OBJECT__test_bit(CIA_BITMAP *const self, const size_t offset)
{
  if (offset >= self->size)
  {
    return CIA_FAILURE;
  }
  return (self->buffer[offset / 8] & (1 << (7 - (offset % 8))) ? CIA_SUCCESS : CIA_FAILURE);
}

enum CIA_STATUS __CIA_BITMAP_OBJECT__set_range(CIA_BITMAP *const self, const size_t begin, const size_t end)
{
  if (end >= self->size || begin > end)
  {
    return CIA_FAILURE;
  }

  const size_t begin_byte = begin / 8;
  const uint8_t begin_mask = 0xFF >> (begin % 8);
  const size_t end_byte = end / 8;
  const uint8_t end_mask = 0xFF << (7 - (end % 8));

  if (begin_byte == end_byte)
  {
    self->buffer[begin_byte] |= (begin_mask & end_mask);
  }
  else
  {
    self->buffer[begin_byte] |= begin_mask;
    for (size_t i = begin_byte + 1; i < end_byte; i += 1)
    {
      self->buffer[i] = 0xFF;
    }
    self->buffer[end_byte] |= end_mask;
  }

  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BITMAP_OBJECT__clear_range(CIA_BITMAP *const self, const size_t begin, const size_t end)
{
  if (end >= self->size || begin > end)
  {
    return CIA_FAILURE;
  }

  const size_t begin_byte = begin / 8;
  const uint8_t begin_mask = 0xFF >> (begin % 8);
  const size_t end_byte = end / 8;
  const uint8_t end_mask = 0xFF << (7 - (end % 8));

  if (begin_byte == end_byte)
  {
    self->buffer[begin_byte] &= ~(begin_mask & end_mask);
  }
  else
  {
    self->buffer[begin_byte] &= ~begin_mask;
    for (size_t i = begin_byte + 1; i < end_byte; i += 1)
    {
      self->buffer[i] = 0x00;
    }
    self->buffer[end_byte] &= ~end_mask;
  }

  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BITMAP_OBJECT__test_range(CIA_BITMAP *const self, const size_t begin, const size_t end)
{
  if (end >= self->size || begin > end)
  {
    return CIA_FAILURE;
  }

  const size_t begin_byte = begin / 8;
  const uint8_t begin_mask = 0xFF >> (begin % 8);
  const size_t end_byte = end / 8;
  const uint8_t end_mask = 0xFF << (7 - (end % 8));

  if (begin_byte == end_byte)
  {
    const uint8_t mask = begin_mask & end_mask;
    return ((self->buffer[begin_byte] & mask) == mask ? CIA_SUCCESS : CIA_FAILURE);
  }
  else
  {
    if ((self->buffer[begin_byte] & begin_mask) != begin_mask)
    {
      return CIA_FAILURE;
    }
    for (size_t i = begin_byte + 1; i < end_byte; i += 1)
    {
      if (self->buffer[i] != 0xFF)
      {
        return CIA_FAILURE;
      }
    }
    return ((self->buffer[end_byte] & end_mask) == end_mask ? CIA_SUCCESS : CIA_FAILURE);
  }
}

void *__CIA_BITMAP_CLASS__new(const void *const cls, ...)
{
  CIA_BITMAP *const obj = (CIA_BITMAP *)malloc(((CIA_CLASS *)cls)->size);
  if (obj == NULL)
  {
    return NULL;
  }

  va_list args;
  va_start(args, cls);
  obj->size = va_arg(args, const size_t);
  va_end(args);

  obj->buffer = (uint8_t *)calloc((obj->size + 7) / 8, sizeof(uint8_t));
  if (obj->buffer == NULL)
  {
    free(obj);
    return NULL;
  }

  obj->free = __CIA_BITMAP_OBJECT__free;
  obj->set_bit = __CIA_BITMAP_OBJECT__set_bit;
  obj->clear_bit = __CIA_BITMAP_OBJECT__clear_bit;
  obj->test_bit = __CIA_BITMAP_OBJECT__test_bit;
  obj->set_range = __CIA_BITMAP_OBJECT__set_range;
  obj->clear_range = __CIA_BITMAP_OBJECT__clear_range;
  obj->test_range = __CIA_BITMAP_OBJECT__test_range;
  return (void *)obj;
}

const __CIA_BITMAP_CLASS const CIA_BITMAP_CLASS = {
    .size = sizeof(CIA_BITMAP),
    .new = __CIA_BITMAP_CLASS__new,
};
