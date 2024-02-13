
#include "s21_multiset.h"

#include "gtest/gtest.h"

// Define a fixture for the unit tests
class multisetTest : public ::testing::Test {
 protected:
  // Create an instance of the multiset class
  s21::multiset<int> multiset;
  s21::multiset<int> multiset1;
  s21::multiset<int> multiset2;
};

// Test case: calling begin on an empty multiset
TEST_F(multisetTest, EmptymultisetBegin) {
  // Arrange

  // Act
  auto iterator = multiset.begin();

  // Assert
  EXPECT_EQ(iterator, multiset.end());
}

// Test case: calling begin on a multiset with values
TEST_F(multisetTest, NonEmptymultiset) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);

  // Act
  auto iterator = multiset.begin();
  std::cout << *iterator << "\n";
  // Assert
  EXPECT_NE(iterator, multiset.end());

  EXPECT_EQ(*iterator, 5);
}

// // Test case: incrementing an iterator on an empty multiset
TEST_F(multisetTest, IncrementEmptymultiset) {
  // Arrange
  auto iterator = multiset.begin();

  // Act
  ++iterator;

  // Assert
  EXPECT_EQ(iterator, multiset.end());
}

// // Test case: incrementing an iterator on a multiset with values
TEST_F(multisetTest, IncrementNonEmptymultiset) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);
  auto iterator = multiset.begin();

  // Act
  iterator++;

  // Assert
  EXPECT_NE(iterator, multiset.end());
  EXPECT_EQ(*iterator, 10);
}

// // Test case: decrementing an iterator on an empty multiset
TEST_F(multisetTest, DecrementEmptymultiset) {
  // Arrange
  auto iterator = multiset.end();

  // Act
  iterator--;

  // Assert
  EXPECT_EQ(iterator, multiset.end());
}

// // Test case: decrementing an iterator on a multiset with values
TEST_F(multisetTest, DecrementNonEmptymultiset) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);
  auto iterator = multiset.end();

  // Act
  --iterator;

  // Assert
  EXPECT_NE(iterator, multiset.end());
  EXPECT_EQ(*iterator, 15);
}

// // Test case: incrementing an iterator on a multiset with multiple levels
TEST_F(multisetTest, IncrementMultipleLevels) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);
  multiset.insert(20);
  multiset.insert(25);
  multiset.insert(30);
  multiset.insert(35);
  multiset.insert(40);
  multiset.insert(45);
  multiset.insert(50);
  auto iterator = multiset.begin();

  // Act
  ++iterator;
  ++iterator;
  ++iterator;

  // Assert
  EXPECT_NE(iterator, multiset.end());
  EXPECT_EQ(*iterator, 20);
}

// // Test case: decrementing an iterator on a multiset with multiple levels
TEST_F(multisetTest, DecrementMultipleLevels) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);
  multiset.insert(20);
  multiset.insert(25);
  multiset.insert(30);
  multiset.insert(35);
  multiset.insert(40);
  multiset.insert(45);
  multiset.insert(50);
  auto iterator = multiset.end();

  // Act
  --iterator;
  --iterator;
  --iterator;

  // Assert
  EXPECT_NE(iterator, multiset.end());
  EXPECT_EQ(*iterator, 40);
}

// // Test case: incrementing an iterator on a multiset with edge values
TEST_F(multisetTest, IncrementEdgeValues) {
  // Arrange
  multiset.insert(std::numeric_limits<int>::min());
  multiset.insert(std::numeric_limits<int>::max());
  auto iterator = multiset.begin();

  // Act
  ++iterator;

  // Assert
  EXPECT_NE(iterator, multiset.end());
  EXPECT_EQ(*iterator, std::numeric_limits<int>::max());
}

// Test case: multiset is empty
TEST_F(multisetTest, EmptymultisetEmpty) { EXPECT_TRUE(multiset.empty()); }

// Test case: multiset is not empty
TEST_F(multisetTest, NonEmptymultisetEmpty) {
  // Arrange
  multiset.insert(5);

  // Act

  // Assert
  EXPECT_FALSE(multiset.empty());
}

// Test case: multiset is empty
TEST_F(multisetTest, EmptymultisetSize) {
  // Arrange

  // Act

  // Assert
  EXPECT_TRUE(multiset.empty());
  EXPECT_EQ(multiset.size(), 0);
}

// Test case: multiset has one element
TEST_F(multisetTest, SizeOne) {
  // Arrange
  multiset.insert(5);

  // Act

  // Assert
  EXPECT_FALSE(multiset.empty());
  EXPECT_EQ(multiset.size(), 1);
}

// Test case: multiset has multiple elements
TEST_F(multisetTest, SizeMultiple) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);

  // Act

  // Assert
  EXPECT_FALSE(multiset.empty());
  EXPECT_EQ(multiset.size(), 3);
}

// Test case: check max size of the multiset
TEST_F(multisetTest, MaxSize) {
  // Arrange

  // Act

  // Assert
  EXPECT_EQ(multiset.max_size(), std::numeric_limits<std::size_t>::max());
}

// Test case: clear empty multiset
TEST_F(multisetTest, ClearEmptymultiset) {
  // Arrange

  // Act
  multiset.clear();

  // Assert
  EXPECT_TRUE(multiset.empty());
}

// Test case: clear non-empty multiset
TEST_F(multisetTest, ClearNonEmptymultiset) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);

  // Act
  multiset.clear();

  // Assert
  EXPECT_TRUE(multiset.empty());
}

// Test case: insert a value into an empty multiset
TEST_F(multisetTest, EmptymultisetInsert) {
  // Arrange
  int value = 10;

  // Act
  auto result = multiset.insert(value);

  // Assert
  EXPECT_EQ(result.second, true);
  EXPECT_EQ(*result.first, value);
}

// Test case: insert a value into a multiset with existing values
TEST_F(multisetTest, ExistingValues) {
  // Arrange
  int value1 = 5;
  int value2 = 10;
  int value3 = 15;

  // Act
  multiset.insert(value1);
  multiset.insert(value2);
  multiset.insert(value3);

  // Assert
  EXPECT_EQ(multiset.size(), 3);
}

// Test case: insert a duplicate value into the multiset
TEST_F(multisetTest, DuplicateValue) {
  // Arrange
  int value = 10;

  // Act
  multiset.insert(value);
  auto result = multiset.insert(value);

  // Assert
  EXPECT_EQ(result.second, true);
}

TEST_F(multisetTest, DuplicateValueDelete) {
  // Arrange
  int value = 10;

  // Act
  multiset.insert(value);
  auto result = multiset.insert(value);

  multiset.erase(result.first);

  // Assert
  EXPECT_EQ(multiset.contains(10), true);
}

// Test case: erase element from empty multiset
TEST_F(multisetTest, EraseEmptymultiset) {
  // Arrange
  s21::multiset<int>::iterator pos = multiset.begin();

  // Act
  multiset.erase(pos);

  // Assert
  EXPECT_TRUE(multiset.empty());
}

// Test case: erase element from multiset with one element
TEST_F(multisetTest, EraseOneElement) {
  // Arrange
  multiset.insert(5);
  s21::multiset<int>::iterator pos = multiset.begin();

  // Act
  multiset.erase(pos);

  // Assert
  EXPECT_TRUE(multiset.empty());
}

// Test case: erase element from multiset with multiple elements
TEST_F(multisetTest, EraseMultipleElements) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);
  s21::multiset<int>::iterator pos = multiset.find(10);

  // Act
  multiset.erase(pos);

  // Assert
  EXPECT_EQ(multiset.size(), 2);
  EXPECT_FALSE(multiset.contains(10));
}

// Test case: swap empty multisets
TEST_F(multisetTest, SwapEmptymultisets) {
  // Arrange

  // Act
  multiset1.swap(multiset2);

  // Assert
  EXPECT_TRUE(multiset1.empty());
  EXPECT_TRUE(multiset2.empty());
}

// Test case: swap multisets with one element
TEST_F(multisetTest, SwapmultisetsOneElement) {
  // Arrange
  multiset1.insert(5);
  multiset2.insert(10);

  // Act
  multiset1.swap(multiset2);

  // Assert
  EXPECT_EQ(multiset1.size(), 1);
  EXPECT_EQ(*multiset1.begin(), 10);
  EXPECT_EQ(multiset2.size(), 1);
  EXPECT_EQ(*multiset2.begin(), 5);
}

// Test case: swap multisets with multiple elements
TEST_F(multisetTest, SwapmultisetsMultipleElements) {
  // Arrange
  multiset1.insert(5);
  multiset1.insert(10);
  multiset1.insert(15);
  multiset2.insert(20);
  multiset2.insert(25);
  multiset2.insert(30);

  // Act
  multiset1.swap(multiset2);

  // Assert
  EXPECT_EQ(multiset1.size(), 3);
  EXPECT_EQ(*multiset1.begin(), 20);
  EXPECT_EQ(*(++multiset1.begin()), 25);
  EXPECT_EQ(*(++(++multiset1.begin())), 30);
  EXPECT_EQ(multiset2.size(), 3);
  EXPECT_EQ(*multiset2.begin(), 5);
  EXPECT_EQ(*(++multiset2.begin()), 10);
  EXPECT_EQ(*(++(++multiset2.begin())), 15);
}

// Test case: merge empty multisets
TEST_F(multisetTest, MergeEmptymultisets) {
  // Arrange

  // Act
  multiset1.merge(multiset2);

  // Assert
  EXPECT_TRUE(multiset1.empty());
  EXPECT_TRUE(multiset2.empty());
}

// Test case: merge multisets with one element
TEST_F(multisetTest, MergemultisetsOneElement) {
  // Arrange
  multiset1.insert(5);
  multiset2.insert(10);

  // Act
  multiset1.merge(multiset2);

  // Assert
  EXPECT_EQ(multiset1.size(), 2);
  EXPECT_TRUE(multiset1.contains(5));
  EXPECT_TRUE(multiset1.contains(10));
  EXPECT_TRUE(multiset2.empty());
}

// Test case: merge multisets with multiple elements
TEST_F(multisetTest, MergemultisetsMultipleElements) {
  // Arrange
  multiset1.insert(5);
  multiset1.insert(10);
  multiset1.insert(15);
  multiset2.insert(20);
  multiset2.insert(25);
  multiset2.insert(30);

  // Act
  multiset1.merge(multiset2);

  // Assert
  EXPECT_EQ(multiset1.size(), 6);
  EXPECT_TRUE(multiset1.contains(5));
  EXPECT_TRUE(multiset1.contains(10));
  EXPECT_TRUE(multiset1.contains(15));
  EXPECT_TRUE(multiset1.contains(20));
  EXPECT_TRUE(multiset1.contains(25));
  EXPECT_TRUE(multiset1.contains(30));
  EXPECT_TRUE(multiset2.empty());
}

// Test case: merge multisets with overlapping elements
TEST_F(multisetTest, MergemultisetsOverlappingElements) {
  // Arrange
  multiset1.insert(5);
  multiset1.insert(10);
  multiset1.insert(15);
  multiset2.insert(10);
  multiset2.insert(20);
  multiset2.insert(25);

  // Act
  multiset1.merge(multiset2);

  // Assert
  EXPECT_EQ(multiset1.size(), 5);
  EXPECT_TRUE(multiset1.contains(5));
  EXPECT_TRUE(multiset1.contains(10));
  EXPECT_TRUE(multiset1.contains(15));
  EXPECT_TRUE(multiset1.contains(20));
  EXPECT_TRUE(multiset1.contains(25));
  EXPECT_EQ(multiset2.size(), 1);
  EXPECT_TRUE(multiset2.contains(10));
}

// Test case: find existing key
TEST_F(multisetTest, FindExistingKey) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);

  // Act
  auto it = multiset.find(10);

  // Assert
  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 10);
}

// Test case: find non-existing key
TEST_F(multisetTest, FindNonExistingKey) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);

  // Act
  auto it = multiset.find(20);

  // Assert
  EXPECT_EQ(it, multiset.end());
}

// Test case: check if the multiset contains an existing key
TEST_F(multisetTest, ContainsExistingKey) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);

  // Act
  bool result = multiset.contains(10);

  // Assert
  EXPECT_TRUE(result);
}

// Test case: check if the multiset contains a non-existing key
TEST_F(multisetTest, ContainsNonExistingKey) {
  // Arrange
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(15);

  // Act
  bool result = multiset.contains(20);

  // Assert
  EXPECT_FALSE(result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
