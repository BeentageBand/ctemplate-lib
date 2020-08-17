#define COBJECT_IMPLEMENTATION
#define Dbg_FID DBG_FID_DEF(GTEST_FID, 3)

#include "gtest/gtest.h"
#include "gtest_template.h"
#include "dbg_log.h"
 
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
static CSet_Uint8_T CSetC = {NULL};
static Uint8_T CSet_Buff[10];
 
static std::set<Tuple_Ptr_T> SetTupleCpp;
static CSet_Tuple_Ptr_T CSet_Tuple = {NULL};
static Tuple_Ptr_T Tuple_Buff[10];

int cset_tuple_cmp(Tuple_Ptr_T * const a, Tuple_Ptr_T * const b)
{
	if((*a)->id < (*b)->id) return -1;
	if((*a)->id == (*b)->id) return 0;
	if((*a)->id > (*b)->id) return 1;
}

TEST(Set,functionalities)
{
	Populate_CSet_Uint8(&CSetC, CSet_Buff, Num_Elems(CSet_Buff));
	Populate_CSet_Cmp_Tuple_Ptr(&CSet_Tuple, Tuple_Buff, Num_Elems(Tuple_Buff),
			(CSet_Cmp_T)cset_tuple_cmp);
}

TEST_P(Test_CSetC, insert_n_find)
{
	EXPECT_EQ(SetCpp.size(), CSetC.vtbl->size(&CSetC));

	SetCpp.insert(GetParam().id);
	CSetC.vtbl->insert(&CSetC, GetParam().id);
	EXPECT_EQ(*SetCpp.find(GetParam().id), *CSetC.vtbl->find(&CSetC, GetParam().id));

	SetTupleCpp.insert(Set_Data + GetParam().id);
	CSet_Tuple.vtbl->insert(&CSet_Tuple, (Tuple_Ptr_T) Set_Data + GetParam().id);
	EXPECT_EQ(*SetTupleCpp.find((Tuple_Ptr_T) Set_Data + GetParam().id), *CSet_Tuple.vtbl->find(&CSet_Tuple, (Tuple_Ptr_T)Set_Data + GetParam().id));
}

TEST_P(Test_CSetC, destroy)
{
		SetCpp.erase(SetCpp.begin(), SetCpp.end());
		CSetC.vtbl->erase(&CSetC, GetParam().id); 

		SetTupleCpp.erase(SetTupleCpp.begin(), SetTupleCpp.end());
		CSet_Tuple.vtbl->erase(&CSet_Tuple, (Tuple_Ptr_T)Set_Data + GetParam().id);

	if(0 == CSetC.vtbl->size(&CSetC))
	{
		_delete(&CSetC);
	}

	if(0 == CSet_Tuple.vtbl->size(&CSet_Tuple))
	{
		_delete(&CSet_Tuple);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CSetC, ::testing::ValuesIn(Set_Data));
