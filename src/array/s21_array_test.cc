// g++ -std=c++17  -lgtest s21_array_test.cc
// CK_FORK=no leaks -atExit -- ./a.out
#include "s21_array.h"

#include <gtest/gtest.h>

#include <array>
#include <iostream>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
TEST(arrayTest, DefaultConstructor_Emptyarray) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.size(), 5);
}
TEST(array_constructor, case1) {
  s21::array<int, 4> s21_arr_int;
  s21::array<double, 4> s21_arr_double;
  s21::array<std::string, 4> s21_arr_string;

  EXPECT_EQ(s21_arr_int.size(), 4U);
  EXPECT_EQ(s21_arr_double.size(), 4U);
  EXPECT_EQ(s21_arr_string.size(), 4U);
}
TEST(array_constructor, case2) {
  s21::array<int, 5> s21_arr_int{1, 4, 8, 9, 1};
  s21::array<double, 5> s21_arr_double{1.4, 4.8, 8.9, 9.1, 1.1};
  s21::array<std::string, 5> s21_arr_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(s21_arr_int.size(), 5U);
  EXPECT_EQ(s21_arr_int[0], 1);

  EXPECT_EQ(s21_arr_double.size(), 5U);
  EXPECT_EQ(s21_arr_double[0], 1.4);

  EXPECT_EQ(s21_arr_string.size(), 5U);
  EXPECT_EQ(s21_arr_string[0], "Hello");
}
TEST(array_constructor, case3) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int(s21_arr_ref_int);

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double(s21_arr_ref_double);

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string(s21_arr_ref_string);

  EXPECT_EQ(s21_arr_ref_int.size(), s21_arr_res_int.size());
  EXPECT_EQ(s21_arr_ref_int[0], s21_arr_res_int[0]);
  EXPECT_EQ(s21_arr_ref_int[1], s21_arr_res_int[1]);
  EXPECT_EQ(s21_arr_ref_int[2], s21_arr_res_int[2]);
  EXPECT_EQ(s21_arr_ref_int[3], s21_arr_res_int[3]);

  EXPECT_EQ(s21_arr_ref_double.size(), s21_arr_res_double.size());
  EXPECT_EQ(s21_arr_ref_double[0], s21_arr_res_double[0]);
  EXPECT_EQ(s21_arr_ref_double[1], s21_arr_res_double[1]);
  EXPECT_EQ(s21_arr_ref_double[2], s21_arr_res_double[2]);
  EXPECT_EQ(s21_arr_ref_double[3], s21_arr_res_double[3]);

  EXPECT_EQ(s21_arr_ref_string.size(), s21_arr_res_string.size());
  EXPECT_EQ(s21_arr_ref_string[0], s21_arr_res_string[0]);
  EXPECT_EQ(s21_arr_ref_string[1], s21_arr_res_string[1]);
  EXPECT_EQ(s21_arr_ref_string[2], s21_arr_res_string[2]);
  EXPECT_EQ(s21_arr_ref_string[3], s21_arr_res_string[3]);
}
TEST(array_constructor, case4) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int = std::move(s21_arr_ref_int);

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double = std::move(s21_arr_ref_double);

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string = std::move(s21_arr_ref_string);

  EXPECT_EQ(s21_arr_res_int.size(), 4U);
  EXPECT_EQ(s21_arr_res_int[0], 1);
  EXPECT_EQ(s21_arr_res_int[1], 4);
  EXPECT_EQ(s21_arr_res_int[2], 8);
  EXPECT_EQ(s21_arr_res_int[3], 9);

  EXPECT_EQ(s21_arr_res_double.size(), 4U);
  EXPECT_EQ(s21_arr_res_double[0], 1.4);
  EXPECT_EQ(s21_arr_res_double[1], 4.8);
  EXPECT_EQ(s21_arr_res_double[2], 8.9);
  EXPECT_EQ(s21_arr_res_double[3], 9.1);

  EXPECT_EQ(s21_arr_res_string.size(), 4U);
  EXPECT_EQ(s21_arr_res_string[0], "Hello");
  EXPECT_EQ(s21_arr_res_string[1], ",");
  EXPECT_EQ(s21_arr_res_string[2], "world");
  EXPECT_EQ(s21_arr_res_string[3], "!");
}
TEST(array_constructor, case6) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int;
  s21_arr_res_int = std::move(s21_arr_ref_int);

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double;
  s21_arr_res_double = std::move(s21_arr_ref_double);

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string;
  s21_arr_res_string = std::move(s21_arr_ref_string);

  EXPECT_EQ(s21_arr_res_int.size(), 4U);
  EXPECT_EQ(s21_arr_res_int[0], 1);
  EXPECT_EQ(s21_arr_res_int[1], 4);
  EXPECT_EQ(s21_arr_res_int[2], 8);
  EXPECT_EQ(s21_arr_res_int[3], 9);

  EXPECT_EQ(s21_arr_res_double.size(), 4U);
  EXPECT_EQ(s21_arr_res_double[0], 1.4);
  EXPECT_EQ(s21_arr_res_double[1], 4.8);
  EXPECT_EQ(s21_arr_res_double[2], 8.9);
  EXPECT_EQ(s21_arr_res_double[3], 9.1);

  EXPECT_EQ(s21_arr_res_string.size(), 4U);
  EXPECT_EQ(s21_arr_res_string[0], "Hello");
  EXPECT_EQ(s21_arr_res_string[1], ",");
  EXPECT_EQ(s21_arr_res_string[2], "world");
  EXPECT_EQ(s21_arr_res_string[3], "!");
}
TEST(array_at, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.at(0), 1);
  EXPECT_EQ(s21_arr_double.at(0), 1.4);
  EXPECT_EQ(s21_arr_string.at(0), "Hello");
}

TEST(array_at, case2) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_THROW(s21_arr_int.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr_double.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr_string.at(5), std::out_of_range);
}

TEST(array_at, case3) {
  s21::array<int, 0> s21_arr_int;
  s21::array<double, 0> s21_arr_double;
  s21::array<std::string, 0> s21_arr_string;

  EXPECT_THROW(s21_arr_int.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr_double.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr_string.at(5), std::out_of_range);
}
TEST(array_square_braces, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int[1], 4);
  EXPECT_EQ(s21_arr_double[1], 4.8);
  EXPECT_EQ(s21_arr_string[0], "Hello");
}
TEST(array_front, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.front(), 1);
  EXPECT_EQ(s21_arr_double.front(), 1.4);
  EXPECT_EQ(s21_arr_string.front(), "Hello");
}
TEST(array_back, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.back(), 9);
  EXPECT_EQ(s21_arr_double.back(), 9.1);
  EXPECT_EQ(s21_arr_string.back(), "!");
}
//???????????????????????????????????
TEST(array_data, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};
  auto n = s21_arr_string[0];
  EXPECT_EQ(s21_arr_int.data(), &s21_arr_int[0]);
  EXPECT_EQ(s21_arr_double.data(), &s21_arr_double[0]);
  EXPECT_EQ(s21_arr_string.data(), &s21_arr_string[0]);
}
TEST(arrayTest, DefaultConstructor_Emptyarray1) {
  s21::array<int, 0> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(array_begin, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.begin(), &s21_arr_int[0]);
  EXPECT_EQ(s21_arr_double.begin(), &s21_arr_double[0]);
  EXPECT_EQ(s21_arr_string.begin(), &s21_arr_string[0]);
}
TEST(array_end, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.end(), &s21_arr_int[0] + 4);
  EXPECT_EQ(s21_arr_double.end(), &s21_arr_double[0] + 4);
  EXPECT_EQ(s21_arr_string.end(), &s21_arr_string[0] + 4);
}
TEST(array_empty, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.empty(), 0);
  EXPECT_EQ(s21_arr_double.empty(), 0);
  EXPECT_EQ(s21_arr_string.empty(), 0);
}

TEST(array_empty, case2) {
  s21::array<int, 0> s21_arr_int;
  s21::array<double, 0> s21_arr_double;
  s21::array<std::string, 0> s21_arr_string;

  EXPECT_EQ(s21_arr_int.empty(), 1);
  EXPECT_EQ(s21_arr_double.empty(), 1);
  EXPECT_EQ(s21_arr_string.empty(), 1);
}
TEST(array_size, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.size(), 4U);
  EXPECT_EQ(s21_arr_double.size(), 4U);
  EXPECT_EQ(s21_arr_string.size(), 4U);
}

TEST(array_size, case2) {
  s21::array<int, 0> s21_arr_int;
  s21::array<double, 0> s21_arr_double;
  s21::array<std::string, 0> s21_arr_string;

  EXPECT_EQ(s21_arr_int.size(), 0U);
  EXPECT_EQ(s21_arr_double.size(), 0U);
  EXPECT_EQ(s21_arr_string.size(), 0U);
}
TEST(array_max_size, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  std::array<int, 4> std_arr_int{1, 4, 8, 9};

  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  std::array<double, 4> std_arr_double{1.4, 4.8, 8.9, 9.1};

  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};
  std::array<std::string, 4> std_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_arr_int.max_size(), std_arr_int.max_size());
  EXPECT_EQ(s21_arr_double.max_size(), std_arr_double.max_size());
  EXPECT_EQ(s21_arr_string.max_size(), std_arr_string.max_size());
}
TEST(array_swap, case1) {
  s21::array<int, 4> s21_arr_ref_int{1, 4, 8, 9};
  s21::array<int, 4> s21_arr_res_int{21, 21, 21, 21};

  s21::array<double, 4> s21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::array<double, 4> s21_arr_res_double{21.0, 21.0, 21.0, 21.0};

  s21::array<std::string, 4> s21_arr_ref_string{"Hello", ",", "world", "!"};
  s21::array<std::string, 4> s21_arr_res_string{"21", "21", "21", "21"};

  s21_arr_ref_int.swap(s21_arr_res_int);
  s21_arr_ref_double.swap(s21_arr_res_double);
  s21_arr_ref_string.swap(s21_arr_res_string);

  EXPECT_EQ(s21_arr_ref_int[3], 21);
  EXPECT_EQ(s21_arr_res_int[0], 1);
  EXPECT_EQ(s21_arr_res_int[1], 4);
  EXPECT_EQ(s21_arr_res_int[2], 8);
  EXPECT_EQ(s21_arr_res_int[3], 9);

  EXPECT_EQ(s21_arr_ref_double[3], 21.0);
  EXPECT_EQ(s21_arr_res_double[0], 1.4);
  EXPECT_EQ(s21_arr_res_double[1], 4.8);
  EXPECT_EQ(s21_arr_res_double[2], 8.9);
  EXPECT_EQ(s21_arr_res_double[3], 9.1);

  EXPECT_EQ(s21_arr_ref_string[3], "21");
  EXPECT_EQ(s21_arr_res_string[0], "Hello");
  EXPECT_EQ(s21_arr_res_string[1], ",");
  EXPECT_EQ(s21_arr_res_string[2], "world");
  EXPECT_EQ(s21_arr_res_string[3], "!");
}
TEST(array_fill, case1) {
  s21::array<int, 4> s21_arr_int{1, 4, 8, 9};
  s21::array<double, 4> s21_arr_double{1.4, 4.8, 8.9, 9.1};
  s21::array<std::string, 4> s21_arr_string{"Hello", ",", "world", "!"};

  s21_arr_int.fill(21);
  s21_arr_double.fill(21.0);
  s21_arr_string.fill("21");

  EXPECT_EQ(s21_arr_int[0], 21);
  EXPECT_EQ(s21_arr_int[1], 21);
  EXPECT_EQ(s21_arr_int[2], 21);
  EXPECT_EQ(s21_arr_int[3], 21);

  EXPECT_EQ(s21_arr_double[0], 21.0);
  EXPECT_EQ(s21_arr_double[1], 21.0);
  EXPECT_EQ(s21_arr_double[2], 21.0);
  EXPECT_EQ(s21_arr_double[3], 21.0);

  EXPECT_EQ(s21_arr_string[0], "21");
  EXPECT_EQ(s21_arr_string[1], "21");
  EXPECT_EQ(s21_arr_string[2], "21");
  EXPECT_EQ(s21_arr_string[3], "21");
}

//
TEST(arrayTest, SizeConstructor_PositiveSize) {
  const size_t size = 5;
  s21::array<int, size> v;
  // std::array<int, size> v1;
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), size);
}
//
TEST(arrayTest, SizeConstructor_ZeroSize) {
  const size_t size = 0;
  s21::array<int, size> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), size);
}
//
TEST(arrayTest, InitializerListConstructor_EmptyList) {
  s21::array<int, 0> v = {};
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(arrayTest, InitializerListConstructor_NonEmptyList) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}
//
TEST(arrayTest, CopyConstructor_Emptyarray) {
  s21::array<int, 0> v1;
  s21::array<int, 0> v2(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}
//
TEST(arrayTest, CopyConstructor_NonEmptyarray) {
  s21::array<int, 3> v1 = {1, 2, 3};
  s21::array<int, 3> v2(v1);
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}
//
TEST(arrayTest, MoveConstructor_Emptyarray) {
  s21::array<int, 0> v1;
  s21::array<int, 0> v2(std::move(v1));
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}
//
TEST(arrayTest, MoveConstructor_NonEmptyarray) {
  s21::array<int, 3> v1 = {1, 2, 3};
  s21::array<int, 3> v2(std::move(v1));
  EXPECT_EQ(v2.size(), 3);
  EXPECT_FALSE(v1.empty());
}
//
TEST(arrayTest, Destructor_Emptyarray) {
  s21::array<int, 0> *v = new s21::array<int, 0>();
  delete v;
}

TEST(arrayTest, Destructor_NonEmptyarray) {
  s21::array<int, 3> *v = new s21::array<int, 3>{1, 2, 3};
  delete v;
}

TEST(arrayTest, MoveAssignmentOperator_EmptyToEmpty) {
  s21::array<int, 0> v1;
  s21::array<int, 0> v2;
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(arrayTest, MoveAssignmentOperator_NonEmptyToEmpty) {
  s21::array<int, 3> v1 = {1, 2, 3};
  s21::array<int, 3> v2;
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_FALSE(v1.empty());
}

TEST(arrayTest, MoveAssignmentOperator_EmptyToNonEmpty) {
  s21::array<int, 3> v1;
  s21::array<int, 3> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_TRUE(!v2.empty());
  EXPECT_EQ(v2.size(), 3);
}

TEST(arrayTest, MoveAssignmentOperator_NonEmptyToNonEmpty) {
  s21::array<int, 3> v1 = {1, 2, 3};
  s21::array<int, 3> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_FALSE(v1.empty());
}

TEST(arrayTest, At_ValidIndex) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.at(4), 5);
}

TEST(arrayTest, At_InvalidIndex) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(arrayTest, IndexOperator_ValidIndex) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(arrayTest, IndexOperator_InvalidIndex) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(arrayTest, ConstIndexOperator_ValidIndex) {
  const s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(arrayTest, ConstIndexOperator_InvalidIndex) {
  const s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(arrayTest, FrontConst_Validarray) {
  const s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.front(), 1);
}

TEST(arrayTest, FrontConst_Emptyarray) {
  const s21::array<int, 0> v;
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(arrayTest, BackConst_Validarray) {
  const s21::array<int, 5> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.back(), 5);
}

TEST(arrayTest, BackConst_Emptyarray) {
  const s21::array<int, 0> v;
  EXPECT_THROW(v.back(), std::out_of_range);
}

TEST(arrayTest, Data_Validarray) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  int *dataPtr = v.data();
  EXPECT_EQ(*dataPtr, 1);
  *dataPtr = 10;
  EXPECT_EQ(v[0], 10);
}
TEST(arrayTest, Data_Emptyarray) {
  s21::array<int, 0> v;
  int *dataPtr = v.data();
  EXPECT_EQ(dataPtr, nullptr);
}
TEST(arrayTest, Begin_Validarray) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  *it = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(arrayTest, Begin_Emptyarray) {
  s21::array<int, 0> v;
  auto it = v.begin();
  EXPECT_EQ(it, v.end());
}

TEST(arrayTest, End_Validarray) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  auto it = v.end();
  auto beginIt = v.begin();
  EXPECT_NE(it, beginIt);
}

TEST(arrayTest, End_Emptyarray) {
  s21::array<int, 0> v;
  auto it = v.end();
  EXPECT_EQ(it, v.begin());
}

TEST(arrayTest, Empty_Emptyarray) {
  const s21::array<int, 0> v;
  EXPECT_TRUE(v.empty());
}

TEST(arrayTest, Empty_NonEmptyarray) {
  const s21::array<int, 3> v = {1, 2, 3};
  EXPECT_FALSE(v.empty());
}

TEST(arrayTest, Size_Emptyarray) {
  const s21::array<int, 0> v;
  EXPECT_EQ(v.size(), 0);
}

TEST(arrayTest, Size_NonEmptyarray) {
  const s21::array<int, 3> v = {1, 2, 3};
  EXPECT_EQ(v.size(), 3);
}

TEST(arrayTest, MaxSize) {
  s21::array<int, 0> v;
  std::array<int, 0> v1;

  EXPECT_EQ(v.max_size(), v1.max_size());
}

TEST(arrayTest, Swap_NonEmptyarrays) {
  s21::array<int, 3> v1 = {1, 2, 3};
  s21::array<int, 3> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);
}

TEST(arrayTest, Swap_yarrays) {
  s21::array<int, 3> v1;
  s21::array<int, 3> v2 = {1, 2, 3};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_FALSE(v1.empty());
  EXPECT_EQ(v2.size(), 3);
  EXPECT_FALSE(v2.empty());
}

TEST(arrayConstructorTest, DefaultConstructor) {
  s21::array<int, 0> v;

  EXPECT_EQ(v.size(), 0);

  EXPECT_EQ(v.data(), nullptr);
}

TEST(arrayConstructorTest, SizeConstructor) {
  s21::array<int, 5> v;

  EXPECT_EQ(v.size(), 5);
}

TEST(arrayConstructorTest, InitializerListConstructor) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};

  EXPECT_EQ(v.size(), 5);

  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(v[i], i + 1);
  }
}

TEST(arrayConstructorTest, EmptyInitializerListConstructor) {
  s21::array<int, 0> v = {};

  EXPECT_EQ(v.size(), 0);
}

TEST(arrayConstructorTest, CopyConstructor) {
  s21::array<int, 5> v1 = {1, 2, 3, 4, 5};

  s21::array<int, 5> v2(v1);

  EXPECT_EQ(v2.size(), v1.size());

  for (size_t i = 0; i < v2.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST(arrayConstructorTest, EmptyCopyConstructor) {
  s21::array<int, 0> v1;

  s21::array<int, 0> v2(v1);

  EXPECT_EQ(v2.size(), 0);
}

TEST(arrayConstructorTest, MoveConstructor) {
  s21::array<int, 5> v1 = {1, 2, 3, 4, 5};

  s21::array<int, 5> v2(std::move(v1));

  EXPECT_EQ(v2.size(), 5);

  for (size_t i = 0; i < v2.size(); ++i) {
    EXPECT_EQ(v2[i], i + 1);
  }

  EXPECT_EQ(v1.size(), 5);
}

TEST(arrayConstructorTest, EmptyMoveConstructor) {
  s21::array<int, 0> v1;

  s21::array<int, 0> v2(std::move(v1));

  EXPECT_EQ(v2.size(), 0);

  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.data(), nullptr);
}

TEST(arrayDestructorTest, NonEmptyarray) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};

  EXPECT_NO_THROW({ v.~array(); });

  EXPECT_EQ(v.size(), 5);

  EXPECT_EQ(v.data(), v.begin());
}

TEST(arrayDestructorTest, Emptyarray) {
  s21::array<int, 0> v;

  EXPECT_NO_THROW({ v.~array(); });

  EXPECT_EQ(v.size(), 0);

  EXPECT_EQ(v.data(), nullptr);
}

TEST(arrayMoveAssignmentTest, MoveEmptyarray) {
  s21::array<int, 0> src;

  s21::array<int, 0> dest;
  dest = std::move(src);

  EXPECT_EQ(src.size(), 0);
  EXPECT_EQ(src.data(), nullptr);

  EXPECT_EQ(dest.size(), 0);
  EXPECT_EQ(dest.data(), nullptr);
}

TEST(arrayMoveAssignmentTest, MoveNonEmptyarray) {
  s21::array<int, 5> src = {1, 2, 3, 4, 5};

  s21::array<int, 5> dest;
  dest = std::move(src);

  EXPECT_EQ(src.size(), 5);

  EXPECT_EQ(dest.size(), 5);
  EXPECT_EQ(dest[0], 1);
  EXPECT_EQ(dest[1], 2);
  EXPECT_EQ(dest[2], 3);
  EXPECT_EQ(dest[3], 4);
  EXPECT_EQ(dest[4], 5);
}

TEST(arraySwapTest, SwapEmptyarrays) {
  s21::array<int, 0> v1;
  s21::array<int, 0> v2;

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.data(), nullptr);

  EXPECT_EQ(v2.size(), 0);
  EXPECT_EQ(v2.data(), nullptr);
}

TEST(arraySwapTest, SwapNonEmptyarrays) {
  s21::array<int, 3> v1 = {1, 2, 3};
  s21::array<int, 3> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_NE(v1.data(), nullptr);
  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[1], 5);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2.size(), 3);
  EXPECT_NE(v2.data(), nullptr);
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, Swap_NonEmptyVectors) {
  s21::array<int, 3> v1 = {1, 2, 3};
  s21::array<int, 3> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);
}

TEST(array_test, operator_eq) {
  s21::array<int, 7> vec1 = {1, 2, 3, 5, 6, 3, 4};
  s21::array<int, 7> vec2;
  vec2 = vec1;
  EXPECT_EQ(vec1.size(), vec2.size());
  auto it_2 = vec2.begin();
  for (auto it = vec1.begin(); it != vec1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(array_test, operator_brackets) {
  s21::array<int, 5> vec1 = {1, 2, 3, 4, 5};
  std::array<int, 5> vec2 = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < vec1.size(); i++) {
    EXPECT_EQ(vec1[i], vec2[i]);
  }
  EXPECT_EQ(vec1.size(), vec2.size());
}

TEST(array_test, front) {
  s21::array<int, 3> vec1 = {1, 2, 3};
  std::array<int, 3> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.front(), vec2.front());
  EXPECT_EQ(vec1.size(), vec2.size());
}
TEST(array_test, back) {
  s21::array<int, 3> vec1 = {1, 2, 3};
  std::array<int, 3> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.back(), vec2.back());
  EXPECT_EQ(vec1.size(), vec2.size());
}

TEST(array_test, data) {
  s21::array<int, 0> vec1;
  EXPECT_EQ(vec1.data(), nullptr);
  s21::array<int, 3> vec2 = {1, 2, 3};
  EXPECT_FALSE(vec2.data() == nullptr);
}

TEST(array_test, begin) {
  s21::array<int, 5> vec1 = {1, 2, 3, 4, 5};
  std::array<int, 5> vec2 = {1, 2, 3, 4, 5};
  auto iter1 = vec1.begin();
  auto iter2 = vec2.begin();
  EXPECT_EQ(*iter1, *iter2);
  EXPECT_EQ(vec1.size(), vec2.size());
}

TEST(array_test, end) {
  s21::array<int, 5> vec1 = {1, 2, 3, 4, 5};
  std::array<int, 5> vec2 = {1, 2, 3, 4, 5};
  auto iter1 = vec1.end();
  auto iter2 = vec2.end();
  EXPECT_EQ(*(iter1 - 1), *(iter2 - 1));
  EXPECT_EQ(vec1.size(), vec2.size());
}

TEST(array_test, size) {
  s21::array<int, 3> vec1;
  std::array<int, 3> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), 3);
  vec1 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.size(), vec2.size());
}
TEST(array_test, capacity) {
  s21::array<int, 3> vec1;
  std::array<int, 3> vec2;
  EXPECT_EQ(vec1.size(), vec2.size());

  vec1 = {1, 2, 3};
  vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), vec2.size());
}

TEST(array_test, swap) {
  s21::array<int, 3> vec1 = {1, 2, 3};
  s21::array<int, 3> vec1_1 = {3, 2, 1};
  vec1.swap(vec1_1);
  for (int i = 0, j = 3; i < 3; i++) {
    EXPECT_EQ(vec1_1[i], i + 1);
    EXPECT_EQ(vec1[i], j--);
  }
}

TEST(s21_array, front_back_test_1) {
  s21::array<int, 2> myarray{78, 16};
  std::array<int, 2> test_array{78, 16};
  ASSERT_EQ(myarray.front(), test_array.front());
  ASSERT_EQ(myarray.back(), test_array.back());
}

class TestArray {
 public:
  s21::array<int, 0> s21_array_empty;
  s21::array<int, 3> copy_array{234, 21, 11};
  s21::array<char, 0> copy_ar1;
  s21::array<double, 5> copy_array1{2.5, 3.4, 255.3, 1.2, 0.5};
  s21::array<double, 5> copy_array2{-5.3, 1.18, -4.3, 255.34, 1.23};

  std::array<int, 0> std_array_empty;
  std::array<int, 3> orig_array{234, 21, 11};
  std::array<char, 0> orig_ar1;
  std::array<double, 5> orig_array1{2.5, 3.4, 255.3, 1.2, 0.5};
  std::array<double, 5> orig_array2{-5.3, 1.18, -4.3, 255.34, 1.23};
};

TEST(Array, constructor_default) {
  TestArray tester;
  EXPECT_EQ(tester.s21_array_empty.size(), tester.std_array_empty.size());
  EXPECT_EQ(tester.s21_array_empty.empty(), tester.std_array_empty.empty());
}

TEST(Array, constructor_initializer) {
  TestArray tester;
  EXPECT_EQ(tester.copy_array1[1], tester.orig_array1[1]);
  EXPECT_EQ(tester.copy_array1.front(), tester.orig_array1.front());
  EXPECT_EQ(tester.copy_array1.back(), tester.orig_array1.back());
  EXPECT_EQ(tester.copy_array1.size(), tester.orig_array1.size());
  EXPECT_EQ(tester.copy_array1.empty(), tester.orig_array1.empty());
}

TEST(Array, constructor_copy_empty) {
  TestArray tester;
  s21::array<int, 0> s21_array_copy(tester.s21_array_empty);
  std::array<int, 0> std_array_copy(tester.std_array_empty);
  EXPECT_EQ(s21_array_copy.size(), std_array_copy.size());
  EXPECT_EQ(s21_array_copy.empty(), std_array_copy.empty());
}

TEST(Array, simple_test) {
  TestArray logger;
  for (int i{}; i < 3; i++)
    ASSERT_EQ(logger.orig_array.at(i), logger.copy_array.at(i));
  ASSERT_EQ(logger.orig_array.size(), logger.copy_array.size());
  ASSERT_EQ(logger.orig_array.max_size(), logger.copy_array.max_size());
  ASSERT_EQ(logger.orig_ar1.empty(), logger.copy_ar1.empty());
}
TEST(Array, swap_test) {
  TestArray logger;
  logger.orig_array1.swap(logger.orig_array2);
  logger.copy_array1.swap(logger.copy_array2);
  for (int i{}; i < 5; i++) {
    ASSERT_DOUBLE_EQ(logger.orig_array1[i], logger.copy_array1[i]);
    ASSERT_DOUBLE_EQ(logger.orig_array2[i], logger.copy_array2[i]);
  }
  ASSERT_EQ(logger.orig_array1.size(), logger.copy_array1.size());
  ASSERT_EQ(logger.orig_array2.max_size(), logger.copy_array2.max_size());
  ASSERT_EQ(logger.orig_array1.front(), logger.copy_array1.front());
  ASSERT_EQ(logger.orig_array2.front(), logger.copy_array2.front());
  ASSERT_EQ(logger.orig_array1.back(), logger.copy_array1.back());
  ASSERT_EQ(logger.orig_array2.back(), logger.copy_array2.back());
}

TEST(Array, copy_constructor_test) {
  std::array<int, 3> orig_array3{234, 21, 11};
  s21::array<int, 3> copy_array3{234, 21, 11};
  std::array<int, 3> orig_array4(orig_array3);
  s21::array<int, 3> copy_array4(copy_array3);
  for (int i{}; i < 3; i++) {
    ASSERT_EQ(orig_array3.at(i), copy_array3.at(i));
    ASSERT_EQ(orig_array4.at(i), copy_array4.at(i));
  }
  ASSERT_EQ(orig_array3.size(), copy_array3.size());
  ASSERT_EQ(orig_array3.max_size(), copy_array3.max_size());
  ASSERT_EQ(orig_array4.size(), copy_array4.size());
  ASSERT_EQ(orig_array4.max_size(), copy_array4.max_size());
  std::array<char, 0> orig_ar5;
  s21::array<char, 0> copy_ar5;
  std::array<char, 0> orig_ar6(orig_ar5);
  s21::array<char, 0> copy_ar6(copy_ar5);
  ASSERT_EQ(orig_ar5.empty(), copy_ar5.empty());
  ASSERT_EQ(orig_ar6.empty(), copy_ar6.empty());
}

TEST(Array, move_constructor_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::array<int, 5> copy_array1{234, 21, 11, 34, 999};
  std::array<int, 5> orig_array2(std::move(orig_array1));
  s21::array<int, 5> copy_array2(std::move(copy_array1));
  for (size_t i{}; i < copy_array2.size(); i++) {
    ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  ASSERT_EQ(orig_array2.size(), copy_array2.size());
  ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
  std::array<char, 0> orig_ar1;
  s21::array<char, 0> copy_ar1;
  ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(Array, move_operator_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::array<int, 5> copy_array1{234, 21, 11, 34, 999};
  std::array<int, 5> orig_array2{25};
  s21::array<int, 5> copy_array2{25};
  orig_array2 = std::move(orig_array1);
  copy_array2 = std::move(copy_array1);
  for (size_t i{}; i < copy_array2.size(); i++) {
    ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  ASSERT_EQ(orig_array2.size(), copy_array2.size());
  ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
  std::array<char, 0> orig_ar1;
  s21::array<char, 0> copy_ar1;
  ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(Array, iterator_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::array<int, 5> copy_array1{234, 21, 11, 34, 999};
  int *orig_beg = orig_array1.begin();
  int *copy_beg = copy_array1.begin();
  int *orig_end = orig_array1.end();
  int *copy_end = copy_array1.end();
  while (orig_beg < orig_end && copy_beg < copy_end) {
    ASSERT_EQ(*orig_beg++, *copy_beg++);
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  s21::array<char, 0> copy_ar1;
  ASSERT_TRUE(copy_ar1.begin() == copy_ar1.end());
  s21::array<double, 3> my_arr{2.3, 4.5555, 6.1234};
  double *d = my_arr.data();
  ASSERT_DOUBLE_EQ(my_arr[0], *d);
}

TEST(Array, fill_test) {
  std::array<size_t, 10> orig_array;
  s21::array<size_t, 10> my_arr;
  orig_array.fill(555);
  my_arr.fill(555);
  for (size_t i = 0; i < orig_array.size(); i++)
    ASSERT_EQ(orig_array[i], my_arr[i]);
  ASSERT_EQ(orig_array.size(), my_arr.size());
}