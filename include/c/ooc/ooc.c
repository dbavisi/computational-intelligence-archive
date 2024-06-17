/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Object Oriented Programming in C Programming Language.
 */

#include "ooc.h"

void *__CIA_OOC_CLASS__new(const void *const cls, ...)
{
  CIA_OBJECT *const obj = (CIA_OBJECT *)malloc(((CIA_CLASS *)cls)->size);
  if (obj == NULL)
  {
    return NULL;
  }
  obj->free = __CIA_OOC_OBJECT__free;
  return (void *)obj;
}

enum CIA_STATUS __CIA_OOC_OBJECT__free(void *const self)
{
  free(self);
  return CIA_SUCCESS;
}
