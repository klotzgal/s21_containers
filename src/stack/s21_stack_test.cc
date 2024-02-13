#include "s21_stack.h"

#include <gtest/gtest.h>

// for linux
// g++ -std=c++17 s21_stack_test.cc -lgtest -lgtest_main -pthread -o test

// Тесты конструкторов и операторов присваивания

TEST(StackTest, DefaultConstructor) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, ConstructorWithInitializerList) {
  s21::stack<int> stack({1, 2, 3});
  EXPECT_FALSE(stack.empty());
  EXPECT_EQ(stack.size(), 3);
  EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, CopyConstructor) {
  s21::stack<int> stack1({1, 2, 3});
  s21::stack<int> stack2(stack1);
  EXPECT_FALSE(stack2.empty());
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
}

TEST(StackTest, MoveConstructor) {
  s21::stack<int> stack1({1, 2, 3});
  s21::stack<int> stack2(std::move(stack1));
  EXPECT_FALSE(stack2.empty());
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
  EXPECT_TRUE(stack1.empty());  // Проверка, что исходный стек пуст
}

TEST(StackTest, CopyAssignmentOperator) {
  s21::stack<int> stack1({1, 2, 3});
  s21::stack<int> stack2;
  stack2 = stack1;
  EXPECT_FALSE(stack2.empty());
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
}

TEST(StackTest, MoveAssignmentOperator) {
  s21::stack<int> stack1({1, 2, 3});
  s21::stack<int> stack2;
  stack2 = std::move(stack1);
  EXPECT_FALSE(stack2.empty());
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
  EXPECT_TRUE(stack1.empty());  // Проверка, что исходный стек пуст
}

// Тесты методов стека

TEST(StackTest, Top) {
  s21::stack<int> stack({1, 2, 3});
  EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, Empty) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());
}

TEST(StackTest, NotEmpty) {
  s21::stack<int> stack({1, 2, 3});
  EXPECT_FALSE(stack.empty());
}

TEST(StackTest, SizeEmptyStack) {
  s21::stack<int> stack;
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, Size) {
  s21::stack<int> stack({1, 2, 3});
  EXPECT_EQ(stack.size(), 3);
}

TEST(StackTest, PushAndTop) {
  s21::stack<int> stack;
  stack.push(42);
  EXPECT_EQ(stack.top(), 42);
  EXPECT_EQ(stack.size(), 1);
  EXPECT_FALSE(stack.empty());
}

TEST(StackTest, PushRvalueAndTop) {
  s21::stack<int> stack;
  stack.push(42);
  EXPECT_EQ(stack.top(), 42);
  EXPECT_EQ(stack.size(), 1);
  EXPECT_FALSE(stack.empty());
}

TEST(StackTest, Pop) {
  s21::stack<int> stack({1, 2, 3});
  stack.pop();
  EXPECT_EQ(stack.top(), 2);
  EXPECT_EQ(stack.size(), 2);
}

TEST(StackTest, PopEmptyStack) {
  s21::stack<int> stack;
  EXPECT_NO_THROW(stack.pop());  // Ожидается, что ничего не произойдет
}

TEST(StackTest, Swap) {
  s21::stack<int> stack1({1, 2, 3});
  s21::stack<int> stack2({4, 5, 6});
  stack1.swap(stack2);
  EXPECT_EQ(stack1.top(), 6);
  EXPECT_EQ(stack2.top(), 3);
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack2.size(), 3);
}

TEST(StackTest, SwapEmptyStack) {
  s21::stack<int> stack1;
  s21::stack<int> stack2;
  stack1.swap(stack2);
  EXPECT_TRUE(stack1.empty());
  EXPECT_TRUE(stack2.empty());
  EXPECT_EQ(stack1.size(), 0);
  EXPECT_EQ(stack2.size(), 0);
}

// Дополнительные тесты

TEST(StackTest, PushAndPop) {
  s21::stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.pop();
  EXPECT_EQ(stack.top(), 2);
  stack.push(4);
  EXPECT_EQ(stack.top(), 4);
}

TEST(StackTest, PushRvalueAndPop) {
  s21::stack<std::string> stack;
  stack.push("one");
  stack.push("two");
  stack.push("three");
  stack.pop();
  EXPECT_EQ(stack.top(), "two");
  stack.push("four");
  EXPECT_EQ(stack.top(), "four");
}

TEST(StackTest, SwapWithEmpty) {
  s21::stack<int> stack1({1, 2, 3});
  s21::stack<int> stack2;
  stack1.swap(stack2);
  EXPECT_TRUE(stack1.empty());
  EXPECT_EQ(stack1.size(), 0);
  EXPECT_FALSE(stack2.empty());
  EXPECT_EQ(stack2.size(), 3);
}

TEST(StackTest, SwapWithDifferentContainers) {
  s21::stack<int, std::vector<int>> stack1({1, 2, 3});
  s21::stack<int, std::vector<int>> stack2({4, 5, 6});
  stack1.swap(stack2);
  EXPECT_EQ(stack1.top(), 6);
  EXPECT_EQ(stack2.top(), 3);
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack2.size(), 3);
}

TEST(StackTest, StressTest) {
  s21::stack<int> stack;
  for (int i = 0; i < 100000; ++i) {
    stack.push(i);
  }
  EXPECT_EQ(stack.size(), 100000);
  for (int i = 99999; i >= 0; --i) {
    EXPECT_EQ(stack.top(), i);
    stack.pop();
  }
  EXPECT_TRUE(stack.empty());
  EXPECT_EQ(stack.size(), 0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
