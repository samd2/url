//
// Copyright (c) 2016-2019 Damian Jarek (damian dot jarek93 at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

#ifndef BOOST_URL_GRAMMAR_TOKEN_HPP
#define BOOST_URL_GRAMMAR_TOKEN_HPP

#include <boost/url/detail/config.hpp>
#include <boost/url/grammar/charset.hpp>
#include <boost/url/error.hpp>
#include <boost/url/string_view.hpp>
#include <boost/static_assert.hpp>

namespace boost {
namespace urls {
namespace grammar {

/** BNF for a series of characters in a char set
*/
template<class CharSet>
struct token
{
    using value_type = string_view;

    value_type&
    operator*() noexcept
    {
        return s_;
    }

    value_type*
    operator->() noexcept
    {
        return &**this;
    }

    friend
    bool
    parse(
        char const*& it,
        char const* end,
        error_code& ec,
        token& t) noexcept
    {
        ec = {};
        auto const start = it;
        static constexpr CharSet cs{};
        it = grammar::find_if_not(it, end, cs);
        t.s_ = string_view(start, it - start);
        return true;
    }

private:
    BOOST_STATIC_ASSERT(
        is_charset<
            CharSet>::value);

    value_type s_;
};

} // bnf
} // urls
} // boost

#endif