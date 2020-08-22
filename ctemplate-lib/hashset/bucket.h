#include <stdbool.h>

#ifndef Bucket_Params 
# error "Bucket_Params should be defined"
#endif // !Bucket_Params
#define Bucket_T TEMPLATE(Bucket, Bucket_Params)
#define Hash_T TEMPLATE(Hash, Bucket_Params)
#define HashComparator_T TEMPLATE(HashComparator, Bucket_Params)
#define Bucket_T_access TEMPLATE(Bucket, Bucket_Params, access)
#define Bucket_T_available TEMPLATE(Bucket, Bucket_Params, available)
#define Bucket_T_is_empty TEMPLATE(Bucket, Bucket_Params, is_empty)
#define Bucket_T_hash TEMPLATE(Bucket, Bucket_Params, hash)

typedef size_t (*Hash_T) (T * const t, size_t const, size_t const);
typedef int (*HashComparator_T) (T * const a, T * const b, size_t const);

struct Bucket_T
{
  T value;
  bool collision;
};

extern size_t Bucket_T_access(struct Bucket_T * buckets, size_t const size, Hash_T const hash, 
    HashComparator_T const cmp, T value);

extern size_t Bucket_T_available(struct Bucket_T * buckets, size_t const size, Hash_T const hash, 
    HashComparator_T const cmp, T value);

extern bool Bucket_T_is_empty(struct Bucket_T * bucket_t);

extern size_t Bucket_T_hash(T * const value, size_t const capacity, size_t const seed);

#undef Bucket_T
#undef Hash_T
#undef HashComparator_T
#undef Bucket_T_access
#undef Bucket_T_available
#undef Bucket_T_is_empty
#undef Bucket_T_hash 
