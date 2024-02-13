
#include "s21_set.h"

#include "gtest/gtest.h"

// Define a fixture for the unit tests
class SetTest : public ::testing::Test {
 protected:
  // Create an instance of the Set class
  s21::set<int> set;
  s21::set<int> set1;
  s21::set<int> set2;
};

// Test case: calling begin on an empty set
TEST_F(SetTest, EmptySetBegin) {
  // Arrange

  // Act
  auto iterator = set.begin();

  // Assert
  EXPECT_EQ(iterator, set.end());
}

// Test case: calling begin on a set with values
TEST_F(SetTest, NonEmptySet) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);

  // Act
  auto iterator = set.begin();

  // Assert
  EXPECT_NE(iterator, set.end());
  EXPECT_EQ(*iterator, 5);
}

// Test case: incrementing an iterator on an empty set
TEST_F(SetTest, IncrementEmptySet) {
  // Arrange
  auto iterator = set.begin();

  // Act
  ++iterator;

  // Assert
  EXPECT_EQ(iterator, set.end());
}

// Test case: incrementing an iterator on a set with values
TEST_F(SetTest, IncrementNonEmptySet) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);
  auto iterator = set.begin();

  // Act
  iterator++;

  // Assert
  EXPECT_NE(iterator, set.end());
  EXPECT_EQ(*iterator, 10);
}

// Test case: decrementing an iterator on an empty set
TEST_F(SetTest, DecrementEmptySet) {
  // Arrange
  auto iterator = set.end();

  // Act
  iterator--;

  // Assert
  EXPECT_EQ(iterator, set.end());
}

// Test case: decrementing an iterator on a set with values
TEST_F(SetTest, DecrementNonEmptySet) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);
  auto iterator = set.end();

  // Act
  --iterator;

  // Assert
  EXPECT_NE(iterator, set.end());
  EXPECT_EQ(*iterator, 15);
}

// Test case: incrementing an iterator on a set with multiple levels
TEST_F(SetTest, IncrementMultipleLevels) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);
  set.insert(20);
  set.insert(25);
  set.insert(30);
  set.insert(35);
  set.insert(40);
  set.insert(45);
  set.insert(50);
  auto iterator = set.begin();

  // Act
  ++iterator;
  ++iterator;
  ++iterator;

  // Assert
  EXPECT_NE(iterator, set.end());
  EXPECT_EQ(*iterator, 20);
}

// Test case: decrementing an iterator on a set with multiple levels
TEST_F(SetTest, DecrementMultipleLevels) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);
  set.insert(20);
  set.insert(25);
  set.insert(30);
  set.insert(35);
  set.insert(40);
  set.insert(45);
  set.insert(50);
  auto iterator = set.end();

  // Act
  --iterator;
  --iterator;
  --iterator;

  // Assert
  EXPECT_NE(iterator, set.end());
  EXPECT_EQ(*iterator, 40);
}

// Test case: incrementing an iterator on a set with edge values
TEST_F(SetTest, IncrementEdgeValues) {
  // Arrange
  set.insert(std::numeric_limits<int>::min());
  set.insert(std::numeric_limits<int>::max());
  auto iterator = set.begin();

  // Act
  ++iterator;

  // Assert
  EXPECT_NE(iterator, set.end());
  EXPECT_EQ(*iterator, std::numeric_limits<int>::max());
}

// Test case: set is empty
TEST_F(SetTest, EmptySetEmpty) {
  // Arrange

  // Act

  // Assert
  EXPECT_TRUE(set.empty());
}

// Test case: set is not empty
TEST_F(SetTest, NonEmptySetEmpty) {
  // Arrange
  set.insert(5);

  // Act

  // Assert
  EXPECT_FALSE(set.empty());
}

// Test case: set is empty
TEST_F(SetTest, EmptySetSize) {
  // Arrange

  // Act

  // Assert
  EXPECT_TRUE(set.empty());
  EXPECT_EQ(set.size(), 0);
}

// Test case: set has one element
TEST_F(SetTest, SizeOne) {
  // Arrange
  set.insert(5);

  // Act

  // Assert
  EXPECT_FALSE(set.empty());
  EXPECT_EQ(set.size(), 1);
}

// Test case: set has multiple elements
TEST_F(SetTest, SizeMultiple) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);

  // Act

  // Assert
  EXPECT_FALSE(set.empty());
  EXPECT_EQ(set.size(), 3);
}

// Test case: check max size of the set
TEST_F(SetTest, MaxSize) {
  // Arrange

  // Act

  // Assert
  EXPECT_EQ(set.max_size(), std::numeric_limits<std::size_t>::max());
}

// Test case: clear empty set
TEST_F(SetTest, ClearEmptySet) {
  // Arrange

  // Act
  set.clear();

  // Assert
  EXPECT_TRUE(set.empty());
}

// Test case: clear non-empty set
TEST_F(SetTest, ClearNonEmptySet) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);

  // Act
  set.clear();

  // Assert
  EXPECT_TRUE(set.empty());
}

// Test case: insert a value into an empty set
TEST_F(SetTest, EmptySetInsert) {
  // Arrange
  int value = 10;

  // Act
  auto result = set.insert(value);

  // Assert
  EXPECT_EQ(result.second, true);
  EXPECT_EQ(*result.first, value);
}

// Test case: insert a value into a set with existing values
TEST_F(SetTest, ExistingValues) {
  // Arrange
  int value1 = 5;
  int value2 = 10;
  int value3 = 15;

  // Act
  set.insert(value1);
  set.insert(value2);
  set.insert(value3);

  // Assert
  EXPECT_EQ(set.size(), 3);
}

// Test case: insert a duplicate value into the set
TEST_F(SetTest, DuplicateValue) {
  // Arrange
  int value = 10;

  // Act
  set.insert(value);
  auto result = set.insert(value);

  // Assert
  EXPECT_EQ(result.second, false);
}

// Test case: erase element from empty set
TEST_F(SetTest, EraseEmptySet) {
  // Arrange
  s21::set<int>::iterator pos = set.begin();

  // Act
  set.erase(pos);

  // Assert
  EXPECT_TRUE(set.empty());
}

// Test case: erase element from set with one element
TEST_F(SetTest, EraseOneElement) {
  // Arrange
  set.insert(5);
  s21::set<int>::iterator pos = set.begin();

  // Act
  set.erase(pos);

  // Assert
  EXPECT_TRUE(set.empty());
}

// Test case: erase element from set with multiple elements
TEST_F(SetTest, EraseMultipleElements) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);
  s21::set<int>::iterator pos = set.find(10);

  // Act
  set.erase(pos);

  // Assert
  EXPECT_EQ(set.size(), 2);
  EXPECT_FALSE(set.contains(10));
}

// Test case: swap empty sets
TEST_F(SetTest, SwapEmptySets) {
  // Arrange

  // Act
  set1.swap(set2);

  // Assert
  EXPECT_TRUE(set1.empty());
  EXPECT_TRUE(set2.empty());
}

// Test case: swap sets with one element
TEST_F(SetTest, SwapSetsOneElement) {
  // Arrange
  set1.insert(5);
  set2.insert(10);

  // Act
  set1.swap(set2);

  // Assert
  EXPECT_EQ(set1.size(), 1);
  EXPECT_EQ(*set1.begin(), 10);
  EXPECT_EQ(set2.size(), 1);
  EXPECT_EQ(*set2.begin(), 5);
}

// Test case: swap sets with multiple elements
TEST_F(SetTest, SwapSetsMultipleElements) {
  // Arrange
  set1.insert(5);
  set1.insert(10);
  set1.insert(15);
  set2.insert(20);
  set2.insert(25);
  set2.insert(30);

  // Act
  set1.swap(set2);

  // Assert
  EXPECT_EQ(set1.size(), 3);
  EXPECT_EQ(*set1.begin(), 20);
  EXPECT_EQ(*(++set1.begin()), 25);
  EXPECT_EQ(*(++(++set1.begin())), 30);
  EXPECT_EQ(set2.size(), 3);
  EXPECT_EQ(*set2.begin(), 5);
  EXPECT_EQ(*(++set2.begin()), 10);
  EXPECT_EQ(*(++(++set2.begin())), 15);
}

// Test case: merge empty sets
TEST_F(SetTest, MergeEmptySets) {
  // Arrange

  // Act
  set1.merge(set2);

  // Assert
  EXPECT_TRUE(set1.empty());
  EXPECT_TRUE(set2.empty());
}

// Test case: merge sets with one element
TEST_F(SetTest, MergeSetsOneElement) {
  // Arrange
  set1.insert(5);
  set2.insert(10);

  // Act
  set1.merge(set2);

  // Assert
  EXPECT_EQ(set1.size(), 2);
  EXPECT_TRUE(set1.contains(5));
  EXPECT_TRUE(set1.contains(10));
  EXPECT_TRUE(set2.empty());
}

// Test case: merge sets with multiple elements
TEST_F(SetTest, MergeSetsMultipleElements) {
  // Arrange
  set1.insert(5);
  set1.insert(10);
  set1.insert(15);
  set2.insert(20);
  set2.insert(25);
  set2.insert(30);

  // Act
  set1.merge(set2);

  // Assert
  EXPECT_EQ(set1.size(), 6);
  EXPECT_TRUE(set1.contains(5));
  EXPECT_TRUE(set1.contains(10));
  EXPECT_TRUE(set1.contains(15));
  EXPECT_TRUE(set1.contains(20));
  EXPECT_TRUE(set1.contains(25));
  EXPECT_TRUE(set1.contains(30));
  EXPECT_TRUE(set2.empty());
}

// Test case: merge sets with overlapping elements
TEST_F(SetTest, MergeSetsOverlappingElements) {
  // Arrange
  set1.insert(5);
  set1.insert(10);
  set1.insert(15);
  set2.insert(10);
  set2.insert(20);
  set2.insert(25);

  // Act
  set1.merge(set2);

  // Assert
  EXPECT_EQ(set1.size(), 5);
  EXPECT_TRUE(set1.contains(5));
  EXPECT_TRUE(set1.contains(10));
  EXPECT_TRUE(set1.contains(15));
  EXPECT_TRUE(set1.contains(20));
  EXPECT_TRUE(set1.contains(25));
  EXPECT_EQ(set2.size(), 1);
  EXPECT_TRUE(set2.contains(10));
}

// Test case: find existing key
TEST_F(SetTest, FindExistingKey) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);

  // Act
  auto it = set.find(10);

  // Assert
  EXPECT_NE(it, set.end());
  EXPECT_EQ(*it, 10);
}

// Test case: find non-existing key
TEST_F(SetTest, FindNonExistingKey) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);

  // Act
  auto it = set.find(20);

  // Assert
  EXPECT_EQ(it, set.end());
}

// Test case: check if the set contains an existing key
TEST_F(SetTest, ContainsExistingKey) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);

  // Act
  bool result = set.contains(10);

  // Assert
  EXPECT_TRUE(result);
}

// Test case: check if the set contains a non-existing key
TEST_F(SetTest, ContainsNonExistingKey) {
  // Arrange
  set.insert(5);
  set.insert(10);
  set.insert(15);

  // Act
  bool result = set.contains(20);

  // Assert
  EXPECT_FALSE(result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
