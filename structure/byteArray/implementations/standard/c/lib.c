/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Standard implementation of ByteArray data structure in C Programming Language.
 */

#include "structure/byteArray/definition/c/header.h"

/**
 * Retrieve the data stored in the CIA_BYTEARRAY buffer.
 * @param obj The CIA_BYTEARRAY object.
 * @param start The start index of the buffer.
 * @param end The end index of the buffer.
 * @return The data stored in the buffer.
 *
 * @note start and end are inclusive.
 * @note The caller is responsible for freeing the memory allocated to the buffer.
 */
uint8_t *__CIA_BYTEARRAY__get(const CIA_BYTEARRAY *const obj, const size_t const start, const size_t const end)
{
  if (obj == NULL)
  {
    return NULL;
  }
  if (start < 0 || start > end || end >= obj->size)
  {
    return NULL;
  }
  uint8_t *const buffer = (uint8_t *)malloc((end - start + 1) * sizeof(uint8_t));
  if (buffer == NULL)
  {
    return NULL;
  }
  for (size_t i = start; i <= end; i += 1)
  {
    buffer[i - start] = obj->buffer[i];
  }
  return buffer;
}

/**
 * Update the data stored in the CIA_BYTEARRAY buffer.
 * @param obj The CIA_BYTEARRAY object.
 * @param start The start index of the buffer.
 * @param data The data to be stored in the buffer.
 * @param size The size of the buffer.
 * @return The status of the operation.
 */
enum CIA_STATUS __CIA_BYTEARRAY__set(CIA_BYTEARRAY *const obj, const size_t const start, const uint8_t *const data, const size_t size)
{
  if (obj == NULL)
  {
    return CIA_FAILURE;
  }
  if (start < 0 || start + size > obj->size)
  {
    return CIA_FAILURE;
  }
  for (size_t i = start; i < start + size; i += 1)
  {
    obj->buffer[i] = data[i - start];
  }
  return CIA_SUCCESS;
}

/**
 * Free the memory allocated to the CIA_BYTEARRAY object.
 * @param obj The CIA_BYTEARRAY object.
 * @return The status of the operation.
 */
enum CIA_STATUS __CIA_BYTEARRAY__free(CIA_BYTEARRAY *const obj)
{
  if (obj == NULL)
  {
    return CIA_FAILURE;
  }
  free(obj->buffer);
  free(obj);
  return CIA_SUCCESS;
}

/**
 * Create a view from the CIA_BYTEARRAY object.
 * @param obj The CIA_BYTEARRAY object.
 * @param start The start index of the view.
 * @param end The end index of the view.
 * @return The view of the CIA_BYTEARRAY object.
 */
CIA_BYTEARRAY *__CIA_BYTEARRAY__view(const CIA_BYTEARRAY *const obj, const size_t const start, const size_t const end)
{
  if (obj == NULL)
  {
    return NULL;
  }
  if (start < 0 || start > end || end >= obj->size)
  {
    return NULL;
  }

  CIA_BYTEARRAY *const view = CIA_BYTEARRAY_CLASS.new(&CIA_BYTEARRAY_CLASS, 0, NULL);
  if (view == NULL)
  {
    return NULL;
  }

  view->buffer = obj->buffer + start;
  view->size = end - start + 1;

  return view;
}

/**
 * Create a new instance of CIA_BYTEARRAY object with the given data
 * @param cls The class definition.
 * @param size The size of the data.
 * @param [data] The data to be stored in the object.
 * @return The newly created CIA_BYTEARRAY object.
 */
CIA_BYTEARRAY *__CIA_BYTEARRAY_CLASS__new(const __CIA_BYTEARRAY_CLASS *const cls, const size_t size, const uint8_t *const data)
{
  CIA_BYTEARRAY *const obj = (CIA_BYTEARRAY *)malloc(sizeof(CIA_BYTEARRAY));
  if (obj == NULL)
  {
    return NULL;
  }

  if (size > 0)
  {
    if (data == NULL)
    {
      obj->buffer = (uint8_t *)calloc(size, sizeof(uint8_t));
    }
    else
    {
      obj->buffer = (uint8_t *)malloc(size * sizeof(uint8_t));
    }
    if (obj->buffer == NULL)
    {
      free(obj);
      return NULL;
    }

    if (data != NULL)
    {
      for (size_t i = 0; i < size; i += 1)
      {
        obj->buffer[i] = data[i];
      }
    }
  }
  else
  {
    obj->buffer = NULL;
  }

  obj->size = size;
  obj->get = __CIA_BYTEARRAY__get;
  obj->set = __CIA_BYTEARRAY__set;
  obj->free = __CIA_BYTEARRAY__free;
  obj->view = __CIA_BYTEARRAY__view;
  return obj;
}

// Class instance for CIA_BYTEARRAY.
const __CIA_BYTEARRAY_CLASS const CIA_BYTEARRAY_CLASS = {
    .new = __CIA_BYTEARRAY_CLASS__new,
};
