#ifndef CPP2_S21_CONTAINERS_SRC_STACK_H_
#define CPP2_S21_CONTAINERS_SRC_STACK_H_

#include "../list/s21_list.h"

namespace s21 {
template <class T, class Container = s21::list<T>>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack();  // конуструктор
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);  //
  stack(stack &&s);
  ~stack();

  stack &operator=(const stack &s);  //
  stack &operator=(stack &&s);

  const_reference top() const;

  bool empty() const noexcept;
  size_t size() const noexcept;

  void push(const_reference value);
  void push(value_type &&value);
  void pop();
  void swap(stack &s);

 private:
  Container container_;
};
}  // namespace s21

#include "s21_stack.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_STACK_H_