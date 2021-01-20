#ifndef TASK3_WRAPPER_H
#define TASK3_WRAPPER_H
#include <memory>

namespace task3 {

    class Wrapper {
    public:
        Wrapper() = default;

        template<typename F>
        Wrapper(F&& f) :
                impl{std::make_unique<impl_type<F>>(impl_type<F>(std::move(f)))}
        {}

        Wrapper(Wrapper&& other):
                impl(std::move(other.impl))
        {}

        Wrapper& operator=(Wrapper&& other)
        {
            impl=std::move(other.impl);
            return *this;
        }

        void operator()() {
            impl->call();
        }
    private:
        struct impl_base {
            virtual void call() = 0;
            virtual ~impl_base() = default;
        };

        template<typename F>
        struct impl_type : impl_base {
            F f;
            explicit impl_type(F&& f_) : f{std::move(f_)} {};
            void call() override {
                f();
            };
        };
        std::unique_ptr<impl_base> impl;
    };
}

#endif //TASK3_WRAPPER_H
