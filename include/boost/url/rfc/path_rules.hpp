//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/url
//

#ifndef BOOST_URL_RFC_PATH_RULES_HPP
#define BOOST_URL_RFC_PATH_RULES_HPP

#include <boost/url/detail/config.hpp>
#include <boost/url/error_code.hpp>
#include <boost/url/grammar/char_rule.hpp>
#include <boost/url/grammar/not_empty_rule.hpp>
#include <boost/url/grammar/range_rule.hpp>
#include <boost/url/grammar/sequence_rule.hpp>
#include <boost/url/rfc/pchars.hpp>
#include <boost/url/rfc/pct_encoded_rule.hpp>
#include <boost/url/rfc/detail/path_rules.hpp>
#include <cstddef>

namespace boost {
namespace urls {

/** Rule for path-abempty grammar

    @par BNF
    @code
    path-abempty  = *( "/" segment )
    @endcode

    @par Specification
    @li <a href="https://datatracker.ietf.org/doc/html/rfc3986#section-3.3"
        >3.3. Path (rfc3986)</a>
*/
#ifdef BOOST_URL_DOCS
constexpr __implementation_defined__ path_abempty_rule;
#else
constexpr auto path_abempty_rule =
    grammar::range_rule(
        grammar::sequence_rule(
            grammar::char_rule('/'),
            detail::segment_rule));
#endif

//------------------------------------------------

/** Rule for path-absolute grammar.

    @par BNF
    @code
    path-absolute = "/" [ segment-nz *( "/" segment ) ]
    @endcode

    @par Specification
    @li <a href="https://datatracker.ietf.org/doc/html/rfc3986#section-3.3"
        >3.3. Path (rfc3986)</a>
*/
#ifdef BOOST_URL_DOCS
constexpr __implementation_defined__ path_absolute_rule;
#else
constexpr auto path_absolute_rule =
    grammar::range_rule(
        grammar::sequence_rule(
            grammar::char_rule('/'),
            detail::segment_ns_rule),
        detail::slash_segment_rule,
        1);
#endif

//------------------------------------------------

/** Rule for path-noscheme grammar.

    @par BNF
    @code
    path-noscheme = segment-nz-nc *( "/" segment )
    @endcode

    @par Specification
    @li <a href="https://datatracker.ietf.org/doc/html/rfc3986#section-3.3"
        >3.3. Path (rfc3986)</a>
*/
#ifdef BOOST_URL_DOCS
constexpr __implementation_defined__ path_noscheme_rule;
#else
constexpr auto path_noscheme_rule =
    grammar::range_rule(
        detail::segment_nz_nc_rule,
        detail::slash_segment_rule,
        1);
#endif

//------------------------------------------------

/** Rule for path-rootless grammar.

    @par Example
    @code
    path_rootless_rule t;
    bool success = parse( it, end, ec, t);
    @endcode

    @par BNF
    @code
    path-rootless = segment-nz *( "/" segment )
    @endcode

    @par Specification
    @li <a href="https://datatracker.ietf.org/doc/html/rfc3986#section-3.3"
        >3.3. Path (rfc3986)</a>
*/
#ifdef BOOST_URL_DOCS
constexpr __implementation_defined__ path_rootless_rule;
#else
constexpr auto path_rootless_rule =
    grammar::range_rule(
        detail::segment_nz_rule,
        detail::slash_segment_rule,
        1);
#endif

} // urls
} // boost

#endif