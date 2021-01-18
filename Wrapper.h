#ifndef TASK3_WRAPPER_H
#define TASK3_WRAPPER_H
#include <memory>

namespace task3 {

    class Wrapper {
    public:
        template<typename F>
        explicit Wrapper(F&& f) :
                impl{std::make_unique<impl_type<F>>(std::move(f))}
        {}
        Wrapper() = default;
        void operator()();
    private:
        struct impl_base {
            virtual void call() = 0;
            virtual ~impl_base() = default;
        };
        std::unique_ptr<impl_base> impl;

        template<typename F>
        struct impl_type : impl_base {
            F f;
            explicit impl_type(F&& f_) : f{std::move(f_)} {};
            void call();
        };
    };
}

#endif //TASK3_WRAPPER_H
