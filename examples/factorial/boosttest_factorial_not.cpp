
//               Copyright Ben Robinson 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//#define BOOST_TEST_MAIN defined
#define BOOST_METAASSERT_UNITTEST defined

#include <boost/mpl/int.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/static_assert.hpp>

#include <boost/test/unit_test.hpp>

#include "metaassert.hpp"

namespace boost {
namespace {

namespace mpl = boost::mpl;

template <class N>
struct factorial
    : mpl::eval_if<
      mpl::less_equal<N, mpl::int_<0> >
    , mpl::int_<1>
    , mpl::times<N, factorial<typename mpl::prior<N>::type> >
    >::type
{
    BOOST_METAASSERT_NOT((mpl::less<N, mpl::int_<0> >));
};

BOOST_AUTO_TEST_CASE(passing) {
    factorial<mpl::int_<0> > fact0;
    factorial<mpl::int_<1> > fact1;
    factorial<mpl::int_<2> > fact2;
    factorial<mpl::int_<4> > fact4;

    BOOST_CHECK_EQUAL(fact0, 1);
    BOOST_CHECK_EQUAL(fact1, 1);
    BOOST_CHECK_EQUAL(fact2, 2);
    BOOST_CHECK_EQUAL(fact4, 24);
}

BOOST_AUTO_TEST_CASE(failing_negative) {
    BOOST_CHECK_THROW( factorial<mpl::int_<-1> > factneg1;, metaassert_exception );
    BOOST_CHECK_THROW( factorial<mpl::int_<-2> > factneg2;, metaassert_exception );
}

BOOST_AUTO_TEST_CASE(failing_negative_homemade_framework) {
    bool caught = false;
    try {
        factorial<mpl::int_<-1> > factneg1;
    } catch (metaassert_exception & ee) {
        caught = true;
    }
    BOOST_CHECK_EQUAL(caught, true);

    caught = false;
    try {
        factorial<mpl::int_<-2> > factneg1;
    } catch (metaassert_exception & ee) {
        caught = true;
    }
    BOOST_CHECK_EQUAL(caught, true);
}

} // namespace anonymous
} // namespace boost
