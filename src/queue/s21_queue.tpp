#ifndef CPP2_S21_CONTAINERS_SRC_QUEUE_TPP_
#define CPP2_S21_CONTAINERS_SRC_QUEUE_TPP_


namespace s21 {

template <class T, class Container>
queue<T, Container>::queue() : container_() {};

template <class T, class Container>
queue<T, Container>::queue(std::initializer_list<value_type> const &items) : container_(items) {};

template <class T, class Container>
queue<T, Container>::queue(const queue& q) : container_(q.container_) {}

template <class T, class Container>
queue<T, Container>::queue(queue&& q) : container_(std::move(q.container_)) {}

template <class T, class Container>
queue<T, Container>::~queue() {}

template <class T, class Container>
queue<T, Container>& queue<T, Container>::operator=(const queue &q) {
    if (this != &q) {
        container_ = q.container_;
    }
    return *this;
}

template <class T, class Container>
queue<T, Container>& queue<T, Container>::operator=(queue &&q) {
    if (this != &q) {
        container_ = std::move(q.container_);
    }
    return *this;
}

template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::front()
    const noexcept {
    return container_.front();
}

template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::back()
    const noexcept {
    return container_.back();
}

template <class T, class Container>
bool queue<T, Container>::empty() const noexcept {
    return container_.empty();
}

template <class T, class Container>
typename queue<T, Container>::size_type queue<T, Container>::size()
    const noexcept {
        return container_.size();
    }

template <class T, class Container>
void queue<T, Container>::push(const_reference value) {
    container_.push_back(value);
}

template <class T, class Container>
void queue<T, Container>::push(value_type&& value) {
    container_.push_back(std::move(value));
}

template <class T, class Container>
void queue<T, Container>::pop() {
    container_.pop_front();
}

template <class T, class Container>
void queue<T, Container>::swap(queue& q) {
    container_.swap(q.container_);
}

};  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_QUEUE_TPP_