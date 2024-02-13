#ifndef CPP2_S21_CONTAINERS_SRC_BTREE_TPP_
#define CPP2_S21_CONTAINERS_SRC_BTREE_TPP_

namespace s21 {
//* Конструкторы
template <typename T>
BTree<T>::BTree() : root_(nullptr), size_(0) {}

template <typename T>
BTree<T>::BTree(std::initializer_list<T> const& init)
    : root_(nullptr), size_(0) {
  auto it = init.begin();
  while (it != init.end()) {
    insert(*it++);
  }
}

template <typename T>
BTree<T>::BTree(const BTree& other) : root_(nullptr), size_(0) {
  Clear(root_);
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
}

template <typename T>
BTree<T>::BTree(BTree&& other) noexcept
    : root_(other.root_), size_(other.size_) {
  other.root_ = nullptr;
  other.size_ = 0;
}

template <typename T>
BTree<T>& BTree<T>::operator=(const BTree& other) {
  if (&other != this) {
    BTree tmp(other);
    this = std::move(tmp);
  }
  return *this;
}

template <typename T>
BTree<T>& BTree<T>::operator=(BTree&& other) noexcept {
  if (&other != this) {
    Clear(root_);
    root_ = other.root_;
    size_ = other.size_;
    other.root_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename T>
BTree<T>::~BTree() {
  Clear(root_);
}

//* Методы класса

/**
 * @brief
 * Вставляет значение в множество.
 *
 * @tparam T Тип значения, которое будет вставлено.
 * @param value Значение, которое будет вставлено.
 * @return `true`, если значение было успешно вставлено, `false` в противном
 * случае.
 */
template <typename T>
std::pair<typename BTree<T>::const_iterator, bool> BTree<T>::insert(
    const_reference value, bool multi) {
  // Использование рекурсивного метода вставки.
  return Insert(root_, value, nullptr, multi);
}

template <typename T>
void BTree<T>::erase(iterator pos) {
  DeleteNode(pos.current_);
}

template <typename T>
void BTree<T>::swap(BTree& other) {
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
}

template <typename T>
void BTree<T>::merge(BTree& other) {
  BTree<T> tmp;
  for (auto it = other.begin(); it != other.end(); ++it) {
    if (!insert(*it).second) {
      tmp.insert(*it);
    }
  }
  other = std::move(tmp);
}

template <typename T>
typename BTree<T>::iterator BTree<T>::begin() const {
  return root_ ? BTreeIterator(FindMinNode(root_))
               : BTreeIterator(nullptr, true);
}

template <typename T>
typename BTree<T>::iterator BTree<T>::end() const {
  if (!root_) {
    return BTreeIterator(nullptr, true);
  }
  Node* node = root_;
  while (node->right != nullptr) {
    node = node->right;
  }
  return BTreeIterator(node, true);
}

template <typename T>
typename BTree<T>::iterator BTree<T>::find(const value_type& key) const {
  Node* node = FindNode(root_, key);
  return node ? BTreeIterator(node) : BTreeIterator(nullptr, true);
}

//* Вспомогательные приватные методы

template <typename T>
void BTree<T>::Clear(Node*& node) {
  if (node) {
    Clear(node->left);
    Clear(node->right);
    delete node;
  }
  node = nullptr;
  size_ = 0;
}

template <typename T>
template <typename K, typename V>  // map
bool BTree<T>::Compare(const std::pair<K, V>& value_1,
                       const std::pair<K, V>& value_2) const {
  if (value_1.first < value_2.first) return true;
  return false;
}

template <typename T>
template <typename V>
bool BTree<T>::Compare(const V& value_1, const V& value_2) const {
  if (value_1 < value_2) return true;
  return false;
}

/**
 * @brief Вставляет новый узел с заданным значением в множество.
 *
 * @tparam T Тип элементов в множестве.
 * @param node Ссылка на указатель на текущий обрабатываемый узел.
 * @param value Значение, которое нужно вставить в множество.
 * @param multi Разрешена ли вставка элементов с одинаковым значением

 */
template <typename T>
std::pair<typename BTree<T>::const_iterator, bool> BTree<T>::Insert(
    Node*(&node), const_reference value, Node* parent_node, bool multi) {
  auto res = std::make_pair(const_iterator(nullptr), false);
  if (node == nullptr) {
    Node* new_node = new Node(parent_node, value);
    node = new_node;
    res = std::make_pair(const_iterator(node), true);
    ++size_;
  } else {
    if (Compare(value, node->data)) {
      res = Insert(node->left, value, node, multi);
      Balance(node);
    } else if (Compare(node->data, value)) {
      res = Insert(node->right, value, node, multi);
      Balance(node);
    } else if (multi) {
      res = Insert(node->left, value, node, multi);
      Balance(node);
    }
  }
  return res;
}

template <typename T>
typename BTree<T>::Node* BTree<T>::FindNode(Node* node,
                                            const_reference value) const {
  while (node != nullptr) {
    if (Compare(value, node->data)) {
      node = node->left;
    } else if (Compare(node->data, value)) {
      node = node->right;
    } else {
      return node;
    }
  }
  return nullptr;
}

template <typename T>
void BTree<T>::DeleteNode(Node*& node) {
  if (!node) {
    return;
  }
  if (node->right) {
    Node* min_node = FindMinNode(node->right);
    node->data = min_node->data;
    DeleteNode(min_node);
  } else if (node->left) {
    // Если справа нет узла, то по свойству AVL дерева слева не может быть
    // больше одного узла
    node->data = node->left->data;
    DeleteNode(node->left);
  } else {
    Node* p = node->parent;
    if (p) {
      p->left == node ? p->left = nullptr : p->right = nullptr;
    } else {
      root_ = nullptr;
    }
    delete node;
    --size_;
    while (p) {
      Balance(p);
      if (p->parent == nullptr) {
        root_ = p;
      }
      p = p->parent;
    }
  }
}

template <typename T>
typename BTree<T>::Node* BTree<T>::FindMinNode(Node* node) const {
  if (node) {
    while (node->left != nullptr) {
      node = node->left;
    }
  }
  return node;
}

template <typename T>
int BTree<T>::Height(Node* node) const {
  return node ? node->height : 0;
}

template <typename T>
int BTree<T>::BalanceFactor(Node* node) const {
  return Height(node->right) - Height(node->left);
}

template <typename T>
void BTree<T>::FixHeight(Node* node) {
  int hl = Height(node->left);
  int hr = Height(node->right);
  node->height = (hl > hr ? hl : hr) + 1;
}

template <typename T>
typename BTree<T>::Node* BTree<T>::RotateRight(Node*(&node)) {
  Node* node2 = node->left;
  node->left = node2->right;
  if (node->left) {
    node->left->parent = node;
  }
  node2->right = node;
  node2->parent = node->parent;
  node->parent = node2;
  FixHeight(node);
  FixHeight(node2);
  return node2;
}

template <typename T>
typename BTree<T>::Node* BTree<T>::RotateLeft(Node*& node) {
  Node* node2 = node->right;
  node->right = node2->left;
  if (node->right) {
    node->right->parent = node;
  }
  node2->left = node;
  node2->parent = node->parent;
  node->parent = node2;
  FixHeight(node);
  FixHeight(node2);
  return node2;
}

template <typename T>
void BTree<T>::Balance(Node*& node) {
  FixHeight(node);
  if (BalanceFactor(node) == 2) {
    if (BalanceFactor(node->right) < 0) {
      node->right = RotateRight(node->right);
    }
    node = RotateLeft(node);
  } else if (BalanceFactor(node) == -2) {
    if (node->right && BalanceFactor(node->right) > 0) {
      node->right = RotateLeft(node->right);
    }
    node = RotateRight(node);
  }
}
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_SRC_BTREE_TPP_