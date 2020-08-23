#include "gtest/gtest.h"
#include "gtest-template.h"
 
#include <deque>

#define Num_Elems(arr) (size_t)(sizeof(arr)/sizeof(*arr))

class Test_CQueue : public ::testing::TestWithParam<int>
{};

const int Queue_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};

static std::deque<int> QueueCpp;
static union CQueue_int CQueueC = {NULL};
static int CQueue_Buff[10];

TEST(CQueue,functionalities)
{
	CQueue_int_populate(&CQueueC, 0, 0, Num_Elems(CQueue_Buff), CQueue_Buff);
}

TEST_P(Test_CQueue, insert_n_find)
{
	EXPECT_EQ(QueueCpp.size(), CQueue_int_size(&CQueueC));

	QueueCpp.push_front(GetParam());
	CQueue_int_push_front(&CQueueC, GetParam());

	EXPECT_EQ(QueueCpp.front(), CQueue_int_front(&CQueueC));
}

TEST_P(Test_CQueue, destroy)
{
	QueueCpp.pop_back();
	CQueue_int_pop_back(&CQueueC);

	EXPECT_EQ(QueueCpp.size(), CQueue_int_size(&CQueueC));

	if(0 == CQueue_int_size(&CQueueC))
	{
		_delete(&CQueueC);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CQueue, ::testing::ValuesIn(Queue_Data));
