/*
 * =============================================================================
 *
 *       Filename:  lauxlib.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月26日 16时07分45秒
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef lauxlib_h
#define lauxlib_h


#include <stddef.h>
#include <stdio.h>

#include "lua.h"

LUALIB_API lua_State *(luaL_newstate) (void);
