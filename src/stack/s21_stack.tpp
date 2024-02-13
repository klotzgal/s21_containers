#ifndef CPP2_S21_CONTAINERS_SRC_STACK_TPP_
#define CPP2_S21_CONTAINERS_SRC_STACK_TPP_

namespace s21 {
template <class T, class Container>
stack<T, Container>::stack() : container_() {};

template <class T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const &items) : container_(items) {};

template <class T, class Container>
stack<T, Container>::stack(const stack &s) : container_(s.container_) {};

template <class T, class Container>
stack<T, Container>::stack(stack &&s) : container_(std::move(s.container_)) {};

template <class T, class Container>
stack<T, Container>::~stack() {}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(const stack &s) {
    if (this != &s) {
        container_ = s.container_;
    }
    return *this;
}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(stack &&s) {
    if (this != &s) {
        container_ = std::move(s.container_);
    }
    return *this;
}

template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() 
    const {
    return container_.back();
}

template <class T, class Container>
bool stack<T, Container>::empty() const noexcept {
    return container_.empty();
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size()
    const noexcept {
        return container_.size();
    }

template <class T, class Container>
void stack<T, Container>::push(const_reference value) {
    container_.push_back(value);
}

template <class T, class Container>
void stack<T, Container>::push(value_type&& value) {
    container_.push_back(std::move(value));
}

template <class T, class Container>
void stack<T, Container>::pop() {
    container_.pop_back();
}

template <class T, class Container>
void stack<T, Container>::swap(stack& s) {
    container_.swap(s.container_);
}

};  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_STACK_TPP_