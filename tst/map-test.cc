#include "gtest/gtest.h"
#include "gtest-template.h"
#include <map>

class Test_CMap : public ::testing::TestWithParam<int>
{};

const int Map_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};

static std::map<int, int> CMapCpp;
static union CMap_int_int CMap = {NULL};
TEST(Map,functionalities)
{
  CMap_int_int_populate(&CMap, NULL);
}

TEST_P(Test_CMap, insert_n_find)
{
	EXPECT_EQ(CMapCpp.size(), CMap_int_int_size(&CMap));

	CMapCpp.insert(std::make_pair(GetParam(), GetParam()));
	CMap_int_int_insert(&CMap, GetParam(), GetParam());

  auto found = CMapCpp.find(GetParam());
  Pair_int_int * pair = CMap_int_int_find(&CMap, GetParam());
	EXPECT_EQ(found->first, pair->key);
	EXPECT_EQ(found->second, pair->value);
}

TEST_P(Test_CMap, destroy)
{
	static bool once = true;
	if(once)
	{
		CMapCpp.clear();
		CMap_int_int_clear(&CMap);
		once = false;

		_delete(&CMap);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CMap, ::testing::ValuesIn(Map_Data));
