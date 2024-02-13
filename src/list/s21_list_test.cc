// 1
//  g++ -v -std=c++17  -lgtest s21_list_test.cc
//  CK_FORK=no leaks -atExit -- ./a.out
//  clang-format -i s21_list.h s21_list_test.cc
#include "s21_list.h"

#include <gtest/gtest.h>

#include <list>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(LIST, case1) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(LIST, case2) {
  s21::list<int> s21_list_int(5);
  s21::list<double> s21_list_double(5);
  s21::list<std::string> s21_list_string(5);

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_string.size(), 5U);
}

TEST(LIST, case3) {
  EXPECT_THROW(s21::list<int> s21_list_int(0), std::out_of_range);
  EXPECT_THROW(s21::list<double> s21_list_double(0), std::out_of_range);
  EXPECT_THROW(s21::list<std::string> s21_list_string(0), std::out_of_range);
}

TEST(LIST, case4) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_int.front(), 1);

  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_double.front(), 1.4);

  EXPECT_EQ(s21_list_string.size(), 4U);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(LIST, case5) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int(s21_list_ref_int);

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double(s21_list_ref_double);

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string(s21_list_ref_string);

  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case6) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int = s21_list_ref_int;

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double = s21_list_ref_double;

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string = s21_list_ref_string;

  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case7) {
  s21::list<int> s21_list_ref_int;
  s21::list<int> s21_list_res_int = s21_list_ref_int;

  s21::list<double> s21_list_ref_double;
  s21::list<double> s21_list_res_double = s21_list_ref_double;

  s21::list<std::string> s21_list_ref_string;
  s21::list<std::string> s21_list_res_string = s21_list_ref_string;

  EXPECT_EQ(s21_list_res_int.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 0U);
}

TEST(LIST, case8) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int = std::move(s21_list_ref_int);

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double = std::move(s21_list_ref_double);

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string = std::move(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case9) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int;
  s21_list_res_int = std::move(s21_list_ref_int);

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double;
  s21_list_res_double = std::move(s21_list_ref_double);

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string;
  s21_list_res_string = std::move(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case10) {
  s21::list<int> a = {43, 43, 43, 5};
  s21::list<int> b = {1};
  a = std::move(b);
  EXPECT_EQ(a.back(), 1);
}

TEST(LIST, case11) {
  size_t n = 1e4;
  s21::list<int> lst(n);
  EXPECT_EQ(lst.size(), n);
  EXPECT_TRUE(lst.max_size() != 0);
  lst.pop_back();
  lst.pop_front();
  EXPECT_EQ(lst.size(), (n - 2));  //?
  int back = lst.back();
  int front = lst.front();
  EXPECT_EQ(back, 0);
  EXPECT_EQ(front, 0);
}

TEST(LIST, case12) {
  s21::list<double> lst = {1.032, 2.320,    3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  EXPECT_EQ(lst.size(), 10U);
  double front = lst.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst.pop_front();
  double new_front = lst.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  lst.pop_back();
  double back = lst.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ((int)lst.size(), (int)8);
  EXPECT_EQ(lst.size(), 8U);  //??????????

  lst.clear();
  EXPECT_EQ(lst.size(), 0U);
}

TEST(LIST, case13) {
  s21::list<double> lst = {1.032, 2.32,     3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  s21::list<double> lst_cpy(lst);
  EXPECT_EQ(lst_cpy.size(), 10U);
  double front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst_cpy.pop_front();
  double new_front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  double back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 10.0);
  lst_cpy.pop_back();
  back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ(lst_cpy.size(), 8U);
}

TEST(LIST, case14) {
  s21::list<double> lst = {1.032, 2.32,     3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  s21::list<double> lst_cpy(std::move(lst));
  EXPECT_EQ(lst_cpy.size(), 10U);
  double front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst_cpy.pop_front();
  double new_front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  double back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 10.0);
  lst_cpy.pop_back();
  back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ(lst_cpy.size(), 8U);
  EXPECT_EQ(lst.size(), 0U);
}

TEST(LIST, case15) {
  std::list<int> orig_list = {};
  s21::list<int> lst = {};
  auto orig_itr_end = orig_list.end();
  auto itr_end = lst.end();
  EXPECT_EQ(*orig_itr_end, *itr_end);
}  //////////////////////????????????????????

TEST(LIST, case16) {
  std::list<int> orig_list;
  s21::list<int> lst;
  auto orig_itr = orig_list.end();
  auto itr = lst.end();
  EXPECT_EQ(*orig_itr, *itr);
}

TEST(LIST_PUSH_FRONT, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 5U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_FRONT, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 1U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_FRONT, case3) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.0};
  s21::list<std::string> s21_list_string{"1"};

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 2U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 2U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 2U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_BACK, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 5U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_PUSH_BACK, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 1U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_PUSH_BACK, case3) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.0};
  s21::list<std::string> s21_list_string{"1"};

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 2U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 2U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 2U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_POP_FRONT, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.pop_front();
  s21_list_double.pop_front();
  s21_list_string.pop_front();

  EXPECT_EQ(s21_list_int.size(), 3U);
  EXPECT_EQ(s21_list_int.front(), 4);

  EXPECT_EQ(s21_list_double.size(), 3U);
  EXPECT_EQ(s21_list_double.front(), 4.8);

  EXPECT_EQ(s21_list_string.size(), 3U);
  EXPECT_EQ(s21_list_string.front(), ",");
}

TEST(LIST_POP_FRONT, case2) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.0};
  s21::list<std::string> s21_list_string{"1"};

  s21_list_int.pop_front();
  s21_list_double.pop_front();
  s21_list_string.pop_front();

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(LIST_POP_FRONT, case3) {
  s21::list<int> lol = {1, 2, 10, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
  lol.pop_front();
  lol_orig.pop_front();
  auto itr_orig = lol_orig.begin();
  for (auto itr = lol.begin(); itr != lol.end(); itr++) {
    EXPECT_EQ(*itr, *itr_orig);
    itr_orig++;
  }
}

TEST(LIST_POP_BACK, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.pop_back();
  s21_list_double.pop_back();
  s21_list_string.pop_back();

  EXPECT_EQ(s21_list_int.size(), 3U);
  EXPECT_EQ(s21_list_int.back(), 8);

  EXPECT_EQ(s21_list_double.size(), 3U);
  EXPECT_EQ(s21_list_double.back(), 8.9);

  EXPECT_EQ(s21_list_string.size(), 3U);
  EXPECT_EQ(s21_list_string.back(), "world");
}

TEST(LIST_POP_BACK, case2) {
  s21::list<int> s21_list_int{1, 2};
  s21::list<double> s21_list_double{1.0, 2.0};
  s21::list<std::string> s21_list_string{"1", "2"};

  s21_list_int.pop_back();
  s21_list_double.pop_back();
  s21_list_string.pop_back();

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_string.size(), 1U);
}

TEST(LIST_FRONT, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(LIST_FRONT, case2) {
  s21::list<char> lol = {'l', 'o', 'l'};
  std::list<char> lol_orig = {'l', 'o', 'l'};
  EXPECT_EQ(lol.front(), lol_orig.front());
}

TEST(back, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.back(), 9);
  EXPECT_EQ(s21_list_double.back(), 9.1);
  EXPECT_EQ(s21_list_string.back(), "!");
}

TEST(swap, case1) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int{12, 13};

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double{11.0, 12.0, 13.0};

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string{"12", "13", "14", "15"};

  s21_list_ref_int.swap(s21_list_res_int);
  s21_list_ref_double.swap(s21_list_res_double);
  s21_list_ref_string.swap(s21_list_res_string);

  EXPECT_EQ(s21_list_ref_int.size(), 2U);
  EXPECT_EQ(s21_list_ref_int.front(), 12);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 3U);
  EXPECT_EQ(s21_list_ref_double.front(), 11.0);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 4U);
  EXPECT_EQ(s21_list_ref_string.front(), "12");
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(swap, case2) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int;

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double;

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string;

  s21_list_ref_int.swap(s21_list_res_int);
  s21_list_ref_double.swap(s21_list_res_double);
  s21_list_ref_string.swap(s21_list_res_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(sort, case1) {
  s21::list<int> s21_list_int{8, 1, 4, 9};
  s21::list<double> s21_list_double{9.1, 1.4, 4.8, 8.9};
  s21::list<std::string> s21_list_string{"hello", "there", "21", "school"};

  s21_list_int.sort();
  s21_list_double.sort();
  s21_list_string.sort();

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "21");
}

TEST(sort, case2) {
  s21::list<int> s21_list_int{8};
  s21::list<double> s21_list_double{9.1};
  s21::list<std::string> s21_list_string{"hello"};

  s21_list_int.sort();
  s21_list_double.sort();
  s21_list_string.sort();

  EXPECT_EQ(s21_list_int.front(), 8);
  EXPECT_EQ(s21_list_double.front(), 9.1);
  EXPECT_EQ(s21_list_string.front(), "hello");
}

TEST(merge, case1) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int{12, 13};

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double{11.0, 12.0, 13.0};

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string{"12", "13", "14", "15"};

  s21_list_res_int.merge(s21_list_ref_int);
  s21_list_res_double.merge(s21_list_ref_double);
  s21_list_res_string.merge(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 6U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 7U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 8U);
  EXPECT_EQ(s21_list_res_string.front(), "12");
}

TEST(merge, case2) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int;

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double;

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string;

  s21_list_res_int.merge(s21_list_ref_int);
  s21_list_res_double.merge(s21_list_ref_double);
  s21_list_res_string.merge(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(merge, case3) {
  s21::list<int> lol = {1, 2, 10, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
  s21::list<int> list_merge = {2, 5, 7, 9};
  std::list<int> list_merge_orig = {2, 5, 7, 9};
  lol.sort();
  lol_orig.sort();
  lol.merge(list_merge);
  lol_orig.merge(list_merge_orig);
  auto itr_orig = lol_orig.begin();
  for (auto itr = lol.begin(); itr != lol.end(); itr++) {
    EXPECT_EQ(*itr, *itr_orig);
    itr_orig++;
  }
}

TEST(reverse, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.reverse();
  s21_list_double.reverse();
  s21_list_string.reverse();

  EXPECT_EQ(s21_list_int.front(), 9);
  EXPECT_EQ(s21_list_double.front(), 9.1);
  EXPECT_EQ(s21_list_string.front(), "!");
}

TEST(reverse, case2) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.4};
  s21::list<std::string> s21_list_string{"Hello"};

  s21_list_int.reverse();
  s21_list_double.reverse();
  s21_list_string.reverse();

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(unique, case1) {
  s21::list<int> s21_list_int{1, 1, 4, 4, 8, 8, 8, 9, 9, 9, 9, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 1.4, 4.8, 8.9, 9.1,
                                    1.4, 4.8, 8.9, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",",     "Hello", ",",
                                         "world", ",",     "world", "!",
                                         "!",     "world", "!"};

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 10U);
  EXPECT_EQ(s21_list_string.size(), 10U);
}

TEST(unique, case2) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_string.size(), 4U);
}

TEST(unique, case3) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(size, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_string.size(), 4U);
}

TEST(size, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

// TEST(max_size, case1) {
//   s21::list<int> s21_list_int{1, 4, 8, 9};
//   std::list<int> std_list_int{1, 4, 8, 9};

//   s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
//   std::list<double> std_list_double{1.4, 4.8, 8.9, 9.1};

//   s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};
//   std::list<std::string> std_list_string{"Hello", ",", "world", "!"};

//   EXPECT_EQ(s21_list_int.max_size(), std_list_int.max_size());
//   EXPECT_EQ(s21_list_double.max_size(), std_list_double.max_size());
//   EXPECT_EQ(s21_list_string.max_size(), std_list_string.max_size());
// }

TEST(LIST_EMPTY, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.empty(), 0);
  EXPECT_EQ(s21_list_double.empty(), 0);
  EXPECT_EQ(s21_list_double.empty(), 0);
}

TEST(LIST_EMPTY, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.empty(), 1);
  EXPECT_EQ(s21_list_double.empty(), 1);
  EXPECT_EQ(s21_list_double.empty(), 1);
}

TEST(LIST_EMPTY, case3) {
  s21::list<int> lol;
  std::list<int> lol_orig;
  EXPECT_EQ(lol.front(), lol_orig.front());
}

TEST(LIST_EMPTY, case4) {
  s21::list<int> lol;
  std::list<int> lol_orig;
  EXPECT_EQ(lol.back(), lol_orig.back());
}

TEST(LIST_EMPTY, case5) {
  std::list<int> orig_list(5);
  s21::list<int> lst(5);
  auto orig_itr = orig_list.end();
  auto itr = lst.end();
  EXPECT_EQ(*orig_itr, *itr);
}

TEST(LIST_INSERT, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  it_int += 2;
  it_int = s21_list_int.insert(it_int, 13);
  EXPECT_EQ(s21_list_int.front(), 13);
  EXPECT_EQ(*(s21_list_int.begin() + 2), 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  it_double += 2;
  it_double = s21_list_double.insert(it_double, 21.0);
  EXPECT_EQ(s21_list_double.front(), 21.0);
  EXPECT_EQ(*(s21_list_double.begin() + 2), 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  it_string += 2;
  it_string = s21_list_string.insert(it_string, "HI");
  EXPECT_EQ(s21_list_string.front(), "HI");
  EXPECT_EQ(*(s21_list_string.begin() + 2), "HI");
}

TEST(LIST_INSERT, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  EXPECT_EQ(s21_list_int.front(), 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  EXPECT_EQ(s21_list_double.front(), 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  EXPECT_EQ(s21_list_string.front(), "HI");
}

TEST(LIST_INSERT, case3) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.0};
  s21::list<std::string> s21_list_string{"1"};

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  EXPECT_EQ(s21_list_int.front(), 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  EXPECT_EQ(s21_list_double.front(), 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  EXPECT_EQ(s21_list_string.front(), "HI");
}

TEST(LIST_INSERT, case4) {
  s21::list<int> lol;
  std::list<int> lol_orig;
  auto itr = lol.begin();
  auto itr_orig = lol_orig.begin();
  itr = lol.insert(itr, 21);
  itr_orig = lol_orig.insert(itr_orig, 21);
  EXPECT_EQ(*itr, *itr_orig);

  s21::list<int> lol1 = {1, 2, 3, 4, 6, 43};
  std::list<int> lol_orig1 = {1, 2, 3, 4, 6, 43};
  auto itr1 = lol1.begin();
  auto itr_orig1 = lol_orig1.begin();
  itr1 = lol1.insert(itr1, 21);
  itr_orig1 = lol_orig1.insert(itr_orig1, 21);
  auto end1 = lol1.end();
  auto end_orig1 = lol_orig1.end();
  while (itr1 != end1 && itr_orig1 != end_orig1) {
    EXPECT_EQ(*itr1, *itr_orig1);
    itr1++;
    itr_orig1++;
  }

  s21::list<int> lol2 = {1, 2, 3, 4, 6, 44};
  std::list<int> lol_orig2 = {1, 2, 3, 4, 6, 44};
  auto itr2 = lol2.end();
  auto itr_orig2 = lol_orig2.end();
  itr2 = lol2.insert(itr2, 21);
  itr_orig2 = lol_orig2.insert(itr_orig2, 21);
  while (itr2 != lol2.begin() && itr_orig2 != lol_orig2.begin()) {
    EXPECT_EQ(*itr2, *itr_orig2);
    itr2--;
    itr_orig2--;
  }
}

TEST(LIST_SPLICE, case1) {
  s21::list<int> s21_list_ref_int{3, 5};
  s21::list<int> s21_list_res_int{1, 4, 8, 9};

  s21::list<double> s21_list_ref_double{5.6, 7.1};
  s21::list<double> s21_list_res_double{1.4, 4.8, 8.9, 9.1};

  s21::list<std::string> s21_list_ref_string{"Hi"};
  s21::list<std::string> s21_list_res_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 3);
  EXPECT_EQ(*(s21_list_res_int.begin() + 1), 5);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 5.6);
  EXPECT_EQ(*(s21_list_res_double.begin() + 1), 7.1);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hi");
}

TEST(LIST_SPLICE, case2) {
  s21::list<int> s21_list_ref_int;
  s21::list<int> s21_list_res_int{1, 4, 8, 9};

  s21::list<double> s21_list_ref_double;
  s21::list<double> s21_list_res_double{1.4, 4.8, 8.9, 9.1};

  s21::list<std::string> s21_list_ref_string;
  s21::list<std::string> s21_list_res_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 1);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 1.4);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hello");
}

TEST(LIST_SPLICE, case3) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int;

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double;

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string;

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 1);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 1.4);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hello");
}

TEST(LIST_EMPLACE_BACK, case1) {
  s21::list<int> our = {1, 2, 7, 8, 9};
  our.emplace_back(4, 5, 6);
  EXPECT_EQ(our.back(), 6);
}

TEST(LIST_EMPLACE_BACK, case2) {
  s21::list<int> our;
  our.emplace_back(4, 5, 6);
  EXPECT_EQ(our.back(), 6);
  EXPECT_EQ(our.front(), 4);
}

TEST(LIST_EMPLACE_FRONT, case1) {
  s21::list<int> our{1, 2, 7, 8, 9};
  our.emplace_front(4, 5, 6);
  EXPECT_EQ(our.front(), 6);
}

TEST(LIST_EMPLACE_FRONT, case2) {
  s21::list<int> our;
  our.emplace_front(4, 5, 6);
  EXPECT_EQ(our.front(), 6);
  EXPECT_EQ(our.back(), 4);
}
TEST(LIST_ITERATOR, case1) {
  s21::list<int> lol = {1, 2, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 3, 4, 6, 43};
  unsigned int n = lol.size();
  unsigned int n_orig = lol_orig.size();
  EXPECT_EQ(n, n_orig);
  auto itr = lol.begin();
  auto itr_orig = lol_orig.begin();
  auto end = lol.end();
  auto end_orig = lol_orig.end();
  while (itr != end && itr_orig != end_orig) {
    EXPECT_EQ(*itr, *itr_orig);
    itr++;
    itr_orig++;
  }
}

TEST(LIST_ITERATOR, case2) {
  s21::list<int> lol = {1, 2, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 3, 4, 6, 43};
  unsigned int n = lol.size();
  unsigned int n_orig = lol_orig.size();
  EXPECT_EQ(n, n_orig);
  auto itr = lol.end();
  auto itr_orig = lol_orig.end();
  auto end = lol.begin();
  auto end_orig = lol_orig.begin();
  while (true) {
    if (itr == end && itr_orig == end_orig) {
      break;
    }
    EXPECT_EQ(*itr, *itr_orig);
    itr--;
    itr_orig--;
  }
}

TEST(LIST_ITERATOR, case3) {
  s21::list<int> lol = {1, 2, 3, 4, 6, 43};
  auto itr = lol.begin() + 1;
  EXPECT_EQ(*itr, 2);
}

TEST(LIST_ITERATOR, case4) {
  s21::list<int> lol = {1, 2, 3, 4, 6, 43};
  auto itr = lol.end() - 1;
  EXPECT_EQ(*itr, 43);
}

TEST(LIST_ITERATOR, case5) {
  s21::list<int> lol = {1, 2, 3, 4, 6, 43};
  auto itr = lol.end();
  itr -= 1;
  EXPECT_EQ(*itr, 43);
}

TEST(List, Constructor_Default) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, Constructor_Initializer_list) {
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  EXPECT_EQ(std_list.front(), s21_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}
TEST(List, Constructor_Parameterized) {
  s21::list<double> s21_list(5);
  std::list<double> std_list(5);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}
TEST(List, Constructor_Copy) {
  s21::list<char> s21_list_1 = {'a', 'b', 'c', 'd'};
  std::list<char> std_list_1 = {'a', 'b', 'c', 'd'};
  s21::list<char> s21_list_2 = s21_list_1;
  std::list<char> std_list_2 = std_list_1;

  EXPECT_EQ(s21_list_1.size(), s21_list_2.size());
  EXPECT_EQ(std_list_1.size(), std_list_2.size());
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}
TEST(List, Constructor_Move) {
  s21::list<char> s21_list_1 = {'a', 'b', 'c', 'd'};
  std::list<char> std_list_1 = {'a', 'b', 'c', 'd'};
  s21::list<char> s21_list_2 = std::move(s21_list_1);
  std::list<char> std_list_2 = std::move(std_list_1);

  EXPECT_EQ(s21_list_2.size(), std_list_2.size());
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
  auto it1 = s21_list_2.begin();
  auto it2 = std_list_2.begin();
  while (it1 != s21_list_2.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}

TEST(List, Modifier_Insert) {
  s21::list<int> s21_list_1 = {'a', 'c', 'd'};
  s21::list<int> s21_list_2 = {'a', 'b', 'c', 'd'};

  auto it = s21_list_1.begin();
  ++it;
  s21_list_1.insert(it, 'b');
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list_1.size(), s21_list_2.size());
}

TEST(List, Modifier_Erase) {
  s21::list<int> s21_list_1 = {'a', 'c', 'd'};
  s21::list<int> s21_list_2 = {'a', 'b', 'c', 'd'};

  auto it = s21_list_2.begin();
  ++it;
  s21_list_2.erase(it);
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  while (it1 != s21_list_1.end() - 1) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list_1.size(), s21_list_2.size());
}

TEST(List, Modifier_Push) {
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  s21_list.push_back(5);
  s21_list.push_front(0);
  std_list.push_back(5);
  std_list.push_front(0);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
  auto it1 = s21_list.begin();
  auto it2 = std_list.begin();
  while (it1 != s21_list.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}

TEST(List, Modifier_Pop) {
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  s21_list.pop_back();
  s21_list.pop_front();
  std_list.pop_back();
  std_list.pop_front();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
  auto it1 = s21_list.begin();
  auto it2 = std_list.begin();
  while (it2 != std_list.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}

TEST(List, Modifier_Swap) {
  s21::list<char> s21_list_1 = {'a', 'b', 'o', 'b', 'a'};
  s21::list<char> s21_list_2 = {'s', 'h', 'l', 'e', 'p', 'p', 'a'};
  s21::list<char> s21_list_3 = {'a', 'b', 'o', 'b', 'a'};
  s21::list<char> s21_list_4 = {'s', 'h', 'l', 'e', 'p', 'p', 'a'};
  s21_list_1.swap(s21_list_2);
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  auto it3 = s21_list_3.begin();
  auto it4 = s21_list_4.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it4);
    ++it1, ++it4;
  }
  while (it2 != s21_list_2.end()) {
    EXPECT_EQ(*it2, *it3);
    ++it2, ++it3;
  }
  EXPECT_EQ(s21_list_1.size(), s21_list_4.size());
  EXPECT_EQ(s21_list_2.size(), s21_list_3.size());
}
TEST(List, Modifier_Merge) {
  s21::list<int> s21_list_1 = {1, 3, 7};
  s21::list<int> s21_list_2 = {-1, 0, 5, 8};
  std::list<int> std_list_1 = {1, 3, 7};
  std::list<int> std_list_2 = {-1, 0, 5, 8};
  s21_list_1.merge(s21_list_2);
  std_list_1.merge(std_list_2);
  auto it1 = s21_list_1.begin();
  auto it2 = std_list_1.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
}
TEST(List, Modifier_Reverse) {
  s21::list<int> s21_list_1 = {1, 2, 3, 4};
  s21::list<int> s21_list_2 = {4, 3, 2, 1};
  s21_list_1.reverse();
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list_1.size(), s21_list_2.size());
}
TEST(List, Modifier_Unique) {
  s21::list<int> s21_list{1, -1, -23, 4, 1, 5, 6, 4, -1, -1};
  std::list<int> std_list{1, -1, -23, 4, 1, 5, 6, 4, -1, -1};
  s21_list.unique();
  std_list.unique();
  auto it1 = s21_list.begin();
  auto it2 = std_list.begin();
  while (it1 != s21_list.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Modifier_Sort) {
  s21::list<int> s21_list{1, -1, -23, 4, 1, 5, 6, 4, -1, -1};
  std::list<int> std_list{1, -1, -23, 4, 1, 5, 6, 4, -1, -1};
  s21_list.sort();
  std_list.sort();
  auto it1 = s21_list.begin();
  auto it2 = std_list.begin();
  while (it2 != std_list.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}
TEST(s21_list_constructor, default_constructor) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  ASSERT_EQ(s21list.empty(), stdlist.empty());
  ASSERT_EQ(s21list.size(), stdlist.size());
}

TEST(s21_list_constructor, size_constructor) {
  s21::list<int> s21list(5);
  std::list<int> stdlist(5);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, init_constructor) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}
TEST(s21_list_constructor, init_char_constructor) {
  s21::list<char> s21list{'a', 'b', 'c'};
  std::list<char> stdlist{'a', 'b', 'c'};
  s21::list<char>::iterator s21it = s21list.begin();
  std::list<char>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, init_string_constructor) {
  s21::list<std::string> s21list{"just", "string", "constructor"};
  std::list<std::string> stdlist{"just", "string", "constructor"};
  s21::list<std::string>::iterator s21it = s21list.begin();
  std::list<std::string>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, copy_constructor) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int> s21list2(s21list);
  std::list<int> stdlist2(stdlist);
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}
TEST(s21_list_constructor, move_constructor) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int> s21list2(std::move(s21list));
  std::list<int> stdlist2(std::move(stdlist));
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, move_operator_constructor) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int> s21list2 = std::move(s21list);
  std::list<int> stdlist2 = std::move(stdlist);
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}
TEST(s21_list_front_back, front_back) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  ASSERT_EQ(s21list.front(), stdlist.front());
  ASSERT_EQ(s21list.back(), stdlist.back());
}

TEST(s21_list_empty_clear, empty_clear) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  s21list.clear();
  stdlist.clear();
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}
TEST(s21_list_push_pop, push) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_push_pop, pop) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21list.pop_back();
  stdlist.pop_back();
  ASSERT_EQ(s21list.front(), stdlist.front());
  ASSERT_EQ(s21list.back(), stdlist.back());
  s21list.pop_front();
  stdlist.pop_front();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  s21list.clear();
  stdlist.clear();
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(s21_list_function, insert) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.insert(s21it, 77);
  stdlist.insert(stdit, 77);
  s21it = s21list.end();
  stdit = stdlist.end();
  s21list.insert(s21it, 66);
  stdlist.insert(stdit, 66);
  ASSERT_EQ(s21list.front(), stdlist.front());
  ++s21it;
  ++stdit;
  s21list.insert(s21it, 1111);
  stdlist.insert(stdit, 1111);
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, erase) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.erase(s21it);
  stdlist.erase(stdit);
  ASSERT_EQ(s21list.front(), stdlist.front());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ++s21it;
  ++stdit;
  s21list.erase(s21it);
  stdlist.erase(stdit);
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, swap) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.swap(s21list2);
  stdlist.swap(stdlist2);
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, merge) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  stdlist.sort();
  s21list.sort();
  s21list.merge(s21list2);
  stdlist.merge(stdlist2);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(s21_list_function, splice) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.splice(s21it, s21list2);
  stdlist.splice(stdit, stdlist2);
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(s21_list_function, reverse) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  s21list.reverse();
  stdlist.reverse();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, unique) {
  s21::list<int> s21list{1, 1, 1, 1, 222, 222, 2, 33, 3, 3};
  std::list<int> stdlist{1, 1, 1, 1, 222, 222, 2, 33, 3, 3};
  s21list.unique();
  stdlist.unique();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_sort, sort) {
  s21::list<double> s21lone{7.19};
  s21lone.sort();
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  s21list.sort();
  stdlist.sort();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_iterator, iterator) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  s21::list<int>::iterator begin = s21list.begin();
  s21::list<int>::iterator begin1 = begin;
  ASSERT_TRUE(begin == begin1);
  ASSERT_FALSE(begin != begin1);
}

TEST(s21_bonus, emplace) {
  s21::list<int> s21list{6, 7, 9};
  s21::list<int> s21res_list{6, 7, 1, 2, 8, 9};
  s21::list<int>::iterator s21it = s21list.begin();
  ++s21it;
  ++s21it;
  s21list.emplace(s21it, 1, 2, 8);
  s21::list<int>::iterator it_i = s21list.begin();
  s21::list<int>::iterator it_j = s21res_list.begin();
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}

TEST(s21_bonus, emplace_front) {
  s21::list<int> s21list{6, 7, 9};
  s21::list<int> s21res_list{8, 2, 1, 6, 7, 9};
  s21list.emplace_front(1, 2, 8);
  auto it_i = s21list.begin();
  s21::list<int>::iterator it_j = s21res_list.begin();
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}

TEST(s21_bonus, emplace_back) {
  s21::list<int> s21list{6, 7, 9};
  s21::list<int> s21res_list{6, 7, 9, 1, 2, 8};
  s21list.emplace_back(1, 2, 8);
  s21::list<int>::iterator it_i = s21list.begin();
  s21::list<int>::iterator it_j = s21res_list.begin();
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}

TEST(list, push_back_and_iterator) {
  s21::list<int> one;
  one.push_back(111);
  one.push_back(222);
  one.push_back(444);
  auto iter = one.begin();
  EXPECT_EQ(111, *iter);
  ++iter;
  EXPECT_EQ(222, *iter);
  ++iter;
  EXPECT_EQ(444, *iter);
}

TEST(list, pop_back_and_empty) {
  s21::list<int> one;
  EXPECT_EQ((int)one.size(), (int)0);
  EXPECT_EQ(true, one.empty());
  one.push_back(111);
  one.push_back(555);
  EXPECT_EQ((int)one.size(), (int)2);
  EXPECT_EQ(false, one.empty());
  one.pop_back();
  one.pop_back();
  EXPECT_EQ((int)one.size(), (int)0);
  EXPECT_EQ(true, one.empty());
}

TEST(list, n_constructor) {
  s21::list<int> one(20);
  EXPECT_EQ((int)one.size(), (int)20);
}

TEST(list, front_and_back) {
  s21::list<int> one{11, 22, 33, 44, 55, 66, 77};
  EXPECT_EQ(11, one.front());
  EXPECT_EQ(77, one.back());
}

TEST(list, push_front_and_pop_front) {
  s21::list<int> one;
  EXPECT_EQ((int)one.size(), (int)0);
  EXPECT_EQ(true, one.empty());
  one.push_front(111);
  one.push_front(555);
  EXPECT_EQ((int)one.size(), (int)2);
  EXPECT_EQ(555, *one.begin());
  one.pop_front();
  EXPECT_EQ((int)one.size(), (int)1);
  EXPECT_EQ(111, *one.begin());
  one.pop_front();
  EXPECT_EQ(true, one.empty());
}

TEST(list, initializer_list) {
  s21::list<int> one{111, 222, 444};
  auto iter = one.begin();
  EXPECT_EQ(111, *iter);
  ++iter;
  EXPECT_EQ(222, *iter);
  ++iter;
  EXPECT_EQ(444, *iter);
}

TEST(list, copy_constructor) {
  s21::list<int> zero{111, 222, 444};
  s21::list<int> one(zero);
  auto iter = one.begin();
  EXPECT_EQ(111, *iter);
  ++iter;
  EXPECT_EQ(222, *iter);
  ++iter;
  EXPECT_EQ(444, *iter);
}

TEST(list, erase) {
  s21::list<std::string> alpha{"one", "two", "three"};
  alpha.erase(alpha.begin());
  EXPECT_EQ("two", *alpha.begin());
  s21::list<std::string> beta{"one", "oneone", "oneoneone"};
  auto iter = beta.begin();
  ++iter;
  beta.erase(iter);
  iter = beta.begin();
  EXPECT_EQ("one", *iter);
  ++iter;
  EXPECT_EQ("oneoneone", *iter);
}

// TEST(list, max_size) {
//   s21::list<std::string> s21_list_obj;
//   std::list<std::string> std_list_obj;
//   EXPECT_EQ(s21_list_obj.max_size(), std_list_obj.max_size());
//   s21::list<char> s21_list_obj_2;
//   std::list<char> std_list_obj_2;
//   EXPECT_EQ(s21_list_obj_2.max_size(), std_list_obj_2.max_size());
// }

TEST(list, insert) {
  s21::list<std::string> alpha{"one", "two", "three"};
  alpha.insert(alpha.begin(), "zero");
  EXPECT_EQ("zero", *alpha.begin());
  auto iter = alpha.insert(alpha.end(), "four");
  EXPECT_EQ("four", *iter);
  ++iter;
  EXPECT_EQ(true, iter == alpha.end());
  iter = alpha.begin();
  ++iter;
  iter = alpha.insert(iter, "zeroPointFive");
  EXPECT_EQ("zeroPointFive", *iter);
}

TEST(list, move_constructor) {
  s21::list<int> zero{111, 222, 444};
  s21::list<int> one(std::move(zero));
  auto iter = one.begin();
  EXPECT_EQ(111, *iter);
  ++iter;
  EXPECT_EQ(222, *iter);
  ++iter;
  EXPECT_EQ(444, *iter);
  EXPECT_EQ(true, zero.empty());
}

TEST(list, reverse) {
  s21::list<int> zero{111, 222, 444};
  zero.reverse();
  auto iter = zero.begin();
  EXPECT_EQ(444, *iter);
  ++iter;
  EXPECT_EQ(222, *iter);
  ++iter;
  EXPECT_EQ(111, *iter);
}

TEST(list, unique) {
  s21::list<int> zero{111, 111, 111, 222, 222, 222, 444, 444, 444};
  zero.unique();
  auto iter = zero.begin();
  EXPECT_EQ(111, *iter);
  ++iter;
  EXPECT_EQ(222, *iter);
  ++iter;
  EXPECT_EQ(444, *iter);
  ++iter;
  EXPECT_EQ(iter, zero.end());

  s21::list<int> one{111, 222, 444};
  one.unique();
  iter = one.begin();
  EXPECT_EQ(111, *iter);
  ++iter;
  EXPECT_EQ(222, *iter);
  ++iter;
  EXPECT_EQ(444, *iter);

  s21::list<int> two;
  EXPECT_NO_THROW(two.unique());
}

TEST(list, splice) {
  s21::list<int> zero{111, 123, 444};
  s21::list<int> one;
  one.splice(one.begin(), zero);
  EXPECT_EQ(true, zero.empty());
  auto iter = one.begin();
  EXPECT_EQ(111, *iter);
  ++iter;
  EXPECT_EQ(123, *iter);
  ++iter;
  EXPECT_EQ(444, *iter);
  EXPECT_EQ((int)one.size(), (int)3);

  s21::list<int> two{2, 3, 4};
  s21::list<int> three{1, 5, 6};
  three.splice(++three.begin(), two);
  iter = three.begin();
  for (int i = 1; i < 7; ++i, ++iter) {
    EXPECT_EQ(i, *iter);
  }
  EXPECT_EQ((int)two.size(), (int)0);
}

TEST(list, assignment_operator) {
  s21::list<int> one{111, 123, 444};
  s21::list<int> two;
  two = std::move(one);
  EXPECT_EQ(true, one.empty());
  auto iter = two.begin();
  EXPECT_EQ(111, *iter);
  ++iter;
  EXPECT_EQ(123, *iter);
  ++iter;
  EXPECT_EQ(444, *iter);
  // two = std::move(two);
  // EXPECT_EQ(444, *iter);
}

TEST(list, sort) {
  s21::list<int> one{222, 33, 111, 444, 333, 3213, 555};
  one.sort();
  auto iter = one.begin();
  EXPECT_EQ(33, *iter);
  --iter;
  --iter;
  EXPECT_EQ(3213, *iter);
  ++iter;
  ++iter;
  ++iter;
  EXPECT_EQ(111, *iter);

  s21::list<int> two{4, 0, 3, 2, 1, 7, 6, 5};
  two.sort();
  iter = two.begin();
  for (size_t i = 0; i < two.size(); ++i) {
    EXPECT_EQ((int)i, (int)*iter);
    ++iter;
  }
  ++iter;
  EXPECT_EQ(0, *iter);
  ++iter;
  EXPECT_EQ(1, *iter);
  iter = two.end();
  for (int i = two.size() - 1; i >= 0; --i) {
    --iter;
    EXPECT_EQ(i, *iter);
  }
}

TEST(list, merge) {
  s21::list<int> one{4, 0, 3, 2};
  s21::list<int> two{1, 7, 6, 5};
  one.merge(two);
  auto iter = two.begin();
  for (size_t i = 0; i < two.size(); ++i) {
    EXPECT_EQ((int)i, (int)*iter);
    ++iter;
  }
  EXPECT_EQ(true, two.empty());
}

TEST(ListTest, DefaultConstructor) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ((int)my_list.size(), (int)0);
}
TEST(ListTest, Front) {
  s21::list<int> my_list{99, 2, 3, 4, 5};
  std::list<int> std_list{99, 2, 3, 4, 5};
  EXPECT_EQ(my_list.front(), std_list.front());
}
TEST(ListTest, Back) {
  s21::list<int> my_list{1, 2, 3, 4, 99};
  std::list<int> std_list{1, 2, 3, 4, 99};
  EXPECT_EQ(my_list.back(), std_list.back());
}
TEST(ListTest, Empty) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.empty(), std_list.empty());
  my_list.push_back(10);
  std_list.push_back(10);
  EXPECT_EQ(my_list.empty(), std_list.empty());
}
TEST(ListTest, Size) {
  s21::list<int> my_list{1, 2, 3, 4, 5, 6, 7, 8};
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, SizeEmpty) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.size(), std_list.size());
}
TEST(ListTest, begin_1) {
  s21::list<int> my_list1{500, 15000, 30000};

  std::list<int> std_list2{500, 15000, 30000};
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}
TEST(ListTest, begin_2) {
  s21::list<int> my_list1(4);

  std::list<int> std_list2(4);
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}
TEST(ListTest, begin_3_throw) {
  s21::list<int> my_list1;
  std::list<int> std_list2;

  EXPECT_EQ(*my_list1.begin(), 0);
}
