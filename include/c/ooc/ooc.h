/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Object Oriented Programming in C Programming Language.
 */

#ifndef CIA_OOC_H
#define CIA_OOC_H

#include <stdlib.h>
#include <stdint.h>

enum CIA_STATUS
{
  CIA_SUCCESS = EXIT_SUCCESS,
  CIA_FAILURE = EXIT_FAILURE,
};

typedef struct __CIA_OOC_CLASS__ CIA_CLASS;
typedef struct __CIA_OOC_CLASS__
{
  size_t size;
  void *(*new)(const void *const cls, ...);
} CIA_CLASS;

typedef struct __CIA_OOC_OBJECT__ CIA_OBJECT;
typedef struct __CIA_OOC_OBJECT__
{
  enum CIA_STATUS (*free)(void *const self);
} CIA_OBJECT;

extern void *__CIA_OOC_CLASS__new(const void *const cls, ...);
extern enum CIA_STATUS __CIA_OOC_OBJECT__free(void *const self);

#endif // CIA_OOC_H
