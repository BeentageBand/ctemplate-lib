#include "gtest/gtest.h"
#include "gtest-template.h"
#include <iostream>

#define Num_Elems(arr) (size_t)(sizeof(arr)/sizeof(*arr))

#include <vector>

class Test_CVector : public ::testing::TestWithParam<Uint8>
{};
 
const Uint8 Vector_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};
static std::vector<Uint8> VectorCpp;
static union CVector_Uint8 CVectorC = {NULL};
static Uint8 CVectorC_Buff[10];
 
int main(int argc, char ** argv)
{
  std::cout << "Running main()" << std::endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Vector,functionalities)
{
	CVector_Uint8_populate(&CVectorC, 0, Num_Elems(CVectorC_Buff), CVectorC_Buff);
}

TEST_P(Test_CVector, insert_n_find)
{
	EXPECT_EQ(VectorCpp.size(), CVector_Uint8_size(&CVectorC));

	VectorCpp.push_back(GetParam());
	CVector_Uint8_push_back(&CVectorC, GetParam());

	EXPECT_EQ(VectorCpp.back(), CVector_Uint8_back(&CVectorC));

	std::cout << "CVectorC size = " << CVector_Uint8_size(&CVectorC) << ", VectorCpp size = " << 
		VectorCpp.size() << std::endl;
}

TEST_P(Test_CVector, destroy)
{
	VectorCpp.pop_back();
	CVector_Uint8_pop_back(&CVectorC);

	EXPECT_EQ(VectorCpp.size(), CVector_Uint8_size(&CVectorC));

	if(0 == CVector_Uint8_size(&CVectorC))
	{
		_delete(&CVectorC);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CVector, ::testing::ValuesIn(Vector_Data));
