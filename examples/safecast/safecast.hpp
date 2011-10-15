//               Copyright Ben Robinson 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef SAFECAST_HPP
#define SAFECAST_HPP

#include <boost/mpl/assert.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/is_signed.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/integer_traits.hpp>

#include "metaassert.hpp"

namespace boost {

using ::boost::integer_traits;

template <class LHS, class RHS>
LHS safe_cast(RHS const rhs)
{
    typedef typename ::boost::remove_cv<LHS>::type L;
    typedef typename ::boost::remove_cv<RHS>::type R;
    BOOST_METAASSERT_MSG(integer_traits<L>::is_integral, LHS_MUST_BE_AN_INTEGRAL_TYPE, (L, R));
    BOOST_METAASSERT_MSG(integer_traits<R>::is_integral, RHS_MUST_BE_AN_INTEGRAL_TYPE, (L, R));
    BOOST_METAASSERT_MSG(integer_traits<L>::const_max >= integer_traits<R>::const_max, LHS_MAX_MUST_BE_GREATER_THAN_OR_EQUAL_TO_RHS_MAX, (LHS, RHS));
    BOOST_METAASSERT_MSG(is_unsigned<R>::value || (is_signed<L>::value && sizeof(L) >= sizeof(R)), LHS_MIN_MUST_BE_LESS_THAN_OR_EQUAL_TO_RHS_MIN, (LHS, RHS));
    return static_cast<LHS>(rhs);
}

} // namespace boost

#endif // SAFECAST_HPP
