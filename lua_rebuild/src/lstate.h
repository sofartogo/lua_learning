/*
 * =============================================================================
 *
 *       Filename:  lstate.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月26日 16时50分43秒
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */


struct lua_State {
	CommonHeader;
	lu_byte status;
	StkId top; /* first free slot in the stack */
	global_State *l_G;
	CallInfo *ci; /* call info for current function */
	const Instruction *oldpc; /* last pc traced */
	StkId stack_last; /* last free slot in the stack */
	StkId stack; /* stack base */
	int stacksize;
	unsigned short nny; /* number of non-yieldable calls in stack */
	unsigned short nCcalls; /* number of nested C calls */
	lu_byte hookmask;
	lu_byte allowhook;
	int basehookcount;
	int hookcount;
	lua_Hook hook;
	GCObject *openupval; /* list of open upvalues in this stack */
	GCObject *gclist;
	struct lua_longjmp *errorJmp; /* current error recover point */
	ptrdiff errfunc; /* current error handling function (stack index) */
	CallInfo base_ci; /* CallInfo for first level (C calling Lua) */
};


union GCObject {
	GCheader gch; /* common header */
	union TString ts;
	union Udata u;
	union Closure cl;
	struct Table h;
	struct Proto p;
	struct Upval uv;
	struct lua_State th;    /* thread */
};


/*
** `global state', shared by all threads of this state
*/

stop here
