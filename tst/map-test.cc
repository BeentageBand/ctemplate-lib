#include "gtest/gtest.h"
#include "gtest_template.h"

#include <map>
class Test_CMap : public ::testing::TestWithParam<Uint8_T>
{};

const Uint8_T Map_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};

static std::map<Uint8_T, Uint8_T> MapCpp;
static Map_Uint8_Uint8_T CMap;
TEST(Map,functionalities)
{
	CMap = Map_Uint8_Uint8();
}

TEST_P(Test_CMap, insert_n_find)
{
	EXPECT_EQ(MapCpp.empty(), CMap_Uint8_Uint8_empty(&CMap));

	MapCpp.insert(GetParam());
	CMap_Uint8_Uint8_insert(&CMap, &GetParam());

	EXPECT_EQ(*MapCpp.find(GetParam()), *CMap_Uint8_Uint8_find(&CMap, &GetParam()));
}

TEST_P(Test_CMap, destroy)
{
	static bool_t once = true;
	if(once)
	{
		MapCpp.clear();
		CMap_Uint8_Uint8_clear(&CMap);
		once = false;

		_delete(&CMap);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CMap, ::testing::ValuesIn(Map_Data));
/*=====================================================================================* 
 * map_gtest.cpp
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
