/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * @header Library for STANDARD implementation of CIA_BYTE.
 */

#include "header.h"

/**
 * Retrive the data stored in the CIA_BYTE object.
 * @param obj The CIA_BYTE object.
 * @return The data stored in the object.
 */
uint8_t __CIA_BYTE__get(const CIA_BYTE *obj)
{
  if (obj == NULL)
  {
    return 0;
  }
  return obj->data;
}

/**
 * Update the data stored in the CIA_BYTE object.
 * @param obj The CIA_BYTE object.
 * @param data The new data to be stored in the object.
 * @return The status of the operation.
 */
enum CIA_STATUS __CIA_BYTE__set(CIA_BYTE *obj, const uint8_t data)
{
  if (obj == NULL)
  {
    return CIA_FAILURE;
  }
  obj->data = data;
  return CIA_SUCCESS;
}

/**
 * Free the memory allocated to the CIA_BYTE object.
 * @param obj The CIA_BYTE object.
 * @return The status of the operation.
 */
enum CIA_STATUS __CIA_BYTE__free(CIA_BYTE *obj)
{
  if (obj == NULL)
  {
    return CIA_FAILURE;
  }
  free(obj);
  return CIA_SUCCESS;
}

/**
 * Create a new instance of CIA_BYTE object with the given data
 * @param cls The class definition.
 * @param data The data to be stored in the object.
 * @return The newly created CIA_BYTE object.
 */
CIA_BYTE *__CIA_BYTE_CLASS__new(const __CIA_BYTE_CLASS *cls, const uint8_t data)
{
  CIA_BYTE *obj = (CIA_BYTE *)malloc(sizeof(CIA_BYTE));
  if (obj == NULL)
  {
    return NULL;
  }

  obj->data = data;
  obj->get = __CIA_BYTE__get;
  obj->set = __CIA_BYTE__set;
  obj->free = __CIA_BYTE__free;

  return obj;
}

// Class instance for CIA_BYTE.
const __CIA_BYTE_CLASS CIA_BYTE_CLASS = {
    .new = __CIA_BYTE_CLASS__new,
};
