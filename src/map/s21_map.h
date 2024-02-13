#ifndef _S21_CONTAINERS_SRC_S21_MAP_H_
#define _S21_CONTAINERS_SRC_S21_MAP_H_
#include <iostream>

#include "../btree/s21_btree.h"
namespace s21 {
template <typename Key, typename T>
class map : public BTree<std::pair<Key, T>> {
  struct MapIterator {};
  struct MapConstIterator {};

 public:
  using BTree<std::pair<Key, T>>::BTree;

  using key_type = Key;
  using mapped_type = T;

  using typename BTree<std::pair<Key, T>>::value_type;
  using typename BTree<value_type>::reference;
  using typename BTree<value_type>::const_reference;
  using typename BTree<value_type>::iterator;
  using typename BTree<value_type>::const_iterator;
  using typename BTree<value_type>::size_type;
  using typename BTree<value_type>::insert;

 public:
  map() : BTree<value_type>(){};
  map(std::initializer_list<value_type> const& items)
      : BTree<value_type>(items){};
  map(map&& m) noexcept : BTree<value_type>(std::move(m)){};
  map(const map& m) : BTree<value_type>(m){};

  T& at(const Key& key);
  T& operator[](const Key& key);

  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj);
};
}  // namespace s21
#include "s21_map.tpp"

#endif  // _S21_CONTAINERS_SRC_S21_MAP_H_