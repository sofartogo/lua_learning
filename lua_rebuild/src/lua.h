/*
 * =============================================================================
 *
 *       Filename:  lua.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月26日 16时49分02秒
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef lua_h
#define lua_h

#include <stdarg.h>
#include <stddef.h>

#include "luaconf.h"





typedef struct lua_State lua_State;

typedef int (*CFunction) (lua_State *L);


#define LUA_TNIL            0
