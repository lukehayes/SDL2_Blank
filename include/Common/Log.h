#ifndef LOG_H
#define LOG_H

#include "Common/Types.h"

/**
 * Printf wrappers for simpler logging.
 */

/**
 * Log a string to the command line.
 *
 * @param char* message
 *
 * @return void
 */
void L(str message)
{
    printf("Log: %s \n", message);
}

/**
 * Log two strings to the command line.
 *
 * @param char* a
 *
 * @param char* b
 *
 * @return void
 */
void LSS(str a, str b)
{
    printf("Log: %s | %s \n", a,b);
}

/**
 * Log a string and a float to the command line.
 *
 * @param char* s
 *
 * @param float f
 *
 * @return void
 */
void LSF(str s, f32 f)
{
    printf("Log: %s | %f \n", s,f);
}

/**
 * Log a string and an integer to the command line.
 *
 * @param char* s
 *
 * @param int i
 *
 * @return void
 */
void LSI(str s, s32 i)
{
    printf("Log: %s -> %i \n", s,i);
}

#endif
