#ifndef CPP2_S21_CONTAINERS_SRC_QUEUE_H_
#define CPP2_S21_CONTAINERS_SRC_QUEUE_H_

#include "../list/s21_list.h"

namespace s21 {
template <class T, class Container = s21::list<T>>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue();  // конуструктор
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();

  queue &operator=(const queue &q);
  queue &operator=(queue &&q);

  const_reference front() const noexcept;
  const_reference back() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;

  void push(const_reference value);
  void push(value_type &&value);
  void pop();
  void swap(queue &q);

 private:
  Container container_;
};
}  // namespace s21

#include "s21_queue.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_QUEUE_H_