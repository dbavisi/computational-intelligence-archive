/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Definition of Byte data structure in C Programming Language.
 */

#ifndef CIA_BYTE_H
#define CIA_BYTE_H

#include "common.h"

typedef struct __CIA_BYTE__ CIA_BYTE;
typedef struct __CIA_BYTE_CLASS__ __CIA_BYTE_CLASS;

// Definition for instance of CIA_BYTE.
typedef struct __CIA_BYTE__
{
  uint8_t data;

  /**
   * Retrive the data stored in the CIA_BYTE object.
   * @param obj The CIA_BYTE object.
   * @return The data stored in the object.
   */
  uint8_t (*get)(const CIA_BYTE *const obj);

  /**
   * Update the data stored in the CIA_BYTE object.
   * @param obj The CIA_BYTE object.
   * @param data The new data to be stored in the object.
   * @return The status of the operation.
   */
  enum CIA_STATUS (*set)(CIA_BYTE *const obj, const uint8_t const data);

  /**
   * Free the memory allocated to the CIA_BYTE object.
   * @param obj The CIA_BYTE object.
   * @return The status of the operation.
   */
  enum CIA_STATUS (*free)(CIA_BYTE *const obj);
} CIA_BYTE;

// Definition for class of CIA_BYTE.
typedef struct __CIA_BYTE_CLASS__
{
  /**
   * Create a new instance of CIA_BYTE object with the given data
   * @param cls The class definition.
   * @param data The data to be stored in the object.
   * @return The newly created CIA_BYTE object.
   */
  CIA_BYTE *(*new)(const __CIA_BYTE_CLASS *const cls, const uint8_t const data);
} __CIA_BYTE_CLASS;

// Global instance of CIA_BYTE_CLASS.
extern const __CIA_BYTE_CLASS const CIA_BYTE_CLASS;

#endif // CIA_BYTE_H
