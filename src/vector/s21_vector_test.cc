// g++ -v -std=c++17  -lgtest s21_vector_test.cc
// clang-format -i *.
// CK_FORK=no leaks -atExit -- ./a.out

#include "s21_vector.h"

#include <gtest/gtest.h>

#include <iostream>
#include <vector>
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(vectorTest, DefaultConstructor_Emptyvector1) {
  s21::vector<int> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ((int)v.size(), (int)0);
}

// TEST(vectorTest, SizeConstructor_PositiveSize) {
//   const size_t size = 5;
//   s21::vector<int> v(size);
//   EXPECT_FALSE(v.empty());
//   EXPECT_EQ(v.size(), size);
//   for (size_t i = 0; i < size; ++i) {
//     EXPECT_EQ(v[i], 0);
//   }
// }

TEST(vectorTest, SizeConstructor_ZeroSize) {
  const size_t size = 0;
  s21::vector<int> v(size);
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), size);
}

TEST(vectorTest, InitializerListConstructor_EmptyList) {
  s21::vector<int> v = {};
  EXPECT_TRUE(v.empty());
  EXPECT_EQ((int)v.size(), (int)0);
}

TEST(vectorTest, InitializerListConstructor_NonEmptyList) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ((int)v.size(), (int)5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}

TEST(vectorTest, CopyConstructor_Emptyvector) {
  s21::vector<int> v1;
  s21::vector<int> v2(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ((int)v2.size(), (int)0);
}

TEST(vectorTest, CopyConstructor_NonEmptyvector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(v1);
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST(vectorTest, MoveConstructor_Emptyvector) {
  s21::vector<int> v1;
  s21::vector<int> v2(std::move(v1));
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ((int)v2.size(), (int)0);
}

TEST(vectorTest, MoveConstructor_NonEmptyvector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(std::move(v1));
  EXPECT_EQ((int)v2.size(), (int)3);
  EXPECT_TRUE(v1.empty());
}

TEST(vectorTest, Destructor_Emptyvector) {
  s21::vector<int> *v = new s21::vector<int>();
  delete v;
}

TEST(vectorTest, Destructor_NonEmptyvector) {
  s21::vector<int> *v = new s21::vector<int>{1, 2, 3};
  delete v;
}

TEST(vectorTest, MoveAssignmentOperator_EmptyToEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ((int)v2.size(), (int)0);
}

TEST(vectorTest, MoveAssignmentOperator_NonEmptyToEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ((int)v2.size(), (int)3);
  EXPECT_TRUE(v1.empty());
}

TEST(vectorTest, MoveAssignmentOperator_EmptyToNonEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ((int)v2.size(), (int)0);
}

TEST(vectorTest, At_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.at(4), 5);
}

TEST(vectorTest, At_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(vectorTest, IndexOperator_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(vectorTest, IndexOperator_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(vectorTest, ConstIndexOperator_ValidIndex) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(vectorTest, ConstIndexOperator_InvalidIndex) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(vectorTest, FrontConst_Validvector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.front(), 1);
}

TEST(vectorTest, FrontConst_Emptyvector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(vectorTest, BackConst_Validvector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.back(), 5);
}

TEST(vectorTest, BackConst_Emptyvector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.back(), std::out_of_range);
}

TEST(vectorTest, Data_Validvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  int *dataPtr = v.data();
  EXPECT_EQ(*dataPtr, 1);
  *dataPtr = 10;
  EXPECT_EQ(v[0], 10);
}
TEST(vectorTest, Data_Emptyvector) {
  s21::vector<int> v;
  int *dataPtr = v.data();
  EXPECT_EQ(dataPtr, nullptr);
}
TEST(vectorTest, Begin_Validvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  *it = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(vectorTest, Begin_Emptyvector) {
  s21::vector<int> v;
  auto it = v.begin();
  EXPECT_EQ(it, v.end());
}

TEST(vectorTest, End_Validvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.end();
  auto beginIt = v.begin();
  EXPECT_NE(it, beginIt);
}

TEST(vectorTest, End_Emptyvector) {
  s21::vector<int> v;
  auto it = v.end();
  EXPECT_EQ(it, v.begin());
}

TEST(vectorTest, Empty_Emptyvector) {
  const s21::vector<int> v;
  EXPECT_TRUE(v.empty());
}

TEST(vectorTest, Empty_NonEmptyvector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_FALSE(v.empty());
}

TEST(vectorTest, Size_Emptyvector) {
  const s21::vector<int> v;
  EXPECT_EQ((int)v.size(), (int)0);
}

TEST(vectorTest, Size_NonEmptyvector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_EQ((int)v.size(), (int)3);
}

TEST(vectorTest, Reserve_IncreaseCapacity) {
  s21::vector<int> v;
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity + 10;
  v.reserve(newCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(vectorTest, Reserve_DecreaseCapacity) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity - 2;
  v.reserve(newCapacity);
  EXPECT_LE(v.capacity(), initialCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(vectorTest, Capacity_Emptyvector) {
  const s21::vector<int> v;
  EXPECT_GE((int)v.capacity(), 0);
}

TEST(vectorTest, Capacity_NonEmptyvector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_GE(v.capacity(), v.size());
}

TEST(vectorTest, ShrinkToFit_Emptyvector) {
  s21::vector<int> v;
  v.shrink_to_fit();
  EXPECT_GE((int)v.capacity(), (int)0);
}

TEST(vectorTest, ShrinkToFit_NonEmptyvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  size_t initialCapacity = v.capacity();
  v.pop_back();
  v.shrink_to_fit();
  EXPECT_LE(v.capacity(), v.size());
  EXPECT_LE(v.capacity(), initialCapacity);
}

TEST(vectorTest, Clear_Emptyvector) {
  s21::vector<int> v;
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_GE((int)v.capacity(), (int)0);
}

TEST(vectorTest, Clear_NonEmptyvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_GE(v.capacity(), 0);
}

TEST(vectorTest, Insert_Beginning) {
  s21::vector<int> v = {2, 3, 4};
  auto it = v.insert(v.begin(), 1);
  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(*it, 1);
}

TEST(vectorTest, Insert_Middle) {
  s21::vector<int> v = {1, 3, 4};
  auto it = v.insert((v.begin() + 1), 2);
  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(*it, 2);
}

TEST(vectorTest, Insert_End) {
  s21::vector<int> v = {1, 2, 3};
  auto it = v.insert(v.end(), 4);
  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(*it, 4);
}

TEST(vectorTest, Erase_Beginning) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin());
  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ(v[0], 2);
}

TEST(vectorTest, Erase_Middle) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin() + 1);
  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ(v[1], 3);
}

TEST(vectorTest, Erase_End) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.end() - 1);
  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ(v[2], 3);
}

TEST(vectorTest, PushBack_Emptyvector) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ((int)v.size(), (int)1);
  EXPECT_EQ(v[0], 1);
}

TEST(vectorTest, PushBack_NonEmptyvector) {
  s21::vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[3], 4);
}

TEST(vectorTest, PopBack_NonEmptyvector) {
  s21::vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ((int)v.size(), (int)2);
  EXPECT_EQ(v.back(), 2);
}

TEST(vectorTest, PopBack_Emptyvector) {
  s21::vector<int> v;
  v.pop_back();
  EXPECT_TRUE(v.empty());
}

TEST(vectorTest, Swap_NonEmptyvectors) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ((int)v1.size(), (int)3);
  EXPECT_EQ((int)v2.size(), (int)3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);
}

TEST(vectorTest, Swap_EmptyAndNonEmptyvectors) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {1, 2, 3};

  v1.swap(v2);

  EXPECT_EQ((int)v1.size(), (int)3);
  EXPECT_FALSE(v1.empty());
  EXPECT_EQ((int)v2.size(), (int)0);
  EXPECT_TRUE(v2.empty());
}

TEST(vectorConstructorTest, DefaultConstructor) {
  s21::vector<int> v;

  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_EQ((int)v.capacity(), (int)0);

  EXPECT_EQ(v.data(), nullptr);
}

TEST(vectorConstructorTest, DefaultConstructorWithData) {
  s21::vector<int> v;

  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ((int)v.capacity(), (int)4);

  EXPECT_EQ(v[0], 10);
  EXPECT_EQ(v[1], 20);
  EXPECT_EQ(v[2], 30);
}

TEST(vectorConstructorTest, SizeConstructor) {
  s21::vector<int> v(5);

  EXPECT_EQ((int)v.size(), (int)5);
  EXPECT_EQ((int)v.capacity(), (int)5);
}

TEST(vectorConstructorTest, InitializerListConstructor) {
  s21::vector<int> v = {1, 2, 3, 4, 5};

  EXPECT_EQ((int)v.size(), (int)5);
  EXPECT_EQ((int)v.capacity(), (int)5);

  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ((int)v[i], (int)i + 1);
  }
}

TEST(vectorConstructorTest, EmptyInitializerListConstructor) {
  s21::vector<int> v = {};

  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_EQ((int)v.capacity(), (int)0);
}

TEST(vectorConstructorTest, CopyConstructor) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};

  s21::vector<int> v2(v1);

  EXPECT_EQ((int)v2.size(), (int)v1.size());
  EXPECT_EQ(v2.capacity(), v1.capacity());

  for (size_t i = 0; i < v2.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST(vectorConstructorTest, EmptyCopyConstructor) {
  s21::vector<int> v1;

  s21::vector<int> v2(v1);

  EXPECT_EQ((int)v2.size(), (int)0);
  EXPECT_EQ((int)v2.capacity(), (int)0);
}

TEST(vectorConstructorTest, MoveConstructor) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};

  s21::vector<int> v2(std::move(v1));

  EXPECT_EQ((int)v2.size(), (int)5);
  EXPECT_EQ((int)v2.capacity(), (int)5);

  for (size_t i = 0; i < v2.size(); ++i) {
    EXPECT_EQ((int)v2[i], (int)i + 1);
  }

  EXPECT_EQ((int)v1.size(), (int)0);
  EXPECT_EQ((int)v1.capacity(), (int)0);
  EXPECT_EQ(v1.data(), nullptr);
}

TEST(vectorConstructorTest, EmptyMoveConstructor) {
  s21::vector<int> v1;

  s21::vector<int> v2(std::move(v1));

  EXPECT_EQ((int)v2.size(), (int)0);
  EXPECT_EQ((int)v2.capacity(), (int)0);

  EXPECT_EQ((int)v1.size(), (int)0);
  EXPECT_EQ((int)v1.capacity(), (int)0);
  EXPECT_EQ(v1.data(), nullptr);
}

TEST(vectorDestructorTest, NonEmptyvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};

  EXPECT_NO_THROW({ v.~vector(); });

  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_EQ((int)v.capacity(), (int)0);

  EXPECT_EQ(v.data(), nullptr);
}

TEST(vectorDestructorTest, Emptyvector) {
  s21::vector<int> v;

  EXPECT_NO_THROW({ v.~vector(); });

  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_EQ((int)v.capacity(), (int)0);

  EXPECT_EQ(v.data(), nullptr);
}

TEST(vectorMoveAssignmentTest, MoveEmptyvector) {
  s21::vector<int> src;

  s21::vector<int> dest;
  dest = std::move(src);

  EXPECT_EQ((int)src.size(), (int)0);
  EXPECT_EQ((int)src.capacity(), (int)0);
  EXPECT_EQ(src.data(), nullptr);

  EXPECT_EQ((int)dest.size(), (int)0);
  EXPECT_EQ((int)dest.capacity(), (int)0);
  EXPECT_EQ(dest.data(), nullptr);
}

TEST(vectorMoveAssignmentTest, MoveNonEmptyvector) {
  s21::vector<int> src = {1, 2, 3, 4, 5};

  s21::vector<int> dest;
  dest = std::move(src);

  EXPECT_EQ((int)src.size(), (int)0);
  EXPECT_EQ((int)src.capacity(), (int)0);
  EXPECT_EQ(src.data(), nullptr);

  EXPECT_EQ((int)dest.size(), (int)5);
  EXPECT_GE((int)dest.capacity(), (int)5);
  EXPECT_NE(dest.data(), nullptr);
  EXPECT_EQ(dest[0], 1);
  EXPECT_EQ(dest[1], 2);
  EXPECT_EQ(dest[2], 3);
  EXPECT_EQ(dest[3], 4);
  EXPECT_EQ(dest[4], 5);
}

TEST(vectorMaxSizeTest, MaxSizeCheck) {
  s21::vector<int> v;

  EXPECT_EQ(v.max_size(),
            std::numeric_limits<s21::vector<int>::size_type>::max() /
                sizeof(int) / 2u);
}

TEST(vectorReserveTest, IncreaseCapacity) {
  s21::vector<int> v;

  v.reserve(10);

  EXPECT_EQ((int)v.capacity(), (int)10);
}

TEST(vectorReserveTest, IncreaseCapacityFromNonEmptyvector) {
  s21::vector<int> v = {1, 2, 3};

  v.reserve(10);

  EXPECT_EQ((int)v.capacity(), (int)10);

  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(vectorReserveTest, DecreaseCapacity) {
  s21::vector<int> v = {1, 2, 3, 4, 5};

  v.reserve(3);

  EXPECT_EQ((int)v.capacity(), (int)5);

  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(vectorCapacityTest, Emptyvector) {
  s21::vector<int> v;

  EXPECT_EQ((int)v.capacity(), (int)0);
}

TEST(vectorCapacityTest, NonEmptyvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};

  EXPECT_EQ((int)v.capacity(), (int)5);
}

TEST(vectorShrinkToFitTest, ShrinkNonEmptyvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};

  v.shrink_to_fit();

  EXPECT_EQ(v.capacity(), v.size());
}

TEST(vectorShrinkToFitTest, ShrinkEmptyvector) {
  s21::vector<int> v;

  v.shrink_to_fit();

  EXPECT_EQ((int)v.capacity(), (int)0);
}

TEST(vectorClearTest, ClearEmptyvector) {
  s21::vector<int> v;

  v.clear();

  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_EQ((int)v.capacity(), (int)0);
  EXPECT_EQ(v.data(), nullptr);
}

TEST(vectorTest, InsertIntoEmptyvector) {
  s21::vector<int> vec;
  vec.insert(vec.begin(), 5);

  ASSERT_EQ((int)vec.size(), (int)1);
  ASSERT_EQ(vec[0], 5);
}

TEST(vectorTest, InsertIntoMiddle) {
  s21::vector<int> vec = {1, 2, 3, 4};
  vec.insert(vec.begin() + 2, 10);

  ASSERT_EQ((int)vec.size(), (int)5);
  ASSERT_EQ(vec[0], 1);
  ASSERT_EQ(vec[1], 2);
  ASSERT_EQ(vec[2], 10);
  ASSERT_EQ(vec[3], 3);
  ASSERT_EQ(vec[4], 4);
}

TEST(vectorTest, InsertAtEnd) {
  s21::vector<int> vec = {1, 2, 3};
  vec.insert(vec.end(), 4);

  ASSERT_EQ((int)vec.size(), (int)4);
  ASSERT_EQ(vec[0], 1);
  ASSERT_EQ(vec[1], 2);
  ASSERT_EQ(vec[2], 3);
  ASSERT_EQ(vec[3], 4);
}

TEST(vectorTest, InsertReturnIterator) {
  s21::vector<int> vec = {1, 2, 3};
  s21::vector<int>::iterator it = vec.insert(vec.begin() + 1, 10);

  ASSERT_EQ(*it, 10);
}

TEST(vectorTest, InsertComparisonWithStdvector) {
  s21::vector<int> vec = {1, 2, 3};
  std::vector<int> stdVec = {1, 2, 3};

  vec.insert(vec.begin() + 1, 10);
  stdVec.insert(stdVec.begin() + 1, 10);

  ASSERT_EQ(vec.size(), stdVec.size());

  for (size_t i = 0; i < vec.size(); ++i) {
    ASSERT_EQ(vec[i], stdVec[i]);
  }
}

TEST(vectorEraseTest, EraseFromNonEmptyvector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};

  auto it = v.begin() + 2;
  v.erase(it);

  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 4);
  EXPECT_EQ(v[3], 5);
}

TEST(vectorEraseTest, EraseFromEmptyvector) {
  s21::vector<int> v;

  auto it = v.begin();
  v.erase(it);

  EXPECT_EQ((int)v.size(), (int)0);
}

TEST(vectorEraseTest, EraseOutOfRange) {
  s21::vector<int> v = {1, 2, 3};
  auto it = v.end();
  v.erase(it);
  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(vectorPushBackTest, PushEmptyvector) {
  s21::vector<int> v;

  v.push_back(10);

  EXPECT_EQ((int)v.size(), (int)1);
  EXPECT_EQ(v[0], 10);
}

TEST(vectorPushBackTest, PushNonEmptyvector) {
  s21::vector<int> v = {1, 2, 3};

  v.push_back(4);

  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], 4);
}

TEST(vectorPushBackTest, PushvectorWithCapacity) {
  s21::vector<int> v;
  v.reserve(10);

  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  EXPECT_EQ((int)v.size(), (int)10);
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(v[i], i);
  }
}

TEST(vectorPopBackTest, PopEmptyvector) {
  s21::vector<int> v;

  v.pop_back();

  EXPECT_EQ((int)v.size(), (int)0);
}

TEST(vectorPopBackTest, PopNonEmptyvector) {
  s21::vector<int> v = {1, 2, 3, 4};

  v.pop_back();

  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(vectorSwapTest, SwapEmptyvectors) {
  s21::vector<int> v1;
  s21::vector<int> v2;

  v1.swap(v2);

  EXPECT_EQ((int)v1.size(), (int)0);
  EXPECT_EQ((int)v1.capacity(), (int)0);
  EXPECT_EQ(v1.data(), nullptr);

  EXPECT_EQ((int)v2.size(), (int)0);
  EXPECT_EQ((int)v2.capacity(), (int)0);
  EXPECT_EQ(v2.data(), nullptr);
}

TEST(vectorSwapTest, SwapNonEmptyvectors) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6, 7};

  v1.swap(v2);

  EXPECT_EQ((int)v1.size(), (int)4);
  EXPECT_EQ((int)v1.capacity(), (int)4);
  EXPECT_NE(v1.data(), nullptr);
  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[1], 5);
  EXPECT_EQ(v1[2], 6);
  EXPECT_EQ(v1[3], 7);

  EXPECT_EQ((int)v2.size(), (int)3);
  EXPECT_EQ((int)v2.capacity(), (int)3);
  EXPECT_NE(v2.data(), nullptr);
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, Constructor_default1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.data(), std_v.data());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}
TEST(VectorTest, Capacity_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_GE((int)v.capacity(), (int)0);
}
TEST(VectorTest, Capacity_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_GE((int)v.capacity(), (int)v.size());
}

TEST(VectorTest, ShrinkToFit_EmptyVector) {
  s21::vector<int> v;
  v.shrink_to_fit();
  EXPECT_GE((int)v.capacity(), (int)0);
}
TEST(VectorTest, ShrinkToFit_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  v.pop_back();
  v.shrink_to_fit();
  EXPECT_LE(v.capacity(), v.size());
  EXPECT_LE(v.capacity(), initialCapacity);
}

TEST(VectorTest, Clear_EmptyVector) {
  s21::vector<int> v;
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_GE((int)v.capacity(), (int)0);
}
TEST(VectorTest, Clear_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ((int)v.size(), (int)0);
  EXPECT_GE((int)v.capacity(), (int)0);
}

TEST(VectorTest, Insert_Beginning) {
  s21::vector<int> v = {2, 3, 4};
  auto it = v.insert(v.begin(), 1);
  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(*it, 1);
}

TEST(VectorTest, Insert_Middle) {
  s21::vector<int> v = {1, 3, 4};
  auto it = v.insert(v.begin() + 1, 2);
  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(*it, 2);
}
TEST(VectorTest, Insert_End) {
  s21::vector<int> v = {1, 2, 3};
  auto it = v.insert(v.end(), 4);
  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(*it, 4);
}

TEST(VectorTest, Erase_Beginning) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin());
  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ(v[0], 2);
}

TEST(VectorTest, Erase_Middle) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin() + 1);
  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ(v[1], 3);
}
TEST(VectorTest, Erase_End) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.end() - 1);
  EXPECT_EQ((int)v.size(), (int)3);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, PushBack_EmptyVector) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ((int)v.size(), (int)1);
  EXPECT_EQ(v[0], 1);
}

TEST(VectorTest, PushBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ((int)v.size(), (int)4);
  EXPECT_EQ(v[3], 4);
}
TEST(VectorTest, PopBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ((int)v.size(), (int)2);
  EXPECT_EQ(v.back(), 2);
}

TEST(VectorTest, PopBack_EmptyVector) {
  s21::vector<int> v;
  v.pop_back();
  EXPECT_TRUE(v.empty());
}
TEST(VectorTest, Swap_NonEmptyVectors) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ((int)v1.size(), (int)3);
  EXPECT_EQ((int)v2.size(), (int)3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);
}
TEST(VectorTest, Swap_EmptyAndNonEmptyVectors) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {1, 2, 3};

  v1.swap(v2);

  EXPECT_EQ((int)v1.size(), (int)3);
  EXPECT_FALSE(v1.empty());
  EXPECT_EQ((int)v2.size(), (int)0);
  EXPECT_TRUE(v2.empty());
}
TEST(vector_test, operator_eq) {
  s21::vector<int> vec1 = {1, 2, 3, 5, 6, 3, 4};
  s21::vector<int> vec2;
  vec2 = vec1;
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
  auto it_2 = vec2.begin();
  for (auto it = vec1.begin(); it != vec1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(vector_test, operator_brackets) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < vec1.size(); i++) {
    EXPECT_EQ(vec1[i], vec2[i]);
  }
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, front) {
  s21::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.front(), vec2.front());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}
TEST(vector_test, back) {
  s21::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.back(), vec2.back());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, data) {
  s21::vector<int> vec1;
  EXPECT_EQ(vec1.data(), nullptr);
  s21::vector<int> vec2 = {1, 2, 3};
  EXPECT_FALSE(vec2.data() == nullptr);
}

TEST(vector_test, begin) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  auto iter1 = vec1.begin();
  auto iter2 = vec2.begin();
  EXPECT_EQ(*iter1, *iter2);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, end) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  auto iter1 = vec1.end();
  auto iter2 = vec2.end();
  EXPECT_EQ(*(iter1 - 1), *(iter2 - 1));
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, empty) {
  s21::vector<int> vec1;
  EXPECT_EQ(vec1.empty(), true);
  vec1 = {1, 2, 3};
  EXPECT_EQ(vec1.empty(), false);
}

TEST(vector_test, size) {
  s21::vector<int> vec1;
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ((int)vec1.size(), (int)0);
  vec1 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}
TEST(vector_test, capacity) {
  s21::vector<int> vec1;
  std::vector<int> vec2;
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
  vec1 = {1, 2, 3};
  vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}
TEST(vector_test, shrink_to_fit) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.push_back(11);
  vec2.push_back(11);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());

  vec1.shrink_to_fit();
  vec2.shrink_to_fit();

  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}
TEST(vector_test, clear) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.clear();
  vec2.clear();

  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, insert) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto iter1 = vec1.end();
  auto iter2 = vec2.end();
  vec1.insert(iter1, 11);
  vec2.insert(iter2, 11);
  EXPECT_EQ(vec1[10], vec2[10]);
  EXPECT_EQ(vec1.size(), vec2.size());

  iter1 = vec1.begin();
  iter2 = vec2.begin();
  vec1.insert(iter1 + 5, 11);
  vec2.insert(iter2 + 5, 11);
  EXPECT_EQ(vec1[5], vec2[5]);
  EXPECT_EQ(vec1.size(), vec2.size());
}
TEST(vector_test, erase) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto iter1 = vec1.end();
  auto iter2 = vec2.end();
  vec1.erase(iter1 - 1);
  vec2.erase(iter2 - 1);
  EXPECT_EQ(vec1[8], vec2[8]);
  EXPECT_EQ(vec1.size(), vec2.size());

  iter1 = vec1.begin();
  iter2 = vec2.begin();
  vec1.erase(iter1);
  vec2.erase(iter2);
  EXPECT_EQ(vec1[0], vec2[0]);
  EXPECT_EQ(vec1.size(), vec2.size());
}
TEST(vector_test, push_back) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.push_back(11);
  vec2.push_back(11);
  EXPECT_EQ(vec1[10], vec2[10]);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, pop_back) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.pop_back();
  vec2.pop_back();

  EXPECT_EQ(vec1.size(), vec2.size());
}

TEST(vector_test, swap) {
  s21::vector<int> vec1 = {1, 2, 3};
  s21::vector<int> vec1_1 = {3, 2, 1};
  vec1.swap(vec1_1);
  for (int i = 0, j = 3; i < 3; i++) {
    EXPECT_EQ(vec1_1[i], i + 1);
    EXPECT_EQ(vec1[i], j--);
  }
}

TEST(vector_test, resize) {
  s21::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {3, 2, 1};
  vec1.push_back(5);
  vec2.push_back(5);

  vec1.reserve(10);
  vec2.reserve(10);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());

  s21::vector<int> vec3 = {1, 2, 3};
  std::vector<int> vec4 = {3, 2, 1};
  vec1.reserve(2);
  vec2.reserve(2);
  EXPECT_EQ(vec3.size(), vec4.size());
  EXPECT_EQ(vec3.capacity(), vec4.capacity());
}

TEST(vector_emplace_back, case1) {
  s21::vector<int> s21_vec_int{1, 4};
  s21::vector<double> s21_vec_double{1.4, 4.8};
  s21::vector<std::string> s21_vec_string{"Hello", ","};

  s21_vec_int.emplace_back(2, 3);
  s21_vec_double.emplace_back(2.0, 3.56);
  s21_vec_string.emplace_back("world", "!");

  EXPECT_EQ(s21_vec_int[2], 2);
  EXPECT_EQ(s21_vec_int[3], 3);

  EXPECT_EQ(s21_vec_double[2], 2.0);
  EXPECT_EQ(s21_vec_double[3], 3.56);

  EXPECT_EQ(s21_vec_string[2], "world");
  EXPECT_EQ(s21_vec_string[3], "!");
}

TEST(vector_emplace, case3) {
  s21::vector<int> s21_vec_int;
  s21::vector<double> s21_vec_double;
  s21::vector<std::string> s21_vec_string;

  auto pos_int = s21_vec_int.begin();
  auto pos_double = s21_vec_double.begin();
  auto pos_string = s21_vec_string.begin();

  s21_vec_int.emplace(pos_int, 2, 3);
  s21_vec_double.emplace(pos_double, 2.0, 3.56);
  s21_vec_string.emplace(pos_string, "world", "!");

  EXPECT_EQ(s21_vec_int[0], 2);
  EXPECT_EQ(s21_vec_int[1], 3);

  EXPECT_EQ(s21_vec_double[0], 2.0);
  EXPECT_EQ(s21_vec_double[1], 3.56);

  EXPECT_EQ(s21_vec_string[0], "world");
  EXPECT_EQ(s21_vec_string[1], "!");
}
TEST(vector_emplace, case2) {
  s21::vector<int> s21_vec_int{1, 4};
  s21::vector<double> s21_vec_double{1.4, 4.8};
  s21::vector<std::string> s21_vec_string{"Hello", ","};

  auto pos_int = s21_vec_int.begin();
  auto pos_double = s21_vec_double.begin();
  auto pos_string = s21_vec_string.begin();

  s21_vec_int.emplace(pos_int, 2, 3);
  s21_vec_double.emplace(pos_double, 2.0, 3.56);
  s21_vec_string.emplace(pos_string, "world", "!");

  EXPECT_EQ(s21_vec_int[0], 2);
  EXPECT_EQ(s21_vec_int[1], 3);

  EXPECT_EQ(s21_vec_double[0], 2.0);
  EXPECT_EQ(s21_vec_double[1], 3.56);

  EXPECT_EQ(s21_vec_string[0], "world");
  EXPECT_EQ(s21_vec_string[1], "!");
}
TEST(vector_emplace, case1) {
  s21::vector<int> s21_vec_int{1, 4};
  s21::vector<double> s21_vec_double{1.4, 4.8};
  s21::vector<std::string> s21_vec_string{"Hello", ","};

  auto pos_int = s21_vec_int.begin() + 1;
  auto pos_double = s21_vec_double.begin() + 1;
  auto pos_string = s21_vec_string.begin() + 1;

  s21_vec_int.emplace(pos_int, 2, 3, 5);
  s21_vec_double.emplace(pos_double, 2.0, 3.56);
  s21_vec_string.emplace(pos_string, "world", "!");

  EXPECT_EQ(s21_vec_int[1], 2);
  EXPECT_EQ(s21_vec_int[2], 3);
  EXPECT_EQ(s21_vec_int[4], 4);
  EXPECT_EQ(s21_vec_double[1], 2.0);
  EXPECT_EQ(s21_vec_double[2], 3.56);

  EXPECT_EQ(s21_vec_string[1], "world");
  EXPECT_EQ(s21_vec_string[2], "!");
}

TEST(s21_vector, front_back_test_1) {
  s21::vector<int> myvector{78, 16};
  std::vector<int> test_vector{78, 16};
  ASSERT_EQ(myvector.front(), test_vector.front());
  ASSERT_EQ(myvector.back(), test_vector.back());
}

TEST(vector_modifiers, bounus_emplace_back_Test1) {
  s21::vector<int> myvector;
  myvector.emplace_back(1, 2, 3);
  ASSERT_EQ((int)myvector.size(), (int)3);
  ASSERT_EQ(myvector.front(), 1);
  ASSERT_EQ(myvector.back(), 3);
}

TEST(vector_modifiers, bounus_emplace_back_Test2) {
  s21::vector<int> myvector{9, 8, 7};
  myvector.emplace_back(1, 2, 3);
  auto n = myvector.begin();
  auto m = myvector.begin();
  ASSERT_EQ(m, n);
  ASSERT_EQ((int)myvector.size(), (int)6);
  ASSERT_EQ(myvector.front(), 9);
  ASSERT_EQ(myvector.back(), 3);
}