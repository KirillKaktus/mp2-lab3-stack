#include "../стек/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)// “о что тут написано отображаетс€ в консоли
{
  ASSERT_NO_THROW(Tstack<int> s);
}

