#include "s21_btree.h"

namespace s21 {

//* Методы итератора

/**
 * @brief Инкремент итератора для дерева (++).
 *
 * @tparam T Тип элементов в дереве.
 */
template <typename T>
BTree<T>::iterator::BTreeIterator(const BTreeIterator& other) {
  current_ = other.current_;
  end_ = other.end_;
}

template <typename T>
typename BTree<T>::BTreeIterator& BTree<T>::iterator::operator=(
    const BTreeIterator& other) {
  current_ = other.current_;
  return *this;
}

template <typename T>
typename BTree<T>::BTreeIterator& BTree<T>::iterator::operator++() {
  if (end_ || !current_) {
    return *this;
  }

  if (current_->right) {
    current_ = current_->right;
    while (current_->left) {
      current_ = current_->left;
    }
    end_ = false;
  } else {
    Node* ptr = current_;
    while (ptr->parent && ptr->parent->right == ptr) {
      ptr = ptr->parent;
    }
    if (ptr->parent == nullptr) {
      end_ = true;
    } else {
      current_ = ptr->parent;
    }
  }
  return *this;
}

template <typename T>
typename BTree<T>::BTreeIterator& BTree<T>::iterator::operator++(int) {
  ++(*this);
  return *this;
}

/**
 * @brief Декремент итератора для дерева (++).
 *
 * @tparam T Тип элементов в дереве.
 */
template <typename T>
typename BTree<T>::BTreeIterator& BTree<T>::iterator::operator--() {
  if (!current_) {
    return *this;
  }

  if (end_) {
    end_ = false;
    return *this;
  }

  if (current_->left) {
    current_ = current_->left;
    while (current_->right) {
      current_ = current_->right;
    }
  } else {
    Node* ptr = current_;
    while (ptr->parent && ptr->parent->left == ptr) {
      ptr = ptr->parent;
    }
    if (ptr->parent == nullptr) {
      end_ = true;
    } else {
      current_ = ptr->parent;
    }
  }
  return *this;
}

template <typename T>
typename BTree<T>::BTreeIterator& BTree<T>::iterator::operator--(int) {
  --(*this);
  return *this;
}

template <typename T>
bool BTree<T>::BTreeIterator::operator==(const BTreeIterator& other) const {
  return end_ ? (end_ == other.end_)
              : (current_ == other.current_ && end_ == other.end_);
}

template <typename T>
bool BTree<T>::BTreeIterator::operator!=(const BTreeIterator& other) const {
  return end_ ? (end_ != other.end_)
              : (current_ != other.current_ || end_ != other.end_);
}
template <typename T>
T& BTree<T>::BTreeIterator::get_value() {
  if (current_) {
    return current_->data;
  }
  throw std::out_of_range("Iterator is not pointing to a valid node");
}

}  // namespace s21
