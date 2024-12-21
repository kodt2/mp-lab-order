#include "tlist.h"

#include <gtest.h>

TEST(Tlist, can_create_)
{
	ASSERT_NO_THROW(Tlist<int> m());
}

TEST(Tlist, can_pushback)
{
	Tlist<int> m1;
	ASSERT_NO_THROW(m1.push_back(10));
}

TEST(Tlist, equal_1)
{
	Tlist<int> m1;
	Tlist<int> m2;
	EXPECT_EQ(m1, m2);
}

TEST(Tlist, equal_2)
{
	Tlist<int> m1;
	m1.push_back(10);
	Tlist<int> m2;
	m2.push_back(10);
	EXPECT_EQ(m1, m2);
}

TEST(Tlist, not_equal)
{
	Tlist<int> m1;
	m1.push_back(10);
	Tlist<int> m2;
	EXPECT_NE(m1, m2);
}

TEST(Tlist, can_pop)
{
	Tlist<int> m;
	m.push_back(12);
	ASSERT_NO_THROW(m.pop());
}

TEST(Tlist, can_not_pop)
{
	Tlist<int> m;
	ASSERT_ANY_THROW(m.pop());
}

TEST(Tlist, can_top)
{
	Tlist<int> m;
	m.push_back(12);
	ASSERT_NO_THROW(m.top());
}

TEST(Tlist, can_not_top)
{
	Tlist<int> m;
	ASSERT_ANY_THROW(m.top());
}

TEST(Tlist, can_size)
{
	Tlist<int> m;
	m.push_back(12);
	ASSERT_NO_THROW(m.size());
}
