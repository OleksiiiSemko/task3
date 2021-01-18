#include "Wrapper.h"

template<typename F>
void task3::Wrapper::impl_type<F>::call() {
    f();
}

void task3::Wrapper::operator()() {
    impl->call();
}