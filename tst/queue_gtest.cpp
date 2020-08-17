#define COBJECT_IMPLEMENTATION
#include "gtest_template.h"
#include "gtest/gtest.h"
 
#include <deque>

class Test_CQueue : public ::testing::TestWithParam<Uint8_T>
{};

const Uint8_T Queue_Data[] =
{
	25,
	173,
	0,
	48,
	199,
	240,
	255
};

static std::deque<Uint8_T> QueueCpp;
static CQueue_Uint8_T CQueueC = {NULL};
static Uint8_T CQueue_Buff[10];

TEST(CQueue,functionalities)
{
	Populate_CQueue_Uint8(&CQueueC, CQueue_Buff, Num_Elems(CQueue_Buff));
}

TEST_P(Test_CQueue, insert_n_find)
{
	EXPECT_EQ(QueueCpp.size(), CQueueC.vtbl->size(&CQueueC));

	QueueCpp.push_front(GetParam());
	CQueueC.vtbl->push_front(&CQueueC, GetParam());

	EXPECT_EQ(QueueCpp.front(), CQueueC.vtbl->front(&CQueueC));
}

TEST_P(Test_CQueue, destroy)
{
	QueueCpp.pop_back();
	CQueueC.vtbl->pop_back(&CQueueC);

	EXPECT_EQ(QueueCpp.size(), CQueueC.vtbl->size(&CQueueC));

	if(0 == CQueueC.vtbl->size(&CQueueC))
	{
		_delete(&CQueueC);
	}
}

INSTANTIATE_TEST_CASE_P(Data, Test_CQueue, ::testing::ValuesIn(Queue_Data));
