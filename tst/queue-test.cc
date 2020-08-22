#include "gtest/gtest.h"
#include "gtest-template.h"
 
#include <deque>

#define Num_Elems(arr) (size_t)(sizeof(arr)/sizeof(*arr))

class Test_CQueue : public ::testing::TestWithParam<Uint8>
{};

const Uint8 Queue_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};

static std::deque<Uint8> QueueCpp;
static union CQueue_Uint8 CQueueC = {NULL};
static Uint8 CQueue_Buff[10];

TEST(CQueue,functionalities)
{
	CQueue_Uint8_populate(&CQueueC, 0, 0, Num_Elems(CQueue_Buff), CQueue_Buff);
}

TEST_P(Test_CQueue, insert_n_find)
{
	EXPECT_EQ(QueueCpp.size(), CQueue_Uint8_size(&CQueueC));

	QueueCpp.push_front(GetParam());
	CQueue_Uint8_push_front(&CQueueC, GetParam());

	EXPECT_EQ(QueueCpp.front(), CQueue_Uint8_front(&CQueueC));
}

TEST_P(Test_CQueue, destroy)
{
	QueueCpp.pop_back();
	CQueue_Uint8_pop_back(&CQueueC);

	EXPECT_EQ(QueueCpp.size(), CQueue_Uint8_size(&CQueueC));

	if(0 == CQueue_Uint8_size(&CQueueC))
	{
		_delete(&CQueueC);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CQueue, ::testing::ValuesIn(Queue_Data));
