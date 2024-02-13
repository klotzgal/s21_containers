#ifndef CPP2_S21_CONTAINERS_SRC_VECTOR_TPP_
#define CPP2_S21_CONTAINERS_SRC_VECTOR_TPP_

namespace s21 {

template <typename value_type>
vector<value_type>::vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr) {}

template <typename value_type>
vector<value_type>::vector(typename s21::vector<value_type>::size_type n)
    : m_size_(n), m_capacity_(n), arr_(n ? new value_type[n] : nullptr) {}

template <typename value_type>
vector<value_type>::vector(std::initializer_list<value_type> const &items) {
  arr_ = new value_type[items.size()];
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    arr_[i] = *it;
    i++;
  }
  m_size_ = items.size();
  m_capacity_ = items.size();
}

template <typename value_type>
vector<value_type>::vector(const vector &v)
    : m_size_(v.m_size_), m_capacity_(v.m_capacity_) {
  arr_ = nullptr;
  if (m_size_ > 0) arr_ = new value_type[m_capacity_];
  std::copy(v.begin(), v.end(), arr_);
}

template <typename value_type>
vector<value_type>::vector(vector &&v) noexcept
    : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_) {
  v.arr_ = nullptr;
  v.m_size_ = 0;
  v.m_capacity_ = 0;
}

template <typename value_type>
vector<value_type>::~vector() {
  delete[] arr_;
  m_size_ = 0U;
  m_capacity_ = 0U;
  arr_ = nullptr;
}

template <typename value_type>
typename s21::vector<value_type> &vector<value_type>::operator=(
    vector &&v) noexcept {
  if (this != &v) {
    std::swap(m_size_, v.m_size_);
    std::swap(m_capacity_, v.m_capacity_);
    std::swap(arr_, v.arr_);
  }

  return *this;
}

template <typename value_type>
typename s21::vector<value_type> &vector<value_type>::operator=(
    const vector &v) noexcept {
  m_size_ = v.m_size_;
  m_capacity_ = v.m_capacity_;
  arr_ = nullptr;
  if (m_size_ > 0) arr_ = new value_type[m_capacity_];
  std::copy(v.begin(), v.end(), arr_);

  return *this;
}

template <typename value_type>
value_type vector<value_type>::at(size_type i) {
  if (((int)i >= (int)m_size_)) throw std::out_of_range("index is outside");
  return arr_[i];
}

template <typename value_type>
const value_type vector<value_type>::operator[](int i) const {
  if (i < 0 or (i >= (int)m_size_)) throw std::out_of_range("index is outside");

  return arr_[i];
}

template <typename value_type>
value_type vector<value_type>::operator[](int i) {
  if (i < 0 or (i >= (int)m_size_)) throw std::out_of_range("index is outside");
  return arr_[i];
}

template <typename value_type>
typename s21::vector<value_type>::reference vector<value_type>::front() {
  if (m_size_ == 0U) throw std::out_of_range("index is outside");
  return arr_[0];
}

template <typename value_type>
typename s21::vector<value_type>::const_reference vector<value_type>::front()
    const {
  if (m_size_ == 0U) throw std::out_of_range("index is outside");
  return arr_[0];
}

template <typename value_type>
typename s21::vector<value_type>::const_reference vector<value_type>::back()
    const {
  if (m_size_ == 0U) throw std::out_of_range("index is outside");
  return arr_[m_size_ - 1];
}

template <typename value_type>
typename s21::vector<value_type>::reference vector<value_type>::back() {
  if (m_size_ == 0U) throw std::out_of_range("index is outside");
  return arr_[m_size_ - 1];
}

template <typename value_type>
typename s21::vector<value_type>::iterator vector<value_type>::data() {
  return arr_;
};

template <typename value_type>
bool vector<value_type>::empty() const {
  return (m_size_ == 0) ? true : false;
}

// template <typename value_type> bool const vector<value_type>::empty() const {
//   return (m_size_ == 0) ? true : false;
// }

// template <typename value_type>
// typename s21::vector<value_type>::size_type const
// vector<value_type>::size() const {
//   return m_size_;
// }

template <typename value_type>
typename s21::vector<value_type>::size_type vector<value_type>::size() const {
  return m_size_;
}  // возвращает количество элементов

// template <typename value_type>
// typename s21::vector<value_type>::size_type vector<value_type>::max_size() {
//   return (std::numeric_limits<std::size_t>::max() / sizeof(value_type)) / 2;
// }

template <typename value_type>
typename s21::vector<value_type>::size_type vector<value_type>::max_size()
    const {
  return (std::numeric_limits<std::size_t>::max() / sizeof(value_type)) / 2;
}

template <typename value_type>
void vector<value_type>::reserve(size_type size) {
  if (size <= m_capacity_) return;
  value_type *newarr_ =
      reinterpret_cast<value_type *>(new int[size * sizeof(value_type)]);
  //   size_t i = 0;
  try {
    std::uninitialized_copy(arr_, arr_ + m_size_, newarr_);
  } catch (...) {
    delete[] reinterpret_cast<int8_t *>(newarr_);
    throw;
  }
  for (size_t i = 0; i < m_size_; ++i) (arr_ + i)->~value_type();
  delete[] reinterpret_cast<int8_t *>(arr_);
  arr_ = newarr_;
  m_capacity_ = size;
}

template <typename value_type>
typename s21::vector<value_type>::size_type vector<value_type>::capacity()
    const {
  return m_capacity_;
}

// template <typename value_type>
// typename s21::vector<value_type>::size_type vector<value_type>::capacity() {
//   return m_capacity_;
// }
template <typename value_type>
void vector<value_type>::shrink_to_fit() {
  if (m_size_ == m_capacity_) return;
  while (m_size_ != m_capacity_) {
    (arr_ + m_capacity_)->~value_type();
    m_capacity_ = m_capacity_ - 1;
  }
}

template <typename value_type>
void vector<value_type>::clear() {
  m_size_ = 0;
}

template <typename value_type>
typename s21::vector<value_type>::iterator vector<value_type>::insert(
    iterator pos, const_reference value) {
  size_type index = pos - begin();
  reserve(m_size_ + 1);
  ++m_size_;
  if (index < m_size_ - 1) {
    for (size_type i = m_size_ - 1; i > index; --i) arr_[i] = arr_[i - 1];
  }
  arr_[index] = value;
  return begin() + index;
}

template <typename value_type>
void vector<value_type>::erase(iterator pos) {
  size_type index = pos - begin();
  if (m_size_ > 0U && index < m_size_) {
    for (size_type i = index; i < m_size_ - 1; ++i) {
      arr_[i] = arr_[i + 1];
    }
    --m_size_;
    shrink_to_fit();
  }
}

template <typename value_type>
void vector<value_type>::push_back(value_type v) {
  if (m_capacity_ == 0U)
    reserve(1);
  else if (m_size_ == m_capacity_)
    reserve_more_capacity(m_size_ * 2);
  arr_[m_size_] = v;
  ++m_size_;
}

template <typename value_type>
void vector<value_type>::pop_back() {
  if (m_size_ > 0) {
    --m_size_;
    (arr_ + m_size_)->~value_type();
  }
}

template <typename value_type>
void vector<value_type>::swap(vector &other) {
  std::swap(m_size_, other.m_size_);
  std::swap(m_capacity_, other.m_capacity_);
  std::swap(arr_, other.arr_);
}

template <typename value_type>
template <typename... Args>
constexpr typename s21::vector<value_type>::iterator
vector<value_type>::emplace(const_iterator pos, Args &&...args) {
  iterator iter = (iterator)pos;
  auto position = pos - begin();
  vector temp{args...};
  int t = temp.size();
  temp.reverse();
  reserve_more_capacity(capacity() + sizeof...(args));
  //   int i = 0;
  for (int i = 0; i < (int)t; i++) {
    // for (auto &&item : {std::forward<Args>(args)...}) {
    //  temp.arr_[i]
    // if (temp.arr_[i] != item+1 )
    // std:: cout<<"\n"<<&item<<" "<< item<<"   "<<temp.arr_[i] <<"\n";
    //    temp.arr_[i] = item;
    iter = insert(begin() + position, temp.arr_[i]);

    // i++;
  }
  return iter;
}

template <typename value_type>
template <typename... Args>
constexpr typename s21::vector<value_type>::iterator
vector<value_type>::emplace_back(Args &&...args) {
  for (auto &&item : {std::forward<Args>(args)...}) push_back(item);
  return end() - 1;
}

template <typename value_type>
void vector<value_type>::reserve_more_capacity(size_type size) {
  if (size > m_capacity_) {
    value_type *buff = new value_type[size];
    for (size_t i = 0; i < m_size_; ++i) buff[i] = std::move(arr_[i]);
    delete[] arr_;
    arr_ = buff;
    m_capacity_ = size;
  }
}
template <typename value_type>
void vector<value_type>::reverse() {
  vector temp(size());
  int size_ = size();
  int j = size() - 1;
  for (int i = 0; i < size_; i++) {
    temp.arr_[i] = arr_[j];
    j--;
  }
  swap(temp);
}
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_SRC_VECTOR_TPP_