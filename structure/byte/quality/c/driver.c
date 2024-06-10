/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Test suite for CIA_BYTE data structure in C Programming Language.
 */

#include <stdio.h>
#include "include/headers/c/debug.h"
#include "structure/byte/definition/c/header.h"

uint8_t CIA_DEBUG_INDENT = 0;
extern enum CIA_STATUS acceptence_test(void);

int main(int argc, char **argv)
{
  enum CIA_STATUS test_status;
  int suite_status = EXIT_SUCCESS;

  CIA_DEBUG_ENTER("Running test suite for CIA_BYTE data structure")

  test_status = acceptence_test();
  if (test_status != CIA_SUCCESS)
  {
    CIA_ERROR("Failed acceptence test for CIA_BYTE data structure")
    suite_status = EXIT_FAILURE;
  }

  CIA_DEBUG_EXIT("Finished test suite for CIA_BYTE data structure")

  return suite_status;
}
