/*
 * =============================================================================
 *
 *       Filename:  lua.c
 *
 *    Description:  
 *
 *        Version:  0.0.1
 *        Created:  2012年07月26日 15时48分29秒
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lua_c

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"




int main(int argc, char **argv) {
	int status, result;
	lua_State *L = luaL_newstate();
	if(L == NULL) {
		l_message(argv[0], "cannot create state: not enough memory");
		return EXIT_FAILURE;
	}
	/* call 'pmain' in protected mode */
	lua_pushcfunction(L, &pmain);
	lua_pushinteger(L, argc);
	lua_pushlightuserdate(L, argv);
	status = lua_pcall(L, 2, 1, 0);
	result = lua_toboolean(L, -1);
	finalreport(L, status);
	lua_close(L);
	return (result && status == LUA_OK) ? EXIT_SUCCESS : EXIT_FAILURE;
}
