#include "s21_map.h"

#include <gtest/gtest.h>

#include <map>

bool compare(std::map<int, int> &m, s21::map<int, int> s) {
  bool res = true;
  auto std_itr = m.begin();
  auto itr = s.begin();
  for (; std_itr != m.end() && res; ++std_itr, ++itr) {
    if ((*itr).first != (*std_itr).first) {
      res = false;
    }
  }
  return res;
}

TEST(map_erase_suite, erase_no_child) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  a.insert(1, 0);
  a.insert(2, 0);
  a.insert(3, 0);

  auto std_itr_1 = std_a.insert({1, 0}).first;
  auto std_itr_2 = std_a.insert({2, 0}).first;
  auto std_itr_3 = std_a.insert({3, 0}).first;

  // -----------------------------------------
  a.erase(a.find({1, 0}));
  std_a.erase(std_itr_1);
  EXPECT_EQ(compare(std_a, a), true);

  // -----------------------------------------

  a.erase(a.find({3, 0}));
  std_a.erase(std_itr_3);
  EXPECT_EQ(compare(std_a, a), true);

  // -----------------------------------------
  a.erase(a.find({2, 0}));
  std_a.erase(std_itr_2);

  EXPECT_EQ(a.empty(), std_a.empty());
}

TEST(map_erase_suite, erase_one_child) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  std_a.insert({5, 0});
  std_a.insert({3, 0});
  std_a.insert({7, 0});
  std_a.insert({1, 0});
  std_a.insert({8, 0});

  a.insert(5, 0);
  a.insert(3, 0);
  a.insert(7, 0);
  a.insert(1, 0);
  a.insert(8, 0);

  a.erase(a.find({3, 0}));
  std_a.erase(std_a.find(3));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({7, 0}));
  std_a.erase(std_a.find(7));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({1, 0}));
  std_a.erase(std_a.find(1));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({5, 0}));
  std_a.erase(std_a.find(5));
  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_erase_suite, erase_two_child) {
  std::map<int, int> std_a;
  s21::map<int, int> a;
  std_a.insert({5, 0});
  std_a.insert({3, 0});
  std_a.insert({7, 0});
  std_a.insert({1, 0});
  std_a.insert({2, 0});
  std_a.insert({8, 0});
  std_a.insert({6, 0});

  a.insert(5, 0);
  a.insert(3, 0);
  a.insert(7, 0);
  a.insert(1, 0);
  a.insert(2, 0);
  a.insert(6, 0);
  a.insert(8, 0);

  a.erase(a.find({3, 0}));
  std_a.erase(std_a.find(3));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({7, 0}));
  std_a.erase(std_a.find(7));
  EXPECT_EQ(compare(std_a, a), true);

  a.erase(a.find({5, 0}));
  std_a.erase(std_a.find(5));
  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_constructor_suite, default_constructor) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());
}

TEST(map_constructor_suite, copy_constructor) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  std_a.insert({1, 1});
  std_a.insert({3, 2});
  std_a.insert({4, 2});

  a.insert(1, 1);
  a.insert(3, 2);
  a.insert(4, 2);

  std::map<int, int> std_b(std_a);
  s21::map<int, int> b(a);

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());
  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_constructor_suite, initializer_constructor) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};

  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());

  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_constructor_suite, move_constructor) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};

  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  std::map<int, int> std_b(std::move(std_a));
  s21::map<int, int> b(std::move(a));

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());

  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_constructor_suite, move_operator) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};

  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  std::map<int, int> std_b = std::move(std_a);
  s21::map<int, int> b = std::move(a);

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());

  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_iterator_suite, begin) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};
  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  EXPECT_EQ((*a.begin()).first, (*std_a.begin()).first);
  EXPECT_EQ((*a.begin()).second, (*std_a.begin()).second);
}

TEST(map_iterator_suite, end) {
  std::map<int, int> std_a = {{1, 0}, {2, 0}, {3, 0}};
  s21::map<int, int> a = {{1, 0}, {2, 0}, {3, 0}};

  EXPECT_EQ((*a.end()).first, (*std_a.end()).first);
  EXPECT_EQ((*a.end()).second, (*std_a.end()).second);
}

TEST(map_constructor_suite, initializer_constructor_2) {
  std::map<int, int> std_a = {};

  s21::map<int, int> a = {};

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());

  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_constructor_suite, move_constructor_2) {
  std::map<int, int> std_a;

  s21::map<int, int> a;

  std_a.insert({1, 1});
  std_a.insert({2, 0});
  std_a.insert({3, 0});
  std_a.insert({4, 10});
  std_a.insert({12, 4});
  std_a.insert({10, 0});
  std_a.insert({1, 8});
  std_a.insert({21, 1});
  std_a.insert({12, 9});
  std_a.insert({100, 9});

  a.insert({1, 1});
  a.insert({2, 0});
  a.insert({3, 0});
  a.insert({4, 10});
  a.insert({12, 4});
  a.insert({10, 0});
  a.insert({1, 8});
  a.insert({21, 1});
  a.insert({12, 9});
  a.insert({100, 9});

  std::map<int, int> std_b(std::move(std_a));
  s21::map<int, int> b(std::move(a));

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());

  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_constructor_suite, move_operator_2) {
  std::map<int, int> std_a = {};

  s21::map<int, int> a = {};

  std::map<int, int> std_b = std::move(std_a);
  s21::map<int, int> b = std::move(a);

  EXPECT_EQ(b.empty(), std_b.empty());
  EXPECT_EQ(b.size(), std_b.size());

  EXPECT_EQ(compare(std_b, b), true);
}

TEST(map_modifiers_suite, clear_1) {
  std::map<int, int> std_a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};

  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};

  std_a.clear();
  a.clear();

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());
}

TEST(map_modifiers_suite, clear_2) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  std_a.clear();
  a.clear();

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());
}

TEST(map_modifiers_suite, insert) {
  std::map<int, int> std_a;
  s21::map<int, int> a;

  std_a.insert({1, 1});
  std_a.insert({2, 0});
  std_a.insert({3, 0});
  std_a.insert({4, 10});
  std_a.insert({12, 4});
  std_a.insert({10, 0});
  std_a.insert({1, 8});
  std_a.insert({21, 1});
  std_a.insert({12, 9});
  std_a.insert({100, 9});

  a.insert({1, 1});
  a.insert({2, 0});
  a.insert({3, 0});
  a.insert({4, 10});
  a.insert({12, 4});
  a.insert({10, 0});
  a.insert({1, 8});
  a.insert({21, 1});
  a.insert({12, 9});
  a.insert({100, 9});

  EXPECT_EQ(compare(std_a, a), true);
}

TEST(map_modifiers_suite, swap) {
  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};

  s21::map<int, int> b = {{11, 1}, {12, 0}, {13, 0}, {14, 0}, {15, 5}};

  s21::map<int, int> b_swap = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};

  s21::map<int, int> a_swap = {{11, 1}, {12, 0}, {13, 0}, {14, 0}, {15, 5}};

  a.swap(b);
  auto a_itr = a.begin();
  auto a_swap_itr = a_swap.begin();
  for (; a_itr != a.end(); ++a_itr, ++a_swap_itr) {
    EXPECT_EQ(*a_itr, *a_swap_itr);
  }

  auto b_itr = b.begin();
  auto b_swap_itr = b_swap.begin();
  for (; b_itr != b.end(); ++b_itr, ++b_swap_itr) {
    EXPECT_EQ(*b_itr, *b_swap_itr);
  }
}

TEST(map_modifiers_suite, merge) {
  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};
  s21::map<int, int> b = {{1, 1},  {2, 0},  {3, 0},  {4, 0},  {5, 5},
                          {11, 1}, {12, 0}, {13, 0}, {14, 0}, {15, 5}};

  s21::map<int, int> result = {{1, 1},  {2, 0},  {3, 0},  {4, 0},  {5, 5},
                               {11, 1}, {12, 0}, {13, 0}, {14, 0}, {15, 5}};

  a.merge(b);
  auto a_itr = a.begin();
  auto result_itr = result.begin();
  for (; a_itr != a.end(); ++a_itr, ++result_itr) {
    EXPECT_EQ(*a_itr, *result_itr);
  }
}

TEST(map_modifiers_suite, merge_empty) {
  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};
  s21::map<int, int> b;
  s21::map<int, int> result = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};

  a.merge(b);
  auto a_itr = a.begin();
  auto result_itr = result.begin();
  for (; a_itr != a.end(); ++a_itr, ++result_itr) {
    EXPECT_EQ(*a_itr, *result_itr);
  }
}

TEST(map_modifiers_suite, merge_both_empty) {
  s21::map<int, int> a;
  s21::map<int, int> b;
  s21::map<int, int> result;

  a.merge(b);
  auto a_itr = a.begin();
  auto result_itr = result.begin();
  for (; a_itr != a.end(); ++a_itr, ++result_itr) {
    EXPECT_EQ(*a_itr, *result_itr);
  }
}

TEST(map_lookup_suite, contains) {
  s21::map<int, int> a = {{1, 1}, {2, 0}, {3, 0}, {4, 0}, {5, 5}};

  EXPECT_TRUE(a.contains({1, 1}));
  EXPECT_TRUE(a.contains({2, 0}));
  EXPECT_TRUE(a.contains({3, 0}));
  EXPECT_TRUE(a.contains({4, 0}));
  EXPECT_TRUE(a.contains({5, 5}));

  EXPECT_FALSE(a.contains({8, 8}));
  EXPECT_FALSE(a.contains({6, 7}));
  EXPECT_FALSE(a.contains({123, 33}));
}

TEST(map_element_access, braces_and_at) {
  s21::map<int, int> a;
  std::map<int, int> std_a;

  std_a.insert({1, 1});
  std_a.insert({2, 34});
  std_a.insert({3, 234});

  a.insert({1, 1});
  a.insert({2, 34});
  a.insert({3, 234});

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());

  auto std_itr = std_a.begin();
  auto itr = a.begin();

  for (int i = 1; std_itr != std_a.end(); ++std_itr, ++itr, ++i) {
    EXPECT_EQ(a.at(i), std_a.at(i));
    EXPECT_EQ(a[i], std_a[i]);
    EXPECT_EQ((*itr).first, (*std_itr).first);
    EXPECT_EQ((*itr).second, (*std_itr).second);
  }
}

TEST(map_modifiers_insert, insert_or_assign) {
  s21::map<int, int> a;
  std::map<int, int> std_a;

  a.insert_or_assign(1, 1);
  a.insert_or_assign(2, 1);
  a.insert_or_assign(1, 11);
  a.insert_or_assign(2, 22);
  a.insert_or_assign(3, 1);

  std_a.insert_or_assign(1, 1);
  std_a.insert_or_assign(2, 1);
  std_a.insert_or_assign(1, 11);
  std_a.insert_or_assign(2, 22);
  std_a.insert_or_assign(3, 1);

  EXPECT_EQ(a.empty(), std_a.empty());
  EXPECT_EQ(a.size(), std_a.size());
  EXPECT_EQ(compare(std_a, a), true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
