/*
 * =============================================================================
 *
 *       Filename:  capi_firstdemo.c
 *
 *    Description:  
 *
 *        Version:  0.0.1
 *        Created:  2012年07月26日 10时54分06秒
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"


int main()
{
	char buf[256];
	int error;
	
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	while(fgets(buf, sizeof(buf), stdin) != NULL) {
		error = luaL_loadbuffer(L, buf, strlen(buf), "line") || lua_pcall(L, 0, 0, 0);
			if(error) {
				fprintf(stderr, "%s", lua_tostring(L, -1));
				lua_pop(L, 1);
			}
	}
	lua_close(L);
	return 0;
}
