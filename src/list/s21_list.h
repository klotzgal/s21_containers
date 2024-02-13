// 1
#ifndef CPP2_S21_CONTAINERS_SRC_LIST_H_
#define CPP2_S21_CONTAINERS_SRC_LIST_H_

#include <iostream>
#include <limits>
namespace s21 {
template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 private:
  typedef struct Node {
    value_type value;
    Node *next;
    Node *prev;
    explicit Node(value_type value) noexcept
        : value(value), next(nullptr), prev(nullptr) {}
  } Node;

  Node *first_;
  Node *last_;
  Node *end_;
  size_type size_;
  /////////////////////////////////////////////////////////////
  // основные публичные методы для взаимодействия с классом: //
  /////////////////////////////////////////////////////////////

  // КОНСТРУКТОРЫ
 public:
  list();
  explicit list(
      size_type n);  // параметризованный конструктор, создает размера n
  list(std::initializer_list<value_type> const
           &items);  // Конструктор списка инициализаторов, создает список,
                     // инициализированный с использованием
                     // std::initializer_list<T
  list(const list &l);  // конструктор копирования
  list(list &&other);   // конструктор перемещения
  ~list();              // destructor
  list<T> &operator=(
      const list<value_type> &
          other);  //  Перегрузка оператора присваивания для движущегося объекта
  list<value_type> &operator=(list<value_type> &&other);
  /////////////////////////////////////////////////////
  // публичные методы для доступа к элементам класса://
  /////////////////////////////////////////////////////
  const_reference front() const noexcept;  // доступ к 1
  const_reference back() const noexcept;  // досттуп к последнему
  ///////////////////////////////////////////////////////////////////////////
  //   публичные методы для доступа к информации о наполнении контейнера: ///
  ///////////////////////////////////////////////////////////////////////////
  bool empty() const noexcept;  // проверяет, пуст ли контейнер
  size_type size() const noexcept;  // возвращает количество элементов
  size_type max_size()
      const noexcept;  // возвращает максимально возможное количество элементов
  ///////////////////////////////////////////////////////////////////////////
  //           публичные методы для изменения контейнера:                 ///
  ///////////////////////////////////////////////////////////////////////////
  void clear() noexcept;                  // очищает содержимое
  void push_front(const_reference data);  // добавляет элемент в начало
  void push_back(const_reference data);  // добавляет элемент в конец
  void pop_front();                      // удаляет первый
  void pop_back();  // удаляет последний элемет
  void swap(list &other) noexcept;  // меняет содержимое
  void sort() noexcept;             // Сортирует
  void merge(list &other) noexcept;  // объединяет два отсортированных списка
  void reverse() noexcept;  // меняет порядок элементов
  void unique() noexcept;  // удаляет последовательные повторяющиеся элементы

 private:
  class iter {
   public:
    using const_iter = const iter;
    Node *ptr_;
    iter() noexcept;
    explicit iter(list::Node *node) noexcept;
    iter(const_iter &other) noexcept;
    ~iter();
    ////////////////////////////////////////////////////////////////////
    //           Перегруженные операторы                             ///
    ////////////////////////////////////////////////////////////////////
    bool operator!=(const_iter &other) const noexcept;
    bool operator==(const_iter &other) const noexcept;
    iter &operator=(const_iter &other) noexcept;
    const_reference operator*() noexcept;
    iter operator++(int) noexcept;
    iter &operator++() noexcept;
    iter operator--(int) noexcept;
    iter &operator--() noexcept;
    iter operator+(size_type n) noexcept;
    iter operator-(size_type n) noexcept;
    iter operator+=(size_type n) noexcept;
    iter operator-=(size_type n) noexcept;
  };  // iter

 public:
  using iterator = iter;
  //////////////////////////////////////////////////////////////////////
  // публичные методы для итерирования по элементам класса (доступ к ///
  // итераторам):                                                    ///
  //////////////////////////////////////////////////////////////////////
  iterator begin() const noexcept;  // возвращает итератор в начало
  iterator end() const noexcept;  // возвращает итератор до конца
  //////////////////////////////////////////////////////////////////////
  //           публичные методы для изменения контейнера:            ///
  //////////////////////////////////////////////////////////////////////
  iterator insert(iterator pos,
                  const_reference value);  // вставляет элементы в конкретную
                                           // позицию и возвращает итератор,
                                           // указывающий на новый элемент
  void erase(iterator pos) noexcept;  // стирает элемент в позиции
  void splice(iterator pos,
              list &other) noexcept;  // переносит элементы из списка других,
  template <typename... Args>
  iterator emplace(iterator pos, Args &&...args);
  template <typename... Args>
  void emplace_back(Args &&...args);
  template <typename... Args>
  void emplace_front(Args &&...args);

 private:
  void transfer(list &other);
};  // List

}  // namespace s21
#include "s21_list.tpp"
#endif  // CPP2_S21_CONTAINERS_SRC_LIST_H_