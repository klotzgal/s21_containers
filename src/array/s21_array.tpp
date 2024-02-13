
#ifndef CPP2_S21_CONTAINERS_SRC_ARRAY_TPP_
#define CPP2_S21_CONTAINERS_SRC_ARRAY_TPP_

namespace s21 {

template <class value_type, std::size_t N>
array<value_type, N>::array(std::initializer_list<value_type> const &items) {
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    arr_[i] = *it;
    i++;
  }
}

template <class value_type, std::size_t N>
array<value_type, N>::array(const array &a) {
  for (size_type i = 0; i < m_size_; ++i) arr_[i] = a.arr_[i];
}

template <class value_type, std::size_t N>
array<value_type, N>::array(array &&a) noexcept {
  for (size_type i = 0; i < m_size_; ++i) arr_[i] = a.arr_[i];
}

template <class value_type, std::size_t N>
array<value_type, N> &array<value_type, N>::operator=(array &&a) noexcept {
  if (this != &a) {
    std::swap(m_size_, a.m_size_);
    std::copy(a.begin(), a.end(), arr_);
  }
  return *this;
}

template <class value_type, std::size_t N>
array<value_type, N> &array<value_type, N>::operator=(const array &a) noexcept {
  for (size_type i = 0; i < m_size_; ++i) arr_[i] = a.arr_[i];
  return *this;
}

template <class value_type, std::size_t N>
value_type array<value_type, N>::at(size_type i) {
  if (i >= m_size_) throw std::out_of_range("index is outside");
  return arr_[i];
}

template <class value_type, std::size_t N>
value_type &array<value_type, N>::operator[](int i) {
  if (i < 0 or (i >= (int)m_size_)) throw std::out_of_range("index is outside");
  return arr_[i];
}

template <class value_type, std::size_t N>
const value_type &array<value_type, N>::operator[](int i) const {
  if (i < 0 or i >= (int)m_size_) throw std::out_of_range("index is outside");
  return arr_[i];
}

template <class value_type, std::size_t N>
value_type &array<value_type, N>::front() {
  if (m_size_ == 0U) throw std::out_of_range("index is outside");
  return arr_[0];
}

template <class value_type, std::size_t N>
const value_type &array<value_type, N>::front() const {
  if (m_size_ == 0U) throw std::out_of_range("index is outside");
  return arr_[0];
}

template <class value_type, std::size_t N>
const value_type &array<value_type, N>::back() const {
  if (m_size_ == 0U) throw std::out_of_range("index is outside");
  return arr_[m_size_ - 1];
}

template <class value_type, std::size_t N>
value_type &array<value_type, N>::back() {
  if (m_size_ == 0U) throw std::out_of_range("index is outside");
  return arr_[m_size_ - 1];
}

template <class value_type, std::size_t N>
value_type *array<value_type, N>::data() {
  return (m_size_ == 0U) ? nullptr : arr_;
};

template <class value_type, std::size_t N>
const value_type *array<value_type, N>::begin() const noexcept {
  return arr_;
}

template <class value_type, std::size_t N>
value_type *array<value_type, N>::begin() noexcept {
  return arr_;
}

template <class value_type, std::size_t N>
value_type *array<value_type, N>::end() noexcept {
  return arr_ + m_size_;
}

template <class value_type, std::size_t N>
const value_type *array<value_type, N>::end() const noexcept {
  return arr_ + m_size_;
}

// template <class value_type, std::size_t N> bool array<value_type, N>::empty()
// {
//   if (m_size_ == 0)
//     return true;
//   else
//     return false;
// }

template <class value_type, std::size_t N>
bool array<value_type, N>::empty() const {
  if (m_size_ == 0)
    return true;
  else
    return false;
}

// template <class value_type, std::size_t N>
// size_t const array<value_type, N>::size() const {
//   return m_size_;
// }

template <class value_type, std::size_t N>
size_t array<value_type, N>::size() const {
  return m_size_;
}

// template <class value_type, std::size_t N>
// size_t array<value_type, N>::max_size() {
//   return size();
// }

template <class value_type, std::size_t N>
size_t array<value_type, N>::max_size() const {
  return size();
}

template <class value_type, std::size_t N>
void array<value_type, N>::swap(array &other) noexcept {
  value_type temp;
  for (size_type i = 0; i < size(); ++i) {
    temp = other.arr_[i];
    other.arr_[i] = arr_[i];
    arr_[i] = temp;
  }
}

template <class value_type, std::size_t N>
void array<value_type, N>::fill(const_reference value) {
  for (int i = 0; i < (int)m_size_; i++) {
    arr_[i] = value;
  }
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_SRC_ARRAY_TPP_