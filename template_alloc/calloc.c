#define COBJECT_IMPLEMENTATION

#ifndef CAlloc_Params
#error "CAlloc_Params not defined"
#endif


static _T1 * Method_Name(CAlloc, CAlloc_Params, begin)(union T_Calloc(Calloc_Params) * const this);
static _T1 * Method_Name(CAlloc, CAlloc_Params, end)(union T_Calloc(Calloc_Params) * const this);
static _T1 * Method_Name(CAlloc, CAlloc_Params, alloc_heap)(union T_Calloc(Calloc_Params) * const this);
static void Method_Name(CAlloc, CAlloc_Params, free_heap)(union T_Calloc(Calloc_Params) * const this, _T1 * const ptr);
static size_t Method_Name(CAlloc, CAlloc_Params, capacity)(union T_Calloc(Calloc_Params) * const this);

static _T1 * Method_Name(CAlloc, CAlloc_Params, alloc_pool)(union T_Calloc(Calloc_Params) * const this);
static void Method_Name(CAlloc, CAlloc_Params, free_pool)(union T_Calloc(Calloc_Params) * const this, _T1 * const ptr);

union T_Calloc(Calloc_Params, Class) T_Calloc(Heap, Calloc_Params, Class) =
{
	{NULL, Method_Name(CAlloc, CAlloc_Params, delete) }
	Method_Name(CAlloc, CAlloc_Params, begin),
	Method_Name(CAlloc, CAlloc_Params, end),
	Method_Name(CAlloc, CAlloc_Params, alloc_heap),
	Method_Name(CAlloc, CAlloc_Params, free_heap),
	Method_Name(CAlloc, CAlloc_Params, capacity),
};

union T_Calloc(Calloc_Params, Class) T_Calloc(Pool, Calloc_Params, Class) = 
{
	{NULL, Method_Name(CAlloc, CAlloc_Params, delete) },
	Method_Name(CAlloc, CAlloc_Params, begin),
	Method_Name(CAlloc, CAlloc_Params, end),
	Method_Name(CAlloc, CAlloc_Params, alloc),
	Method_Name(CAlloc, CAlloc_Params, free),
	Method_Name(CAlloc, CAlloc_Params, capacity),
};

static union T_Calloc(Calloc_Params) T_Calloc(Heap, Calloc_Params) = {NULL};
static union T_Calloc(Calloc_Params) T_Calloc(Pool, Calloc_Params) = {NULL};
_T1 * Method_Name(CAlloc, CAlloc_Params, begin)(union T_Calloc(Calloc_Params) * const this)
{
	return this->buff;
}

_T1 * Method_Name(CAlloc, CAlloc_Params, end)(union T_Calloc(Calloc_Params) * const this)
{
	return this->buff + this->end;
}

_T1 * Method_Name(CAlloc, CAlloc_Params, alloc_heap)(union T_Calloc(Calloc_Params) * const this)
{
	return malloc(sizeof(_T1));
}

void Method_Name(CAlloc, CAlloc_Params, free_heap)(union T_Calloc(Calloc_Params) * const this, _T1 * const ptr)
{
	free(this->buff)
	this->end = 0;
}

size_t Method_Name(CAlloc, CAlloc_Params, capacity)(union T_Calloc(Calloc_Params) * const this)
{
	return this->

static _T1 * Method_Name(CAlloc, CAlloc_Params, alloc_pool)(union T_Calloc(Calloc_Params) * const this);
static void Method_Name(CAlloc, CAlloc_Params, free_pool)(union T_Calloc(Calloc_Params) * const this, _T1 * const ptr);


void Method_Name(Populate, Heap, Calloc, Calloc_Params)(union T_Calloc(Calloc_Params) * const this, size_t const alloc_size)
{
	if(NULL == T_Calloc(Heap, Calloc_Params).vtbl)
	{
		T_Calloc(Heap, Calloc_Params) = &T_Calloc(Heap, Calloc_Params, Class);
		T_Calloc(Heap, Calloc_Params).buff = NULL;
		T_Calloc(Heap, Calloc_Params).end = 0;
	}
	
	memcpy(this, &T_Calloc(Heap, Calloc_Params), sizeof(T_Calloc(Heap, Calloc_Params)));
	this->buff = (_T1 *) malloc(sizeof(_T1 * alloc_size));
	this->end = alloc_size;
}

void Method_Name(Populate, Pool, Calloc, Calloc_Params)(union T_Calloc(Calloc_Params) * const this,
		_T1 * const allocated_buff, size_t const alloc_size)
{
	if(NULL == T_Calloc(Pool, Calloc_Params).vtbl)
	{
		T_Calloc(Pool, Calloc_Params) = &T_Calloc(Pool, Calloc_Params, Class);
		T_Calloc(Pool, Calloc_Params).buff = NULL;
		T_Calloc(Pool, Calloc_Params).end = 0;
	}
	
	memcpy(this, &T_Calloc(Pool, Calloc_Params), sizeof(T_Calloc(Pool, Calloc_Params)));
	this->buff = allocate_buff;
	this->end = alloc_size;
}

