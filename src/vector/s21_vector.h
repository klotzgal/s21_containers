#ifndef SRC_S21_VECTOR_H_
#define SRC_S21_VECTOR_H_
#include <iostream>
#include <limits>
#include <memory>
namespace s21 {
template <class T>
class vector {
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

 private:
  size_t m_size_;
  size_t m_capacity_;
  T *arr_;
  /////////////////////////////////////////////////////////////
  // основные публичные методы для взаимодействия с классом:  //
  /////////////////////////////////////////////////////////////
  // конструкторы
 public:
  vector();  // конструктор по умолчанию, создает пустой вектор
  explicit vector(
      size_type n);  // параметризованный конструктор, создает вектор размера n
  vector(std::initializer_list<value_type> const
             &items);  // Конструктор списка инициализаторов, создает вектор,
                       // инициализированный с использованием
                       // std::initializer_list<T>
  vector(const vector &v);      // конструктор копирования
  vector(vector &&v) noexcept;  // конструктор перемещения
  ~vector();                    // destructor
  vector &operator=(vector &&v) noexcept;  //  Перегрузка оператора присваивания
                                           //  для движущегося объекта
  vector &operator=(const vector &v) noexcept;
  /////////////////////////////////////////////////////
  // публичные методы для доступа к элементам класса://
  /////////////////////////////////////////////////////
  value_type at(
      size_type i);  // доступ к указанному элементу с проверкой границ
  const value_type operator[](int i) const;  // доступ к указанному элементу
  value_type operator[](int i);  // доступ к указанному элементу
  reference front();             // доступ к 1
  const_reference front() const;  // доступ к 1
  const_reference back() const;   // досттуп к последнему
  reference back();               // досттуп к последнему
  iterator data();  // прямой доступ к базовому массиву
  /////////////////////////////////////////////////////////////////////////////////
  // публичные методы для итерирования по элементам класса (доступ к
  // итераторам):///
  /////////////////////////////////////////////////////////////////////////////////
  const_iterator begin() const noexcept { return arr_; }
  iterator begin() noexcept { return arr_; }  // |возвращает итератор в начало
  iterator end() noexcept {
    return arr_ + m_size_;
  }  // возвращает итератор до конца
  const_iterator end() const noexcept { return arr_ + m_size_; }
  /////////////////////////////////////////////////////////////////////////////////
  //   публичные методы для доступа к информации о наполнении контейнера: ///
  /////////////////////////////////////////////////////////////////////////////////
  bool empty() const;  // проверяет, пуст ли контейнер
  // bool const empty() const; // проверяет, пуст ли контейнер
  // size_type const size() const;
  size_type size() const;  // возвращает количество элементов
  size_type max_size()
      const;  // возвращает максимально возможное количество элементов
  // size_type
  // max_size() const; // возвращает максимально возможное количество элементов
  void reserve(
      size_type size);  // выделяет хранилище элементов размера и копирует
                        // текущие элементы массива в вновь выделенный массив
  size_type capacity()
      const;  // возвращает количество элементов, которые могут храниться
              // в выделенном на данный момент хранилище
  // size_type capacity(); // возвращает количество элементов, которые могут
  //                       // храниться в выделенном на данный момент хранилище
  void shrink_to_fit();  // уменьшает использование памяти за счет освобождения
                         //  неиспользуемой памяти

  /////////////////////////////////////////////////////////////////////////////////
  //           публичные методы для изменения контейнера: ///
  /////////////////////////////////////////////////////////////////////////////////
  void clear();  // очищает содержимое
  // вставляет элементы в конкретную позицию и возвращает итератор, указывающий
  // на новый элемент
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);  // стирает элемент в позиции
  void push_back(value_type v);  // добавляет элемент в конец
  void pop_back();           // удаляет последний элемет
  void swap(vector &other);  // swaps the contents  меняет содержимое
  template <typename... Args>
  constexpr iterator emplace(const_iterator pos, Args &&...args);
  template <typename... Args>
  constexpr iterator emplace_back(Args &&...args);

 private:
  //////////////////////////////////////////
  //            доп. функции              //
  //////////////////////////////////////////
  void reserve_more_capacity(size_type size);
  void reverse();
};

}  // namespace s21
#include "s21_vector.tpp"
#endif  // SRC_S21_VECTOR_H_
