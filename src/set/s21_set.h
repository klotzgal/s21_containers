#ifndef CPP2_S21_CONTAINERS_SRC_SET_H_
#define CPP2_S21_CONTAINERS_SRC_SET_H_

#include "../btree/s21_btree.h"

namespace s21 {

template <typename T>
class set : public BTree<T> {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;

  set() : BTree<T>(){};
  explicit set(std::initializer_list<T> const& init) : BTree<T>(init) {}
  explicit set(const_reference value) : BTree<T>(value) {}
  set(const set& other) : BTree<T>(other) {}
  set(set&& other) : BTree<T>(std::move(other)) {}
  set& operator=(const set& other) {
    BTree<T>::operator=(other);
    return *this;
  }
  set& operator=(set&& other) {
    BTree<T>::operator=(std::move(other));
    return *this;
  }
};

#include "s21_set.tpp"
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_SET_H_
