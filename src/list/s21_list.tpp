// 1
#ifndef CPP2_S21_CONTAINERS_SRC_LIST_TPP_
#define CPP2_S21_CONTAINERS_SRC_LIST_TPP_
namespace s21 {
template <typename value_type>
list<value_type>::list()
    : first_(nullptr), last_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(value_type());
  end_->next = end_->prev = nullptr;
}

template <typename value_type>
list<value_type>::list(size_type n) : list() {
  if (!n) throw std::out_of_range("Index out of range");
  while (n) {
    --n;
    push_back(value_type());
  }
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const &items)
    : list() {
  for (auto i : items) {
    push_back(i);
  }
}

template <typename value_type>
list<value_type>::list(const list &l) : list() {
  Node *tmp = l.first_;

  for (size_type i = 0; i != l.size(); i++) {
    push_back(tmp->value);
    tmp = tmp->next;
  }
}

template <typename value_type>
list<value_type>::list(list &&other) {
  if (this != &other) {
    swap(other);
    other.first_ = other.last_ = other.end_ = nullptr;
    other.end_ = new Node(value_type());
    end_->next = end_->prev = nullptr;
    other.size_ = 0;
  }
}

template <typename value_type>
list<value_type>::~list() {
  while (size()) pop_front();
  delete end_;
}
template <typename value_type>
list<value_type> &list<value_type>::operator=(const list<value_type> &other) {
  if (this != &other) {
    clear();
    if (!end_) {
      end_ = new Node(value_type());
      end_->prev = end_->next = nullptr;
    }
    Node *tmp_node = other.first_;
    if (tmp_node)
      while (tmp_node != other.end_) {
        push_back(tmp_node->value);
        tmp_node = tmp_node->next;
      }
  }
  return *this;
}
template <typename value_type>
list<value_type> &list<value_type>::operator=(list<value_type> &&other) {
  if (this != &other) {
    list<value_type> tmp_lst(std::move(other));
    *this = tmp_lst;
  }
  return *this;
}
template <typename value_type>
const value_type &list<value_type>::front() const noexcept {
  return first_ ? first_->value : end_->value;
}

template <typename value_type>
const value_type &list<value_type>::back() const noexcept {
  return last_ ? last_->value : front();
}

template <typename value_type>
bool list<value_type>::empty() const noexcept {
  return first_ == nullptr;
}
template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() const noexcept {
  return size_;
}
template <typename value_type>
size_t list<value_type>::max_size() const noexcept {
  return ((std::numeric_limits<std::size_t>::max() / (sizeof(Node))));
}

template <typename value_type>
void list<value_type>::clear() noexcept {
  while (size()) {
    pop_front();
  }
}
template <typename value_type>
void list<value_type>::push_front(const value_type &data) {
  auto *new_ptr = new Node(data);
  if (empty()) {
    first_ = new_ptr;
    first_->prev = first_->next = end_;
    end_->prev = end_->next = first_;
  } else if (!last_) {
    last_ = first_;
    last_->next = end_;
    last_->prev = end_->next = first_ = new_ptr;
    end_->prev = new_ptr->next = last_;
  } else {
    new_ptr->next = first_;
    first_ = end_->next = new_ptr;
    first_->prev = end_;
  }
  ++size_;
  end_->value = size();
}

template <typename value_type>
void list<value_type>::push_back(const value_type &data) {
  if (empty()) {
    push_front(data);
    return;
  } else {
    auto *new_ptr = new Node(data);
    if (!last_) {
      last_ = new_ptr;
      last_->next = end_;
      last_->prev = first_;
      end_->prev = first_->next = last_;
    } else {
      new_ptr->prev = last_;
      last_->next = new_ptr;
      last_ = new_ptr;
      end_->prev = last_;
      last_->next = end_;
    }
    ++size_;
    end_->value = size();
  }
}

template <typename value_type>
void list<value_type>::pop_front() {
  if (!empty()) {
    Node *tmp = first_;
    first_ = (first_->next != end_) ? first_->next : nullptr;
    if (tmp->next) delete tmp;
    if (size() == 2) {
      first_ = end_->next = end_->prev = last_;
      first_->next = first_->prev = end_;
      last_ = nullptr;
    }
    --size_;
    end_->value = size();
  }
}

template <typename value_type>
void list<value_type>::pop_back() {
  if (size() == 1) {
    pop_front();
    return;
  }
  if (!empty()) {
    Node *tmp = last_;
    last_ = (last_->prev != end_) ? last_->prev : nullptr;
    if (tmp->prev) delete tmp;
    if (size() == 2) {
      end_->next = end_->prev = first_;
      first_->next = first_->prev = end_;
      last_ = nullptr;
    }

    --size_;
    end_->value = size();
  }
}

template <typename value_type>
void list<value_type>::swap(list &other) noexcept {
  std::swap(first_, other.first_);
  std::swap(last_, other.last_);
  std::swap(end_, other.end_);
  std::swap(size_, other.size_);
}

template <typename value_type>
void list<value_type>::sort() noexcept {
  if (size() == 0 || size() == 1) return;
  list ptr_;
  Node *p = first_;
  int flag = 0;
  while (!empty()) {
    p = p->next;
    if (p->value >= first_->value) {
      ptr_.push_back(first_->value);
      pop_front();
    } else {
      push_back(first_->value);
      pop_front();
      flag = 1;
    }
    if (size() == 1) {
      ptr_.push_back(first_->value);
      pop_front();
    }
  }
  while (!ptr_.empty()) {
    push_back(ptr_.first_->value);
    ptr_.pop_front();
  }
  if (flag == 1) sort();
}

template <typename value_type>
void list<value_type>::merge(list &other) noexcept {
  list merge_list;
  if (((empty() && other.empty()) && merge_list.empty()) ||
      (other.empty() && merge_list.empty()))
    return;
  if (!other.empty() && !empty()) {
    while (((!other.empty()) && size() > 0) ||
           ((!empty()) && other.size() > 0)) {
      if (first_->value < other.first_->value) {
        merge_list.push_back(first_->value);
        pop_front();
      } else {
        merge_list.push_back(other.first_->value);
        other.pop_front();
      }
    }
  }
  if ((other.empty() && !empty()) || (!empty() && other.empty()))
    transfer(merge_list);
  if (empty() && !other.empty()) other.transfer(merge_list);
  merge_list.transfer(*this);
}

template <typename value_type>
void list<value_type>::reverse() noexcept {
  list temp;
  while (!empty()) {
    temp.push_front(first_->value);
    pop_front();
  }
  temp.transfer(*this);
}

template <typename value_type>
void list<value_type>::unique() noexcept {
  if (empty() || size() == 1) return;
  list temp;
  while (size() > 1) {
    Node *p = first_;
    p = p->next;
    if (p->value != first_->value) {
      temp.push_back(first_->value);
      pop_front();
    } else {
      pop_front();
    }
  }
  temp.push_back(first_->value);
  pop_front();
  while (!empty()) pop_front();
  temp.transfer(*this);
}
template <typename value_type>
list<value_type>::iter::iter() noexcept {
  ptr_ = nullptr;
};

template <typename value_type>
list<value_type>::iter::iter(list::Node *node) noexcept : iter() {
  ptr_ = node;
};

template <typename value_type>
list<value_type>::iter::iter(const_iter &other) noexcept : iter() {
  ptr_ = other.ptr_;
};

template <typename value_type>
list<value_type>::iter::~iter() = default;
template <typename value_type>
bool list<value_type>::iter::operator!=(const iter &other) const noexcept {
  return ptr_ != other.ptr_;
}
template <typename value_type>
bool list<value_type>::iter::operator==(const iter &other) const noexcept {
  return ptr_ == other.ptr_;
}
template <typename value_type>
typename list<value_type>::iter &list<value_type>::iter::operator=(
    const iter &other) noexcept {
  if (this != &other) ptr_ = other.ptr_;
  return *this;
}
template <typename value_type>
typename list<value_type>::const_reference
list<value_type>::iter::operator*() noexcept {
  return ptr_->value;
}

template <typename value_type>
typename list<value_type>::iter list<value_type>::iter::operator++(
    int) noexcept {
  // iter tmp(*this);
  ptr_ = ptr_->next;
  return *this;
}
template <typename value_type>
typename list<value_type>::iter &list<value_type>::iter::operator++() noexcept {
  ptr_ = ptr_->next;
  return *this;
}
template <typename value_type>
typename list<value_type>::iter list<value_type>::iter::operator--(
    int) noexcept {
  iter tmp(*this);
  ptr_ = ptr_->prev;
  return tmp;
}
template <typename value_type>
typename list<value_type>::iter &list<value_type>::iter::operator--() noexcept {
  ptr_ = ptr_->prev;
  return *this;
}
template <typename value_type>
typename list<value_type>::iter list<value_type>::iter::operator+(
    size_type n) noexcept {
  while (n) {
    --n;
    operator++();
  }
  return *this;
}
template <typename value_type>
typename list<value_type>::iter list<value_type>::iter::operator-(
    size_type n) noexcept {
  while (n) {
    --n;
    operator--();
  }
  return *this;
}
template <typename value_type>
typename list<value_type>::iter list<value_type>::iter::operator+=(
    size_type n) noexcept {
  operator+(n);
  return *this;
}
template <typename value_type>
typename list<value_type>::iter list<value_type>::iter::operator-=(
    size_type n) noexcept {
  operator-(n);
  return *this;
}
template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() const noexcept {
  return first_ ? (iterator)first_ : (iterator)end_;
}
template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() const noexcept {
  return (iterator)end_;
}
template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  if ((pos.ptr_ == first_ && size() == 1) || empty()) {
    push_front(value);
    return (iterator)first_;
  }
  auto *new_node_ = new Node(value);
  Node *pos_node = pos.ptr_;
  Node *prevnode = pos_node->prev;
  new_node_->prev = prevnode;
  new_node_->next = pos_node;
  pos_node->prev = prevnode->next = new_node_;
  if (pos_node == end_)
    last_ = new_node_;
  else if (pos_node == first_)
    first_ = new_node_;
  ++size_;
  end_->value = size();
  return (iterator)new_node_;
}
template <typename value_type>
void list<value_type>::erase(iterator pos) noexcept {
  Node *ptr = pos.ptr_;
  if (empty()) return;
  if (pos.ptr_ == first_) {
    pop_front();
  } else if (pos.ptr_ == last_) {
    pop_back();
  } else {
    Node *prev = pos.ptr_->prev;
    Node *next = pos.ptr_->next;
    prev->next = next;
    next->prev = prev;
    ptr->next = ptr->prev = nullptr;
    delete ptr;
    --size_;
    end_->value = size();
  }
}
template <typename value_type>
void list<value_type>::splice(iterator pos, list &other) noexcept {
  if (this != &other) {
    for (auto it = other.begin(); it != other.end(); ++it) insert(pos, *it);
    other.clear();
  }
}
template <typename value_type>
template <typename... Args>
typename list<value_type>::iterator list<value_type>::emplace(iterator pos,
                                                              Args &&...args) {
  Node *pos_node = pos.ptr_;
  iterator it(pos_node);
  for (auto elem : {std::forward<Args>(args)...}) {
    insert(it, elem);
  }
  --it;

  return it;
}
template <typename value_type>
template <typename... Args>
void list<value_type>::emplace_back(Args &&...args) {
  for (auto elem : {std::forward<Args>(args)...}) {
    push_back(elem);
  }
}

template <typename value_type>
template <typename... Args>
void list<value_type>::emplace_front(Args &&...args) {
  for (auto elem : {std::forward<Args>(args)...}) {
    push_front(elem);
  }
}

template <typename value_type>
void list<value_type>::transfer(list &other) {
  while (!empty()) {
    other.push_back(first_->value);
    pop_front();
  }
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_LIST_TPP_