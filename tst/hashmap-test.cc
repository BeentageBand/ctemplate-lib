#include "gtest/gtest.h"
#include "gtest-template.h"
#include <unordered_map>

class Test_CHashMap : public ::testing::TestWithParam<Uint8>
{};

const Uint8 Map_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};

static std::unordered_map<Uint8, Uint8> CHashMapCpp;
static union CHashMap_Uint8_Uint8 CHashMap = {NULL};
TEST(HashMap,functionalities)
{
  CHashMap_Uint8_Uint8_populate(&CHashMap, NULL, NULL);
}

TEST_P(Test_CHashMap, insert_n_find)
{
	EXPECT_EQ(CHashMapCpp.size(), CHashMap_Uint8_Uint8_size(&CHashMap));

	CHashMapCpp.insert(std::make_pair(GetParam(), GetParam()));
	CHashMap_Uint8_Uint8_insert(&CHashMap, GetParam(), GetParam());

  auto found = CHashMapCpp.find(GetParam());
  HashPair_Uint8_Uint8 * pair = CHashMap_Uint8_Uint8_find(&CHashMap, GetParam());
	EXPECT_EQ(found->first, pair->key);
	EXPECT_EQ(found->second, pair->value);
}

TEST_P(Test_CHashMap, destroy)
{
	static bool once = true;
	if(once)
	{
		CHashMapCpp.clear();
		CHashMap_Uint8_Uint8_clear(&CHashMap);
		once = false;

		_delete(&CHashMap);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CHashMap, ::testing::ValuesIn(Map_Data));
