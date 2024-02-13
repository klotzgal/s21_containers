#ifndef _S21_CONTAINERS_SRC_S21_MULTISET_H_
#define _S21_CONTAINERS_SRC_S21_MULTISET_H_

#include "../set/s21_set.h"

namespace s21 {

template <typename T>
class multiset : public set<T> {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;

  using typename BTree<value_type>::iterator;
  using typename BTree<value_type>::const_iterator;

  multiset() : set<T>(){};
  explicit multiset(std::initializer_list<T> const& init) : set<T>(init) {}
  explicit multiset(const_reference value) : set<T>(value) {}
  multiset(const multiset& other) : set<T>(other) {}
  multiset(multiset&& other) : set<T>(std::move(other)) {}
  multiset& operator=(const multiset& other) {
    set<T>::operator=(other);
    return *this;
  }
  multiset& operator=(multiset&& other) {
    set<T>::operator=(std::move(other));
    return *this;
  }

  std::pair<const_iterator, bool> insert(const_reference value) {
    return set<T>::insert(value, true);
  }
};

#include "s21_multiset.tpp"
}  // namespace s21

#endif  // _S21_CONTAINERS_SRC_S21_MULTISET_H_
