#ifndef CPP2_S21_CONTAINERS_SRC_BTREE_H_
#define CPP2_S21_CONTAINERS_SRC_BTREE_H_

#include <iostream>
#include <limits>
#include <utility>

namespace s21 {

template <typename T>
class BTree {
  //* Предварительное объявление
  struct Node;
  class BTreeIterator;

 public:
  //* Конструкторы
  using key_type = T;
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = BTree<T>::BTreeIterator;
  using const_iterator = const BTree<T>::BTreeIterator;
  using size_type = size_t;

  //* Конструкторы и деструктор
  BTree();
  explicit BTree(std::initializer_list<T> const& init);
  BTree(const BTree& other);
  BTree(BTree&& other) noexcept;
  BTree& operator=(const BTree& other);
  BTree& operator=(BTree&& other) noexcept;
  ~BTree();
  //* Методы класса
  //? Iterators
  iterator begin() const;
  iterator end() const;

  //? Capacity
  bool empty() const { return root_ == nullptr; }
  size_type size() const { return size_; }
  size_type max_size() const { return std::numeric_limits<std::size_t>::max(); }

  //? Modifiers
  void clear() { Clear(root_); }
  std::pair<const_iterator, bool> insert(const_reference value,
                                         bool multi = false);
  void erase(iterator pos);
  void swap(BTree& other);
  void merge(BTree& other);

  //? Lookup
  iterator find(const value_type& key) const;
  bool contains(const key_type& key) const {
    return FindNode(root_, key) != nullptr;
  }

 protected:
  Node* root_;
  size_type size_;

  //* Вспомогательные приватные методы
  template <typename K, typename V>
  bool Compare(const std::pair<K, V>& value_1,
               const std::pair<K, V>& value_2) const;

  template <typename V>
  bool Compare(const V& value_1, const V& value_2) const;

  std::pair<const_iterator, bool> Insert(Node*& node, const_reference value,
                                         Node* parentnode = nullptr,
                                         bool multi = false);
  Node* FindNode(Node* node, const_reference value) const;
  void DeleteNode(Node*& node);
  Node* FindMinNode(Node* node) const;
  void Clear(Node*& node);
  //? Для балансировки
  int Height(Node* node) const;
  int BalanceFactor(Node* node) const;
  void FixHeight(Node* node);
  Node* RotateRight(Node*& node);
  Node* RotateLeft(Node*& node);
  void Balance(Node*& node);

 private:
  struct Node {
    T data;
    Node* left;
    Node* right;
    Node* parent;
    int height;

    /**
     * @brief Дефолтный конструктор узла.
     *
     */
    Node()
        : data(0), left(nullptr), right(nullptr), parent(nullptr), height(0) {}

    /**
     * @brief Конструктор узла с двумя параметрами.
     * Высота созданного узла = высота родительского + 1.
     *
     * @param parent
     * Родительский узел.
     * @param value
     * Значение типа T.
     */
    Node(Node* parent, T value)
        : data(value),
          left(nullptr),
          right(nullptr),
          parent(parent),
          height(1) {}
    ~Node() = default;
    Node& operator=(const Node& other) = default;
    Node(const Node& other) = default;
  };
  class BTreeIterator {
   public:
    explicit BTreeIterator(Node* node) : current_(node), end_(false){};
    explicit BTreeIterator(Node* node, bool end) : current_(node), end_(end){};
    BTreeIterator(const BTreeIterator& other);
    BTreeIterator& operator=(const BTreeIterator& other);
    // T& operator*() { return current_->data ; }
    T operator*() const { return current_ ? current_->data : value_type(); }
    BTreeIterator& operator++();
    BTreeIterator& operator++(int);
    BTreeIterator& operator--();
    BTreeIterator& operator--(int);
    bool operator==(const BTreeIterator& other) const;
    bool operator!=(const BTreeIterator& other) const;
    value_type& get_value();

   private:
    Node* current_;
    bool end_;
  };
};

}  // namespace s21

#include "s21_btree.tpp"
#include "s21_btree_iterator.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_BTREE_H_
