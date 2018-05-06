#ifndef CHASH_SET_H
#define CHASH_SET_H

#include "cobject.h"

#ifndef CHash_Set_Params
#error "CHash_Set_Params not set"
#endif

#define CHash_Set_Method(method) TEMPLATE(CHash_Set, CHash_Set_Params, method)
#define CHash_Set_Member(member) TEMPLATE(CHash_Set, CHash_Set_Params, member)
#define CHash_Set_T TEMPLATE(CHash_Set, CHash_Set_Params, T)
#define CHash_Set_Class_T TEMPLATE(CHash_Set, CHash_Set_Params, Class_T)
#define CHash_Set_Item_T CAT(T_Param(CHash_Set_Params, 1), _T)
#define CHash_Set_Rehash_T TEMPLATE(CHash_Set, CHash_Set_Params, Rehash_T)
#define CHash_Set_Bucket_T TEMPLATE(CHash_Set, CHash_Set_Params, Bucket_T)
#define CHash_Set_Cmp_T TEMPLATE(CHash_Set, CHash_Set_Params, Cmp_T)

typedef uint32_t (* CHash_Set_Rehash_T)(CHash_Set_Item_T const item);
typedef int (* CHash_Set_Cmp_T)(CHash_Set_Item_T *, CHash_Set_Item_T *);

struct CHash_Set_Member(Bucket)
{
	bool collisions;
	CHash_Set_Item_T item;
}CHash_Set_Bucket_T;

union TEMPLATE(CHash_Set, CHash_Set_Params)
{
	struct TEMPLATE(CHash_Set, CHash_Set_Params, Class) _private * _private vtbl;
	struct
	{
		struct Object Object;
		CHash_Set_Item_T _private * _private buff;
		size_t _private size;
		CHash_Set_Rehash_T _private rehash;
		CHash_Set_Cmp_T _private compare;
	};
}CHash_Set_T;

struct CHash_Set_Member(Class)
{
	struct Class Class;
	size_t (* _private count)(CHash_Set_T * const);
	CHash_Set_Item_T * (* _private begin)(CHash_Set_T * const);
	CHash_Set_Item_T * (* _private end)(CHash_Set_T * const);
	CHash_Set_Item_T * (* _private find)(CHash_Set_T * const, CHash_Set_Item_T const);
	void (*_private insert)(CHash_Set_T * const, CHash_Set_Item_T const);
	void (*_private erase)(CHash_Set_T * const, CHash_Set_Item_T const);
	void (*_private clear)(CHash_Set_T * const);
}CHash_Set_Class_T;

extern CHash_Set_Class_T _private TEMPLATE(CHash_Set, CHash_Set_Params, Class);

extern void TEMPLATE(Populate, CHash_Set, CHash_Set_Params)(CHash_Set_T * const this,
		CHash_Set_Bucket_T * const hash_buff,
		size_t hash_buff_size,
		CHash_Set_Rehash_T const rehash,
		CHash_Set_Cmp_T const compare);
#endif /*CHASH_SET_H*/
