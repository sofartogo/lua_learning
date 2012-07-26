/*
 * =============================================================================
 *
 *       Filename:  llimits.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月26日 17时00分44秒
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
typedef unsigned LUA_INT32 lu_int32;

typedef unsigned char lu_byte;

typedef lu_int32 Instruction;

/* type to ensure maximum alignment */
#if !define(LUAI_USER_ALIGNMENT_T)
#define LUAI_USER_ALIGNMENT_T union{double u; void *s; long l;}
#endif

typedef LUAI_USER_ALIGNMENT_T L_Umaxalign;
