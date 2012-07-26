/*
 * =============================================================================
 *
 *       Filename:  luaconf.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月26日 16时20分19秒
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */



/*
@@ LUA_INT32 is an signed integer with exactly 32 bits.
@@ LUAI_UMEM is an unsigned integer big enough to count the total
@* memory used by Lua.
@@ LUAI_MEM is a signed integer big enough to count the total memory
@* used by Lua.
** CHANGE here if for some weird reason the default definitions are not
** good enough for your machine. Probably you do not need to change
** this.
*/
#if LUAI_BITSINT >= 32    /* {  */
#define LUA_INT32 int 
#define LUAI_UMEM  size_t
#define LUAI_MEM   ptrdiff_t
#else 
/* 16-bit ints */
#define LUA_INT32 long 
#define LUAI_UMEM unsigned long 
#define LUAI_MEM long
#endif           /* } */


/*
@@ LUA_API is a mark for all core API functions.
@@ LUALIB_API is a mark for all auxiliary library functions.
@@ LUAMOD_API is a mark for all standard library opening functions.
** CHANGE them if you need to define those functions in some special way.
** For instance, if you want to create one Windows DLL with the core and
** the libraries, you may want to use the following definition (define
** LUA_BUILD_AS_DLL to get it).
*/
#if define(LUA_BUILD_AS_DLL)  /* { */

#if define(LUA_CORE) || define(LUA_LIB) /* { */
#define LUA_API __declspec(dllexport)
#else                         /* }{ */
#define LUA_API __declspec(dllimport)
#endif                     /* }*/

#else                      /* }{ */

#define LUA_API extern

#endif                     /* }*/


/* more often than not the libs go together with the core */
#define LUALIB_API LUA_API
#define LUAMOD_API LUALIB_API
