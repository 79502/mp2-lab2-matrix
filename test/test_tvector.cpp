#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(10);
	for (size_t i = 0; i < v.size(); i++)
		v[i] = 1;
	TDynamicVector<int> v1(v);

	EXPECT_EQ(v.size(), v1.size());
	for (size_t i = 0; i < v.size(); i++) {
		EXPECT_EQ(v[i], v1[i]);
	}
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> v1(v);
	EXPECT_NE(&v, &v1);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	int i;
	ASSERT_ANY_THROW(i = v[-1]);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	int i;
	ASSERT_ANY_THROW(i = v[4]);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(4);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(4);
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(4);
	v1 = v2;
	size_t i = 4;
	EXPECT_EQ(v1.size(), i);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(7);
	TDynamicVector<int> v3(7);
	ASSERT_NO_THROW(v2 = v1);
	ASSERT_NO_THROW(v1 = v3);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	v1[1] = 1;
	v2[1] = 1;
	ASSERT_TRUE(v1 == v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v1(7);
	ASSERT_TRUE(v1 == v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(2);
	ASSERT_TRUE(v1 != v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v1(3);
	ASSERT_NO_THROW(v1 + 3);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v1(3);
	ASSERT_NO_THROW(v1 - 3);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v1(3);
	ASSERT_NO_THROW(v1 * 3);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	ASSERT_NO_THROW(v1 + v2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(4);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	ASSERT_NO_THROW(v1 - v2);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(4);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	ASSERT_NO_THROW(v1 * v2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(4);
	ASSERT_ANY_THROW(v1 * v2);
}

