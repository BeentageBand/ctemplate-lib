#include "gtest/gtest.h"
#include "gtest-template.h"
 
#include <algorithm>
#include <vector>

#define Num_Elems(arr) (size_t)(sizeof(arr)/sizeof(*arr))

class Test_PQueue : public ::testing::TestWithParam<int>
{};

const int PQueue_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};

static std::vector<int> PQueueCPP;
static union CPriorityQueue_int CPriorityQueueC = {NULL};

TEST(CPriorityQueue,functionalities)
{
	CPriorityQueue_int_populate(&CPriorityQueueC, NULL);
}

TEST_P(Test_PQueue, insert_n_find)
{
	EXPECT_EQ(PQueueCPP.size(), CPriorityQueue_int_size(&CPriorityQueueC));

  std::make_heap(PQueueCPP.begin(), PQueueCPP.end());
	PQueueCPP.push_back(GetParam());

	CPriorityQueue_int_push(&CPriorityQueueC, GetParam());

	EXPECT_EQ(PQueueCPP.back(), CPriorityQueue_int_peek(&CPriorityQueueC));
}

TEST_P(Test_PQueue, destroy)
{
	PQueueCPP.pop_back();
	CPriorityQueue_int_poll(&CPriorityQueueC);

	EXPECT_EQ(PQueueCPP.size(), CPriorityQueue_int_size(&CPriorityQueueC));

	if(0 == CPriorityQueue_int_size(&CPriorityQueueC))
	{
		_delete(&CPriorityQueueC);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_PQueue, ::testing::ValuesIn(PQueue_Data));
