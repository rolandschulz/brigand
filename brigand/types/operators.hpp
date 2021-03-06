/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <brigand/types/integral_constant.hpp>

namespace std
{
template <typename T, T N>
brigand::integral_constant<T, -N> operator-(brigand::integral_constant<T, N> const &)
{
    return {};
}

template <typename T, T N>
brigand::integral_constant<T, ~N> operator~(brigand::integral_constant<T, N> const &)
{
    return {};
}

template <typename T, T N, T M>
brigand::integral_constant<T, N + M> operator+(brigand::integral_constant<T, N> const &,
                                               brigand::integral_constant<T, M> const &)
{
    return {};
}

template <typename T, T N, T M>
brigand::integral_constant<T, N & M> operator&(brigand::integral_constant<T, N> const &,
                                               brigand::integral_constant<T, M> const &)
{
    return {};
}

template <typename T, T N, T M>
brigand::integral_constant<T, N | M> operator|(brigand::integral_constant<T, N> const &,
                                               brigand::integral_constant<T, M> const &)
{
    return {};
}

template <typename T, T N, T M>
brigand::integral_constant<T, N ^ M> operator^(brigand::integral_constant<T, N> const &,
                                               brigand::integral_constant<T, M> const &)
{
    return {};
}

template <typename T, T N, T M>
brigand::integral_constant<T, N - M> operator-(brigand::integral_constant<T, N> const &,
                                               brigand::integral_constant<T, M> const &)
{
    return {};
}

template <typename T, T N, T M>
brigand::integral_constant<T, N * M> operator*(brigand::integral_constant<T, N> const &,
                                               brigand::integral_constant<T, M> const &)
{
    return {};
}

template <typename T, T N, T M>
brigand::integral_constant<T, N / M> operator/(brigand::integral_constant<T, N> const &,
                                               brigand::integral_constant<T, M> const &)
{
    return {};
}

template <typename T, T N, T M>
brigand::integral_constant<T, N % M> operator%(brigand::integral_constant<T, N> const &,
                                               brigand::integral_constant<T, M> const &)
{
    return {};
}
}
