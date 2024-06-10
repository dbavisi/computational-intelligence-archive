/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Header file for all C Programming Language implementations.
 */

#ifndef CIA_INCLUDE_COMMON_H
#define CIA_INCLUDE_COMMON_H

#include <stdlib.h>
#include <stdint.h>

// Status codes for the CIA library.
enum CIA_STATUS
{
  // Success status code.
  CIA_SUCCESS = EXIT_SUCCESS,

  // Failure status code.
  CIA_FAILURE = EXIT_FAILURE,
};

#endif // CIA_INCLUDE_COMMON_H
