#include "gtest/gtest.h"
#include "gtest-template.h"

#include <memory>

std::shared_ptr<int> CPtrCpp;
union CPtr_int CPtrC = {NULL};

TEST(CPtr, populate)
{
  int i = -1;
  CPtrCpp = std::make_shared<int>(i);

  int * i_ptr = (int *)malloc(sizeof(int));
  CPtr_int_populate(&CPtrC, i_ptr);

  ASSERT_TRUE(i_ptr == CPtrC.ptr);
  ASSERT_EQ(*CPtrCpp, *CPtr_int_get(&CPtrC));
}

TEST(CPtr, share)
{
  int i = -1;

  {
    std::shared_ptr<int> shared = CPtrCpp;
    union CPtr_int shared_c = {NULL};

    CPtr_int_share(&CPtrC, &shared_c);

    ASSERT_EQ(shared.use_count(), CPtr_int_count(&CPtrC));

    _delete(&shared_c);
  }

  ASSERT_EQ(CPtrCpp.use_count(), CPtr_int_count(&CPtrC));
}

TEST(CPtr, swap)
{
  int * i = (int *) malloc(sizeof(int));
  *i = -100;

  CPtr_int_set(&CPtrC, i);
  ASSERT_EQ(-100, *CPtrC.ptr);
}

TEST(CPtr, delete)
{
  _delete(&CPtrC);
}
