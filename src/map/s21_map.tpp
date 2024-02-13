#ifndef CPP2_S21_CONTAINERS_SRC_MAP_TPP_
#define CPP2_S21_CONTAINERS_SRC_MAP_TPP_
namespace s21 {
// Map Element access
template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  auto it = this->find(std::make_pair(key, T()));
  if (it != this->end()) {
    return it.get_value().second;
  }
  throw std::out_of_range("Key not found in the map");
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  try {
    return this->at(key);
  } catch (const std::out_of_range& e) {
    auto it = this->insert(key, T()).first;
    return it.get_value().second;
  }
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const key_type& key, const mapped_type& obj) {
  return this->insert(std::make_pair(key, obj));
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const key_type& key, const mapped_type& obj) {
  auto value = std::make_pair(key, obj);
  auto res = insert(value);
  if (res.second == false) {
    this->erase(this->find(value));
    return insert(value);
  } else {
    return res;
  }
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_MAP_TPP_