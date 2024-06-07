/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * @header Common header file for C programming language.
 */

#ifndef CIA_INCLUDE_COMMON_H
#define CIA_INCLUDE_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Common status codes for CIA applications.
enum CIA_STATUS
{
  // Success status code.
  CIA_SUCCESS = 0,

  // Failure status code.
  CIA_FAILURE = 1,
};

#endif // CIA_INCLUDE_COMMON_H
