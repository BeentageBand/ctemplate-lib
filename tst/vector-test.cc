#include "gtest/gtest.h"
#include "gtest-template.h"
#include <iostream>

#define Num_Elems(arr) (size_t)(sizeof(arr)/sizeof(*arr))

#include <vector>

class Test_CVector : public ::testing::TestWithParam<int>
{};
 
const int Vector_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};
static std::vector<int> VectorCpp;
static union CVector_int CVectorC = {NULL};
static int CVectorC_Buff[10];
 
int main(int argc, char ** argv)
{
  std::cout << "Running main()" << std::endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Vector,functionalities)
{
	CVector_int_populate(&CVectorC, 0, Num_Elems(CVectorC_Buff), CVectorC_Buff);
}

TEST_P(Test_CVector, insert_n_find)
{
	EXPECT_EQ(VectorCpp.size(), CVector_int_size(&CVectorC));

	VectorCpp.push_back(GetParam());
	CVector_int_push_back(&CVectorC, GetParam());

	EXPECT_EQ(VectorCpp.back(), CVector_int_back(&CVectorC));

	std::cout << "CVectorC size = " << CVector_int_size(&CVectorC) << ", VectorCpp size = " << 
		VectorCpp.size() << std::endl;
}

TEST_P(Test_CVector, destroy)
{
	VectorCpp.pop_back();
	CVector_int_pop_back(&CVectorC);

	EXPECT_EQ(VectorCpp.size(), CVector_int_size(&CVectorC));

	if(0 == CVector_int_size(&CVectorC))
	{
		_delete(&CVectorC);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CVector, ::testing::ValuesIn(Vector_Data));
