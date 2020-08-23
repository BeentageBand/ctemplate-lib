#include "gtest/gtest.h"
#include "gtest-template.h"
#include <unordered_map>

class Test_CHashMap : public ::testing::TestWithParam<int>
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

static std::unordered_map<int, int> CHashMapCpp;
static union CHashMap_int_int CHashMap = {NULL};
TEST(HashMap,functionalities)
{
  CHashMap_int_int_populate(&CHashMap, NULL, NULL);
}

TEST_P(Test_CHashMap, insert_n_find)
{
	EXPECT_EQ(CHashMapCpp.size(), CHashMap_int_int_size(&CHashMap));

	CHashMapCpp.insert(std::make_pair(GetParam(), GetParam()));
	CHashMap_int_int_insert(&CHashMap, GetParam(), GetParam());

  auto found = CHashMapCpp.find(GetParam());
  HashPair_int_int * pair = CHashMap_int_int_find(&CHashMap, GetParam());

  ASSERT_FALSE(NULL == pair);
	EXPECT_EQ(found->first, pair->key);
	EXPECT_EQ(found->second, pair->value);
}

TEST_P(Test_CHashMap, destroy)
{
	static bool once = true;
	if(once)
	{
		CHashMapCpp.clear();
		CHashMap_int_int_clear(&CHashMap);
		once = false;

		_delete(&CHashMap);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CHashMap, ::testing::ValuesIn(Map_Data));
