/*
 * =============================================================================
 *
 *       Filename:  lobject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月26日 16时59分17秒
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#define tag2tt(t)  (NNMARK | (t))

typedef struct lua_TValue TValue;

#if !define(NNMARK)   /* {  */

#if !define(LUA_IEEEENDIAN)
#error option 'LUA_NANTRICK' needs 'LUA_IEEEENDIAN'
#endif


#define NNMARK  0x7FF7A500
#define NNMASK  0x7FFFFF00

#undef TValuefields
#undef NILCONSTANT

#if (LUA_IEEEENDIAN == 0)  /* {  */

/* little endian */
#define TValuefields \
	union { struct {Value v__; int tt__;} i; double d__; } u
#define NILCONSTANT {{{NULL}, tag2tt(LUA_TNIL)}}
/* field-access macros */
#define v_(o)      ((o)->u.i.v__)
#define d_(o)      ((o)->u.d__)
#define tt_(o)     ((o)->u.i.tt__)

#else

/* big endian */
#define TValuefields \
	union {struct {int tt__; Value v__;} i; double d__; } u 
#define NILCONSTANT {{tag2tt(LUA_TNIL), {NULL}}}
/* field-access macros */
#define v_(o)      ((o)->u.i.v__)
#define d_(o)      ((o)->u.d__)
#define tt_(o)     ((o)->u.i.tt__)

#endif                  /* }  */

#endif                  /* }  */  



/*
** Union of all collectable objects
*/
typedef union GCObject GCObject;


/*
** Common Header for all collectable objects (in macro form, to be
** included in other objects)
*/
#define CommonHeader GCObject *next; lu_byte tt; lu_byte marked

/*
** Common header in struct form
*/
typedef struct GCheader {
	CommonHeader;
} GCheader;

union Value {
	GCObject *gc;  /* collectable objects */
	void *p;       /* light userdata */
	int b;         /* booleans */
	lua_CFunction f; /* light C functions */
	numfield;    /* numbers */
};


struct lua_TValue {
	TValuefields;
};


typedef TValue *StkId;  /* index to stack elements */

/*
** Header for string value; string bytes follow the end of this structure
*/
typedef union TString {
	L_Umaxalign dummy; /* ensures maximum alignment for strings */
	struct {
		CommonHeader;
		lu_byte extra; /* reserved words for short strings; "has hash" for longs */
		unsigned int hash;
		size_t len; /* number of characters in string */
	}tsv;
} TString;


/*
** Header for userdata; memory area follows the end of this structure
*/
typedef union Udata {
	L_Umaxalign dummy; /* ensures maximum alignment for 'local' udata */
	struct {
		CommonHeader;
		struct Table *metatable;
		struct Table *env;
		size_t len; /* number of bytes */
	}uv;
}Udata;


typedef struct Upvaldesc {
	TString *name; /* upvalue name (for debug information) */
	lu_byte instack; /* where it is in stack */
	lu_byte idx; /* index of upvalue (in stack or in outer function's list) */
}Upvaldesc

/*
** Description of a local variable for function prototypes
** (used for debug information)
*/
typedef struct LocVar {
	TString *varname;
	int startpc; /* first point where variable is active */
	int endpc; /* first point where variable is dead */
}LocVar;

typedef struct Proto {
	CommonHeader;
	TValue *k; /* constants used by the function */
	Instruction *code;
	struct Proto **p; /* function defined inside the function */
	int *lineinfo; /* map from opcodes to source lines (debug information) */
	LocVar *locvars; /* information about local variable (debug information) */
	Upvaldesc *upvalues; /* upvalue information */
	union Closure *cache; /* last created closure with this prototype */
	TString *source; /* used for debug information */
	int sizeupvalues; /* size of 'upvalues' */
	int sizek; /* size of 'k' */
	int sizecode;
	int sizelineinfo;
	int sizep; /* size of 'p' */
	int sizelocvars;
	int linedefined;
	int lastlinedefined;
	GCObject *gclist;
	lu_byte numparams; /* number of fixed parameters */
	lu_byte is_vararg;
	lu_byte maxstacksize; /* maximum stack used by this function */
} Proto;


typedef struct UpVal {
	CommonHeader;
	TValue *v; /* points to stack or to its own value */
	union {
		TValue value; /* the value (when closed) */
		struct {
			struct UpVal * prev;
			struct UpVal * next;
		} l;
	} u;
} UpVal;

#define ClosureHeader \
	CommonHeader; lu_byte nupvalues; GCObject *gclist

typedef struct CClosure {
	ClosureHeader;
	lua_CFunction f;
	TValue upvalue[1]; /* list of upvalues */
}CClosure;

typedef struct LClosure {
	ClosureHeader;
	struct Proto *p;
	UpVal *upvals[1]; /* list of upvalues */
}LClosure;

typedef union Closure {
	CClosure c;
	LClosure l;
} Closure;

typedef union Tkey {
	struct {
		TValuefields;
		struct Node *next; /* for chaining */
	}nk;
	TValue tvk;
}Tkey;

typedef struct Node {
	TValue i_val;
	TKey i_key;
} Node;

typedef struct Table {
	CommonHeader;
	lu_byte flags; /* 1<<p means tagmethod(p) is notpresent */
	lu_byte lsizenode; /* log2 of size of 'node' array */
	struct Table *metatable;
	TValue *array; /* array part  */
	Node *node;
	Node *lastfree; /* any free position is before this position */
	GCObject * gclist;
	int sizearray;
}Table;
