#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);
	EXPECT_EQ(m.size(), m1.size());
	for (size_t i = 0; i < 5; i ++)
	EXPECT_EQ(m[i], m1[i]);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);
	EXPECT_NE(&m, &m1);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(3);
	int i;
	ASSERT_NO_THROW(m[1][1] = 2);
	ASSERT_NO_THROW(i = m[1][1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(3);
	ASSERT_ANY_THROW(m[-1][1] = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(3);
	ASSERT_ANY_THROW(m[3][1] = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(3);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(4);
	m1 = m;
	EXPECT_EQ(3, m1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(4);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);
	ASSERT_TRUE(m1 == m);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(3);
	ASSERT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(4);
	EXPECT_NE(m, m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> m2(3);
	ASSERT_NO_THROW(m2+ m1);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(4);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);
	ASSERT_NO_THROW(m - m1);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(4);
	ASSERT_ANY_THROW(m - m1);
}

