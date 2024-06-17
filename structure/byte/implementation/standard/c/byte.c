/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Standard implementation of Byte data structure in C Programming Language.
 */

#include <stdint.h>
#include <stdarg.h>
#include "include/c/ooc/ooc.h"
#include "structure/byte/definition/c/byte.h"

uint8_t __CIA_BYTE_OBJECT__get(const CIA_BYTE *const self)
{
  return self->data;
}

enum CIA_STATUS __CIA_BYTE_OBJECT__set(CIA_BYTE *const self, const uint8_t data)
{
  self->data = data;
  return CIA_SUCCESS;
}

void *__CIA_BYTE_CLASS__new(const void *const cls, ...)
{
  CIA_BYTE *const obj = (CIA_BYTE *)__CIA_OOC_CLASS__new((CIA_CLASS *)cls);
  if (obj == NULL)
  {
    return NULL;
  }

  va_list args;
  va_start(args, cls);
  obj->data = (uint8_t)va_arg(args, int);
  va_end(args);

  obj->get = __CIA_BYTE_OBJECT__get;
  obj->set = __CIA_BYTE_OBJECT__set;
  return (void *)obj;
}

const __CIA_BYTE_CLASS const CIA_BYTE_CLASS = {
    .size = sizeof(CIA_BYTE),
    .new = __CIA_BYTE_CLASS__new,
};
