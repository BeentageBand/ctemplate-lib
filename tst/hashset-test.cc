#include "gtest/gtest.h"
#include "gtest-template.h"
 
#include <unordered_set>

#define Num_Elems(arr) (sizeof(arr)/sizeof(*arr))
 
#define LIST(XL) \
XL(0) \
XL(1) \
XL(2) \
XL(3) \
XL(4) \
XL(5) \
XL(6) \
XL(7) \

#define XL(a) {a, #a},

class Test_CHashSetC : public ::testing::TestWithParam<Tuple_T>
{};
 

static Tuple_T Set_Data[] =
{
	LIST(XL)
};


static int cset_tuple_cmp(Tuple_Ptr_T * const a, Tuple_Ptr_T * const b);

static std::unordered_set<int> SetCpp;
static union CHashSet_int CHashSetC = {NULL};
static struct Bucket_int Buckets[20] = {0};
static std::unordered_set<Tuple_Ptr_T> SetTupleCpp;
//static union CHashSet_Tuple_Ptr CHashSet_Tuple = {NULL};

int cset_tuple_cmp(Tuple_Ptr_T * const a, Tuple_Ptr_T * const b)
{
	if((*a)->id < (*b)->id) return -1;
	if((*a)->id == (*b)->id) return 0;
	if((*a)->id > (*b)->id) return 1;
}

TEST(HashSet,functionalities)
{
	CHashSet_int_populate(&CHashSetC, NULL, NULL);
  //CHashSet_Tuple_Ptr_populate(&CHashSet_Tuple, NULL, 0, (Comparator_Tuple_Ptr)cset_tuple_cmp);
}

TEST_P(Test_CHashSetC, insert_n_find)
{
	EXPECT_EQ(SetCpp.size(), CHashSet_int_size(&CHashSetC));

  std::cout << "Inserting " << GetParam().id << std::endl;
	SetCpp.insert(GetParam().id);
	CHashSet_int_insert(&CHashSetC, GetParam().id);

  std::cout << "Finding " << GetParam().id << std::endl;
  int * found = CHashSet_int_find(&CHashSetC, GetParam().id);
  ASSERT_FALSE(NULL == found);
	EXPECT_EQ(*SetCpp.find(GetParam().id), *found);

	SetTupleCpp.insert(Set_Data + GetParam().id);
//	CHashSet_Tuple_Ptr_insert(&CHashSet_Tuple, (Tuple_Ptr_T) Set_Data + GetParam().id);
//	EXPECT_EQ(*SetTupleCpp.find((Tuple_Ptr_T) Set_Data + GetParam().id), *CHashSet_Tuple_Ptr_find(&CHashSet_Tuple, (Tuple_Ptr_T)Set_Data + GetParam().id));
}

TEST_P(Test_CHashSetC, destroy)
{
	SetCpp.erase(SetCpp.begin(), SetCpp.end());

  std::cout << "erasing " << GetParam().id << std::endl;
  int * found = CHashSet_int_find(&CHashSetC, GetParam().id);
  EXPECT_TRUE(NULL != found);

	CHashSet_int_erase(&CHashSetC, GetParam().id); 

  std::cout << "finding erased " << GetParam().id << std::endl;
  found = CHashSet_int_find(&CHashSetC, GetParam().id);
  EXPECT_TRUE(NULL == found);

//	SetTupleCpp.erase(SetTupleCpp.begin(), SetTupleCpp.end());
//		CHashSet_Tuple_Ptr_erase(&CHashSet_Tuple, (Tuple_Ptr_T)Set_Data + GetParam().id);

	if(0 == CHashSet_int_size(&CHashSetC))
	{
    std::cout << "Delete" << std::endl;
		_delete(&CHashSetC);
	}
/*
	if(0 == CHashSet_Tuple_Ptr_size(&CHashSet_Tuple))
	{
		_delete(&CHashSet_Tuple);
	}
*/
}

INSTANTIATE_TEST_CASE_P(Data, Test_CHashSetC, ::testing::ValuesIn(Set_Data));
