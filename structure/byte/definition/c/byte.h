/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Byte data structure definition in C Programming Language.
 */

#ifndef CIA_BYTE_H
#define CIA_BYTE_H

#include <stdint.h>
#include "include/c/ooc/ooc.h"

typedef struct __CIA_BYTE_OBJECT__ CIA_BYTE;
typedef struct __CIA_BYTE_OBJECT__
{
  CIA_OBJECT;

  uint8_t data;
  uint8_t (*get)(const CIA_BYTE *const self);
  enum CIA_STATUS (*set)(CIA_BYTE *const self, const uint8_t data);
} CIA_BYTE;

typedef struct __CIA_BYTE_CLASS__ __CIA_BYTE_CLASS;
typedef struct __CIA_BYTE_CLASS__
{
  CIA_CLASS;
} __CIA_BYTE_CLASS;

extern const __CIA_BYTE_CLASS const CIA_BYTE_CLASS;

#endif // CIA_BYTE_H
