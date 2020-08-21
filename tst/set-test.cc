#include "gtest/gtest.h"
#include "gtest-template.h"
 
#include <set>
 
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

class Test_CSetC : public ::testing::TestWithParam<Tuple_T>
{};
 

static Tuple_T Set_Data[] =
{
	LIST(XL)
};


static int cset_tuple_cmp(Tuple_Ptr_T * const a, Tuple_Ptr_T * const b);

static std::set<Uint8_T> SetCpp;
static union CSet_Uint8 CSetC = {NULL};
static std::set<Tuple_Ptr_T> SetTupleCpp;
//static union CSet_Tuple_Ptr CSet_Tuple = {NULL};

int cset_tuple_cmp(Tuple_Ptr_T * const a, Tuple_Ptr_T * const b)
{
	if((*a)->id < (*b)->id) return -1;
	if((*a)->id == (*b)->id) return 0;
	if((*a)->id > (*b)->id) return 1;
}

TEST(Set,functionalities)
{
	CSet_Uint8_populate(&CSetC, NULL, 0, NULL);
  //CSet_Tuple_Ptr_populate(&CSet_Tuple, NULL, 0, (Comparator_Tuple_Ptr)cset_tuple_cmp);
}

TEST_P(Test_CSetC, insert_n_find)
{
	EXPECT_EQ(SetCpp.size(), CSet_Uint8_size(&CSetC));

  std::cout << "Inserting " << GetParam().id << std::endl;
	SetCpp.insert(GetParam().id);
	CSet_Uint8_insert(&CSetC, GetParam().id);

  EXPECT_FALSE(NULL == CSetC.head);

  std::cout << "Finding " << GetParam().id << std::endl;
  Uint8_T * found = CSet_Uint8_find(&CSetC, GetParam().id);
  ASSERT_FALSE(NULL == found);
	EXPECT_EQ(*SetCpp.find(GetParam().id), *found);

	SetTupleCpp.insert(Set_Data + GetParam().id);
//	CSet_Tuple_Ptr_insert(&CSet_Tuple, (Tuple_Ptr_T) Set_Data + GetParam().id);
//	EXPECT_EQ(*SetTupleCpp.find((Tuple_Ptr_T) Set_Data + GetParam().id), *CSet_Tuple_Ptr_find(&CSet_Tuple, (Tuple_Ptr_T)Set_Data + GetParam().id));
}

TEST_P(Test_CSetC, destroy)
{
	SetCpp.erase(SetCpp.begin(), SetCpp.end());

  Uint8_T * found = CSet_Uint8_find(&CSetC, GetParam().id);
  EXPECT_TRUE(NULL != found);

	CSet_Uint8_erase(&CSetC, GetParam().id); 
  found = CSet_Uint8_find(&CSetC, GetParam().id);
  EXPECT_TRUE(NULL == found);

	SetTupleCpp.erase(SetTupleCpp.begin(), SetTupleCpp.end());
//		CSet_Tuple_Ptr_erase(&CSet_Tuple, (Tuple_Ptr_T)Set_Data + GetParam().id);

	if(0 == CSet_Uint8_size(&CSetC))
	{
		_delete(&CSetC);
	}
/*
	if(0 == CSet_Tuple_Ptr_size(&CSet_Tuple))
	{
		_delete(&CSet_Tuple);
	}
*/
}

INSTANTIATE_TEST_CASE_P(Data, Test_CSetC, ::testing::ValuesIn(Set_Data));
