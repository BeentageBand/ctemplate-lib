#define COBJECT_IMPLEMENTATION
#ifndef CHash_Set_Params
#error "CHash_Set_Params not set"
#endif

#define CHash_Set_Method(method) TEMPLATE(CHash_Set, CHash_Set_Params, method)
#define CHash_Set_Member(member) TEMPLATE(CHash_Set, CHash_Set_Params, member)
#define CHash_Set_T TEMPLATE(CHash_Set, CHash_Set_Params, T)
#define CHash_Set_Class_T TEMPLATE(CHash_Set, CHash_Set_Params, Class_T)
#define CHash_Set_Item_T T_Param(1, CHash_Set_Params)
#define CHash_Set_Rehash_T TEMPLATE(CHash_Set, CHash_Set_Params, Rehash_T)
#define CHash_Set_Bucket_T TEMPLATE(CHash_Set, CHash_Set_Params, Bucket_T)
#define CHash_Set_Cmp_T TEMPLATE(CHash_Set, CHash_Set_Params, Cmp_T)

static void CHash_Set_Method(delete)(struct Object * const obj);
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

static CHash_Set_T TEMPLATE(CHash_Set, CHash_Set_Params) = {NULL};
static CHash_Set_Class_T CHash_Set_Member(Class) = 
{
   {CHash_Set_Method(delete), NULL}
};

void CHash_Set_Method(delete)(struct Object * const obj)
{
   CHash_Set_T * const this = (CHash_Set_T *)Object_Cast(&CHash_Set_Member(Class), obj);
   this->vtbl->clear(this);
   this->size = 0UL;
   this->buff = NULL;
}

size_t CHash_Set_Method(count)(CHash_Set_T * const this)
{
   CHash_Set_Item_T * it;
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
   CHash_Set_Item_T * it;
   for(it = this->buff; it < (this->buff + this->size); ++it)
   {
      if(!CHash_Set_Method(is_empty)(it))
      {
         break;
      }
   }
   return it;
}

CHash_Set_Item_T * CHash_Set_Method(end)(CHash_Set_T * const)
{
   CHash_Set_Item_T * it;
   for(it = this->buff + this->size; it != this->buff; --it)
   {
      if(!CHash_Set_Method(is_empty)(it))
      {
        break;
      }
   }
   return end;
}

CHash_Set_Item_T * CHash_Set_Method(find)(CHash_Set_T * const this, CHash_Set_Item_T const item)
{
   CHash_Set_HID_T hid = (CHash_Set_HID_T) item;
   size_t retries = 0;
   bool is_found = false;
   do
   {
      hid = this->rehash(hid + retries);
      CHash_Set_Bucket_T bucket = {0}; 
      bucket.item = this->buff[hid];
      is_found  = !(bucket.collision) &&
         0 == CHash_Set_Method(compare)(&item, &this->buff[hid]);
      ++retries;
   }while(!is_found && retries < this->size);
   return this->buff + hid;
}

void CHash_Set_Method(insert)(CHash_Set_T * const this, CHash_Set_Item_T const item)
{
   CHash_Set_HID_T hid = (CHash_Set_HID_T) item;
   bool is_empty = true;
   size_t retries = 0;
   do
   {
      hid = this->rehash(hid + retries);
      is_empty = CHash_Set_Method(is_empty)(this->buff + hid);
     
      if(!is_empty)
      {
         CHash_Set_Bucket_T * const bucket = this->buff + hid;
         bucket->collision = true;
      }
      else
      {
         memcpy(this->buff + hid, &item, sizeof(item));
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

      if(CHash_Set_Method(is_empty)(&this->buff + hid))
      {
         *((bool *)(found) - 1) = false;
      }
   }
}

void CHash_Set_Method(clear)(CHash_Set_T * const this)
{
   CHash_Set_Item_T * it;
   for(it = this->buff; it <  this->buff + this->size; ++it)
   {
      if(!CHash_Set_Method(is_empty)(it))
      {
        memcpy(it, 0, sizeof(it[0]));
      }
   }
}

bool CHash_Set_Method(is_empty)(CHash_Set_Item_T * const item)
{
   CHash_Set_Item_T empty_it;
   memset(&empty_it, 0, sizeof(empty_it));
   CHash_Set_Bucket_T bucket = { false };
   bucket.item = *item;
   return 0 == memcmp(item, &empty_it, sizeof(empty_it)) || bucket.collision;
}

CHash_Set_HID_T CHash_Set_Method(rehash)(CHash_Set_T * const this, CHash_Set_HID_T const hid)
{
   return hid % this->size;
}

void TEMPLATE(Populate, CHash_Set, CHash_Set_Params)(CHash_Set_T * const this,
      CHash_Set_Item_T * const hash_buff,
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
   memset(hash_buff, 0, hash_buff_size * sizeof(CHash_Set_Item_T));

   if(NULL != rehash)
      this->rehash = rehash;
   if(NULL != compare)
      this->compare = compare;
}

#undef CHash_Set_Method
#undef CHash_Set_Member
#undef CHash_Set_T 
#undef CHash_Set_Class_T 
#undef CHash_Set_Item_T 
#undef CHash_Set_Rehash_T 
#undef CHash_Set_Bucket_T 
#undef CHash_Set_Cmp_T 
