#ifndef CPP2_S21_CONTAINERS_SRC_ARRAY_H_
#define CPP2_S21_CONTAINERS_SRC_ARRAY_H_

#include <iostream>
namespace s21 {
template <class T, std::size_t N>
class array {
 private:
  size_t m_size_ = N;
  T arr_[N];

 public:
  ////////////////////////////////////////////////////////
  //          внутриклассовые переопределения типов     //
  //        (типичные для стандартной библиотеки STL),  //
  //    принятые для удобства восприятия кода класса:   //
  ////////////////////////////////////////////////////////
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  /////////////////////////////////////////////////////////////
  // основные публичные методы для взаимодействия с классом: //
  /////////////////////////////////////////////////////////////
 public:
  // конструкторы
  //  по умолчанию
  array() noexcept : m_size_{N} {}
  // Конструктор списка инициализаторов, создает массив, инициализированный с
  // использованием std::initializer_list<T>
  array(std::initializer_list<value_type> const &items);
  // конструктор копирования с упрощенным синтаксисом
  array(const array &a);
  // конструктор перемещения
  array(array &&a) noexcept;
  // destructor
  ~array() noexcept = default;
  //  Перегрузка оператора присваивания для движущегося объекта
  array &operator=(array &&a) noexcept;
  array &operator=(const array &a) noexcept;
  /////////////////////////////////////////////////////
  // публичные методы для доступа к элементам класса://
  /////////////////////////////////////////////////////
  value_type at(
      size_type i);  // доступ к указанному элементу с проверкой границ
  reference operator[](
      int i);  // доступ к указанному элементу с проверкой границ
  const_reference operator[](
      int i) const;  // доступ к указанному элементу с проверкой границ
  reference front();              // доступ к 1
  const_reference front() const;  // доступ к 1
  const_reference back() const;   // досттуп к последнему
  reference back();               // досттуп к последнему
  iterator data();  // прямой доступ к базовому массиву
  ////////////////////////////////////////////////////////////////////
  // публичные методы для итерирования по элементам класса (доступ к//
  // итераторам):                                                   //
  ////////////////////////////////////////////////////////////////////
  const_iterator begin() const noexcept;  // возвращает итератор в начало
  iterator begin() noexcept;  // возвращает итератор в начало
  iterator end() noexcept;  // возвращает итератор до конца
  const_iterator end() const noexcept;  // возвращает итератор до конца
  /////////////////////////////////////////////////////////////////////////
  //   публичные методы для доступа к информации о наполнении контейнера://
  /////////////////////////////////////////////////////////////////////////
  bool empty() const;  // проверяет, пуст ли
  // const bool  empty() const; // проверяет, пуст ли
  // size_type const size() const; // возвращает количество элементов
  size_type size() const;  // возвращает количество элементов
  // size_type max_size(); // возвращает максимально возможное количество
  // элементов
  size_type max_size()
      const;  // возвращает максимально возможное количество элементов
  void swap(array &other) noexcept;  // swaps the contents  меняет содержимое
  void fill(const_reference value);  // Присваивает заданное значение всем
                                     // элементам контейнера
};
}  // namespace s21
#include "s21_array.tpp"
#endif  // CPP2_S21_CONTAINERS_SRC_ARRAY_H_
