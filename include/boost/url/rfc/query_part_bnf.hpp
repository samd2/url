//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/url
//

#ifndef BOOST_URL_QUERY_PART_BNF_HPP
#define BOOST_URL_QUERY_PART_BNF_HPP

#include <boost/url/detail/config.hpp>
#include <boost/url/error.hpp>
#include <boost/url/string.hpp>
#include <cstddef>

namespace boost {
namespace urls {

/** BNF for query-part

    @par BNF
    @code
    query-part      = [ "?" query ]

    query           = *( pchar / "/" / "?" )
    @endcode

    @see
        https://datatracker.ietf.org/doc/html/rfc3986#section-3.4
*/
struct query_part_bnf
{
    bool has_query;
    string_view query;
    std::size_t query_count;
    string_view query_part;

    BOOST_URL_DECL
    friend
    bool
    parse(
        char const*& it,
        char const* const end,
        error_code& ec,
        query_part_bnf& t);
};

} // urls
} // boost

#endif