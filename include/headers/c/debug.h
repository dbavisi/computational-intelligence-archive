/**
 * Computational Intelligence Archive
 * @author Dwij Bavisi <dwij@dbavisi.net>
 * Website: https://cia.dbavisi.net
 *
 * Header file for debugging in C Programming Language.
 */

#ifndef CIA_INCLUDE_DEBUG_H
#define CIA_INCLUDE_DEBUG_H

#include <stdint.h>

extern uint8_t CIA_DEBUG_INDENT;

#define CIA_DEBUG_STATS __func__, __LINE__

#define CIA_DEBUG(fmt, ...)                 \
  do                                        \
  {                                         \
    printf("[ ]%*s", CIA_DEBUG_INDENT, ""); \
    printf(" %s:%d : ", CIA_DEBUG_STATS);   \
    printf(fmt, ##__VA_ARGS__);             \
    printf("\n");                           \
  } while (0);

#define CIA_DEBUG_ENTER(fmt, ...)  \
  do                               \
  {                                \
    CIA_DEBUG_INDENT += 2;         \
    CIA_DEBUG(fmt, ##__VA_ARGS__); \
  } while (0);

#define CIA_DEBUG_EXIT(fmt, ...)   \
  do                               \
  {                                \
    CIA_DEBUG(fmt, ##__VA_ARGS__); \
    CIA_DEBUG_INDENT -= 2;         \
  } while (0);

#define CIA_ERROR(fmt, ...)                 \
  do                                        \
  {                                         \
    printf("[*]%*s", CIA_DEBUG_INDENT, ""); \
    printf(" %s:%d : ", CIA_DEBUG_STATS);   \
    printf(fmt, ##__VA_ARGS__);             \
    printf("\n");                           \
  } while (0);

#endif // CIA_INCLUDE_DEBUG_H
