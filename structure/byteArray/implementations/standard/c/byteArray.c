/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Standard implementation of ByteArray data structure in C Programming Language.
 */

#include <stdint.h>
#include <stdarg.h>
#include "include/c/ooc/ooc.h"
#include "structure/byteArray/definition/c/byteArray.h"

enum CIA_STATUS __CIA_BYTEARRAY_OBJECT__free(void *const self)
{
  CIA_BYTEARRAY *const obj = (CIA_BYTEARRAY *)self;
  if (!obj->isView)
  {
    free(obj->buffer);
  }
  free(obj);
  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BYTEARRAY_OBJECT__get_byte(CIA_BYTEARRAY *const self, const size_t index, uint8_t *byte)
{
  if (index >= self->length)
  {
    return CIA_FAILURE;
  }
  *byte = self->buffer[index];
  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BYTEARRAY_OBJECT__set_byte(CIA_BYTEARRAY *const self, const size_t index, const uint8_t byte)
{
  if (index >= self->length)
  {
    return CIA_FAILURE;
  }
  self->buffer[index] = byte;
  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BYTEARRAY_OBJECT__get_range(CIA_BYTEARRAY *const self, const size_t begin, const size_t end, uint8_t *range)
{
  if (end >= self->length || begin > end)
  {
    return CIA_FAILURE;
  }
  if (range == NULL)
  {
    range = (uint8_t *)malloc(end - begin + 1);
    if (range == NULL)
    {
      return CIA_FAILURE;
    }
  }
  for (size_t i = begin; i <= end; i += 1)
  {
    range[i - begin] = self->buffer[i];
  }
  return CIA_SUCCESS;
}

enum CIA_STATUS __CIA_BYTEARRAY_OBJECT__set_range(CIA_BYTEARRAY *const self, const size_t begin, const size_t end, const uint8_t *range)
{
  if (end >= self->length || begin > end)
  {
    return CIA_FAILURE;
  }
  for (size_t i = begin; i <= end; i += 1)
  {
    self->buffer[i] = range[i - begin];
  }
  return CIA_SUCCESS;
}

CIA_BYTEARRAY *__CIA_BYTEARRAY_OBJECT__view(CIA_BYTEARRAY *const self, const size_t begin, const size_t end)
{
  CIA_BYTEARRAY *const view = (CIA_BYTEARRAY *)CIA_BYTEARRAY_CLASS.new(&CIA_BYTEARRAY_CLASS, 0, 1);
  if (view == NULL)
  {
    return NULL;
  }

  view->buffer = self->buffer + begin;
  view->length = end - begin + 1;

  return view;
}

void *__CIA_BYTEARRAY_CLASS__new(const void *const cls, ...)
{
  CIA_BYTEARRAY *const obj = (CIA_BYTEARRAY *)malloc(((CIA_CLASS *)cls)->size);
  if (obj == NULL)
  {
    return NULL;
  }

  va_list args;
  va_start(args, cls);
  obj->length = va_arg(args, const size_t);
  obj->isView = va_arg(args, const int);
  va_end(args);

  if (obj->length == 0)
  {
    obj->buffer = NULL;
  }
  else
  {
    obj->buffer = (uint8_t *)calloc(obj->length, sizeof(uint8_t));
    if (obj->buffer == NULL)
    {
      free(obj);
      return NULL;
    }
  }

  ((CIA_OBJECT *)obj)->free = __CIA_BYTEARRAY_OBJECT__free;
  obj->get_byte = __CIA_BYTEARRAY_OBJECT__get_byte;
  obj->set_byte = __CIA_BYTEARRAY_OBJECT__set_byte;
  obj->get_range = __CIA_BYTEARRAY_OBJECT__get_range;
  obj->set_range = __CIA_BYTEARRAY_OBJECT__set_range;
  return obj;
}

const __CIA_BYTEARRAY_CLASS const CIA_BYTEARRAY_CLASS = {
    .size = sizeof(CIA_BYTEARRAY),
    .new = __CIA_BYTEARRAY_CLASS__new,
};
