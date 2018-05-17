#define COBJECT_IMPLEMENTATION
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

static size_t CHash_Set_Method(count)(CHash_Set_T * const);
static CHash_Set_Item_T * CHash_Set_Method(begin)(CHash_Set_T * const);
static CHash_Set_Item_T * CHash_Set_Method(end)(CHash_Set_T * const);
static CHash_Set_Item_T * CHash_Set_Method(find)(CHash_Set_T * const, CHash_Set_Item_T const);
static void CHash_Set_Method(insert)(CHash_Set_T * const, CHash_Set_Item_T const);
static void CHash_Set_Method(erase)(CHash_Set_T * const, CHash_Set_Item_T const);
static void CHash_Set_Method(clear)(CHash_Set_T * const);
static bool CHash_Set_Method(is_empty)(CHash_Set_Item_T * const item);
static int CHash_Set_Method(compare)(CHash_Set_Item_T * a, CHash_Set_Item_T * b);
static CHash_Set_HID_T CHash_Set_Method(rehash)(CHash_Set_HID_T const hid);

size_t CHash_Set_Method(count)(CHash_Set_T * const this)
{
   CHash_Set_Bucket_T * it;
   size_t count = 0;

   for(it = this->buff; it < (this->buff + this->size); ++it)
   {
      if(!CHash_Set_Method(is_empty)(it))
      {
         ++count;
      }
   }
   return count;
}

CHash_Set_Item_T * CHash_Set_Method(begin)(CHash_Set_T * const this)
{
   for(it = this->buff; it < (this->buff + this->size); ++it)
   {
      if(CHash_Set_Method(is_empty)(&it->item))
      {
         break;
      }
   }
   return (CHash_Set_Item_T *)((bool* )it) + 1;
}

CHash_Set_Item_T * CHash_Set_Method(end)(CHash_Set_T * const)
{
   return  (CHash_Set_Item_T *)((bool *)(this->buff + this->size)) + 1;
}

CHash_Set_Item_T * CHash_Set_Method(find)(CHash_Set_T * const this, CHash_Set_Item_T const item)
{
   CHash_Set_HID_T hid = (CHash_Set_HID_T) item;
   size_t retries = 0;
   do
   {
      hid = this->rehash(hid + retries);
      is_found  = !(this->buff[hid].collision) &&
         0 == CHash_Set_Method(compare)(&item, &this->buff[hid].item);
      ++retries;
   }while(!is_found && retries < this->size);
   return &this->buff[hid].item;
}

void CHash_Set_Method(insert)(CHash_Set_T * const this, CHash_Set_Item_T const item)
{
   CHash_Set_HID_T hid = (CHash_Set_HID_T) item;
   size_t retries = 0;
   do
   {
      hid = this->rehash(hid + retries);
      is_empty = CHash_Set_Method(is_empty)(&this->buff[hid].item);
      if(!is_empty)
      {
         this->buff[hid].collision = true;
      }
      else
      {
         memcpy(&this->buff[hid].item, &item, sizeof(item));
      }
      ++retries;
   }while(!is_empty && retries < this->size);

}
void CHash_Set_Method(erase)(CHash_Set_T * const this, CHash_Set_Item_T const item)
{
   CHash_Set_Item_T * found = this->vtbl->find(this, item);
   if(found != this->vtbl->end(this))
   {
      memset(found, 0, sizeof(item));
      CHash_Set_HID_T hid = this->rehash((CHash_Set_HID_T)item);// check if next item is down;

      if(CHash_Set_Method(is_empty)(&this->buff[hid].item))
      {
         *((bool *)(found) - 1) = false;
      }
   }
}
void CHash_Set_Method(clear)(CHash_Set_T * const)
{
   for(it = this->buff; it <  this->buff + this->size; ++it)
   {
      if(CHash_Set_Method(is_empty(&this->buff[hid].
   }
}

bool CHash_Set_Method(is_empty)(CHash_Set_Item_T * const item)
{
   CHash_Set_Item_T empty_it;
   memset(&empty_it, 0, sizeof(empty_it));
   return 0 == memcmp(item, &empty_it, sizeof(empty_it));
}

CHash_Set_HID_T CHash_Set_Method(rehash)(CHash_Set_T * const this, CHash_Set_HID_T const hid)
{
   return hid % this->size;
}

void TEMPLATE(Populate, CHash_Set, CHash_Set_Params)(CHash_Set_T * const this,
      CHash_Set_Bucket_T * const hash_buff,
      size_t hash_buff_size,
      CHash_Set_Rehash_T const rehash,
      CHash_Set_Cmp_T const compare)
{
   if(NULL == TEMPLATE(CHash_Set, CHash_Set_Params).vtbl)
   {
      TEMPLATE(CHash_Set, CHash_Set_Params).vtbl = &CHash_Set_Member(Class);
      TEMPLATE(CHash_Set, CHash_Set_Params).buff = NULL;
      TEMPLATE(CHash_Set, CHash_Set_Params).size = 0;
      TEMPLATE(CHash_Set, CHash_Set_Params).rehash = CHash_Set_Method(rehash);
      TEMPLATE(CHash_Set, CHash_Set_Params).compare = CHash_Set_Method(compare);
   }
   memcpy(this, &TEMPLATE(CHash_Set, CHash_Set_Params), sizeof(TEMPLATE(CHash_Set, CHash_Set_Params)));
   this->buff = hash_buff;
   this->size = hash_buff_size;
   memset(hash_buff, 0, hash_buff_size * sizeof(CHash_Set_Bucket_T));

   if(NULL != rehash)
      this->rehash = rehash;
   if(NULL != compare)
      this->compare = compare;
}
