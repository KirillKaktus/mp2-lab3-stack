#include "../стек/TLstack.h"
#include "../стек/Tcalc.h"
#include "gtest.h"
using namespace std;

/*TEST(TStack, can_create_stack_with_positive_size)// То что тут написано отображается только в консоли
{
  ASSERT_NO_THROW(Tstack<int> s(4));
}
TEST(TStack, can_get_top_element)
{
	Tstack<int> a(2);
	a.push(3);
	Tstack<double> b(2);
	b.push(1.0);
	EXPECT_EQ(a.top(), 3);
	EXPECT_EQ(b.top(), 1.0);
}
TEST(TStack, can_pop_element)
{
	Tstack<int> a(2);
	a.push(3);
	Tstack<double> b(2);
	b.push(1.0);
	EXPECT_EQ(a.pop(), 3);
	EXPECT_EQ(b.pop(), 1.0);
}
TEST(TStack, new_stack_is_empty)
{
	Tstack<int> a(2);
	EXPECT_EQ(a.empty(), 1);
}
TEST(TStack, can_push_and_pop)
{
	Tstack<int> a(3);
	a.push(3);
	a.push(4);
	EXPECT_EQ(a.pop(), 4);
	EXPECT_EQ(a.pop(), 3);
	Tstack<double> b(3);
	b.push(3.0);
	b.push(4.0);
	EXPECT_EQ(b.pop(), 4.0);
	EXPECT_EQ(b.pop(), 3.0);
}
TEST(TStack, cant_use_top_in_empty_stack)
{
	Tstack<int> a(2);
	EXPECT_ANY_THROW(a.top());
}
TEST(TStack, cant_use_pop_in_empty_stack)
{
	Tstack<int> a(2);
	EXPECT_ANY_THROW(a.pop());
}
TEST(TStack, cant_push_to_full_stack)
{
	Tstack<int> a(2);
	a.push(1);
	a.push(3);
	EXPECT_ANY_THROW(a.push(4));
}
TEST(TStack, stack_is_full)
{
	Tstack<int> a(2);
	a.push(1);
	a.push(3);
	EXPECT_EQ(a.full(), 1);
}
TEST(TStack, stack_is_not_completely_full)
{
	Tstack<int> a(2);
	a.push(1);
	EXPECT_EQ(a.full(), 0);
}
TEST(TStack, can_clear_stack)
{
	Tstack<int> a(2);
	a.push(1);
	a.push(3);
	a.clear();
	EXPECT_EQ(a.empty(), 1);
}
TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Tstack<int>s(-3));
}
TEST(TStack, throws_when_push_in_full_stack)
{
	Tstack<int>s(2);
	s.push(2);
	s.push(2);
	ASSERT_ANY_THROW(s.push(2));
}
TEST(TStack, stack_is_empty)
{
	Tstack<int> s(2);
	s.push(2);
	s.push(2);
	int a = s.pop();
	a = s.pop();
	EXPECT_EQ(s.empty(), 1);
}
TEST(TStack, copy_constructor_works)
{
	Tstack<int> s(2);
	s.push(2);
	s.push(2);
	Tstack<int> s1(s);
	EXPECT_EQ(s.pop(), s1.pop());
	EXPECT_EQ(s.pop(), s1.pop());
}*/




TEST(Tcalc, can_calc_the_expression)
{
	Tcalc c("(5+(6-4)*6-4^2)/2");
	EXPECT_EQ(c.calc(), (5 + (6 - 4) * 6 - pow(4,2)) / 2);
}
TEST(Tcalc, throws_when_there_is_an_extra_operator)
{
	Tcalc c("5+6+-(2-3)");
	ASSERT_ANY_THROW(c.calc());
	
	
}
TEST(Tcalc, throws_when_create_calc_with_extra_bracket)
{
	ASSERT_ANY_THROW(Tcalc c("5+6*(2-3))"));
	
}
TEST(Tcalc, postfix_is_right)
{
	Tcalc c("5+6*(2-3)");
	EXPECT_EQ(c.get_postfix(), "5623-*+");
}
TEST(Tcalc, postfix_get_infix)
{
	Tcalc c("5+6*(2-3)");
	EXPECT_EQ(c.get_infix(), "5+6*(2-3)");
}
TEST(Tcalc, can_calc_postfix)
{
	Tcalc c("5+6*(2-3)");
	EXPECT_EQ(c.calcpostfix(), -1);
}
TEST(Tcalc, can_set_infix)
{
	Tcalc c;
	c.set_infix("5+5+6*8");
	EXPECT_EQ(c.get_infix(), "5+5+6*8");
}