
#include <brigand/map.hpp>

namespace brigand
{
namespace detail
{
    // at
    template <int Index, class First, class... T>
    struct element_at
    {
        using type = typename element_at<Index - 1, T...>::type;
    };

    template <class First, class... T>
    struct element_at<0, First, T...>
    {
        using type = First;
    };

    template <int Index, class L> struct at_impl;

    template<int Index, template<class...> class L, class... U>
    struct at_impl<Index, L<U...>>
    {
        using type = typename element_at<Index, U...>::type;
    };
}

    template <class L, int Index>
    using at_c = typename detail::at_impl<Index, L>::type;

namespace detail
{
    template <typename T>
    struct has_at_method
    {
        struct dummy {};

        template <typename C, typename P>
        static auto test(P * p) -> decltype(std::declval<C>().at(*p), std::true_type());

        template <typename, typename>
        static std::false_type test(...);

        typedef decltype(test<T, dummy>(nullptr)) type;
        static const bool value = std::is_same<std::true_type, decltype(test<T, dummy>(nullptr))>::value;
    };

    template <class L, typename Index, bool>
    struct at_dispatch 
    {
        using type = typename at_c<L, Index::value>::type;
    };

    template <class L, typename Index>
    struct at_dispatch<L, Index, true>
    {
        using type = typename lookup<L, Index>::type;
    };
}

    template <class Seq, typename K>
    struct at
    {
        using type = typename detail::at_dispatch<Seq, K, detail::has_at_method<Seq>::value>::type;
    };

}
