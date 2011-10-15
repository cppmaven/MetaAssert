
//               Copyright Ben Robinson 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//#define BOOST_TEST_MAIN defined
#define BOOST_METAASSERT_UNITTEST defined

#include <boost/cstdint.hpp>
#include <boost/test/unit_test.hpp>
#include "metaassert.hpp"

#include "safecast.hpp"

namespace {

using ::boost::metaassert_exception;
using ::boost::safe_cast;

BOOST_AUTO_TEST_CASE(rhs_unsigned8) {
    uint8_t  unsigned8  = 0;
    uint16_t unsigned16 = 0;
    uint32_t unsigned32 = 0;
    int8_t     signed8  = 0;
    int16_t    signed16 = 0;
    int32_t    signed32 = 0;
    BOOST_CHECK_NO_THROW( unsigned8 = safe_cast<uint8_t>(unsigned8); );
    BOOST_CHECK_NO_THROW( unsigned16 = safe_cast<uint16_t>(unsigned8); );
    BOOST_CHECK_NO_THROW( unsigned32 = safe_cast<uint32_t>(unsigned8); );
    BOOST_CHECK_THROW( signed8 = safe_cast<int8_t>(unsigned8);, metaassert_exception );
    BOOST_CHECK_NO_THROW( signed16 = safe_cast<int16_t>(unsigned8); );
    BOOST_CHECK_NO_THROW( signed32 = safe_cast<int32_t>(unsigned8); );
}

BOOST_AUTO_TEST_CASE(rhs_unsigned16) {
    uint8_t  unsigned8  = 0;
    uint16_t unsigned16 = 0;
    uint32_t unsigned32 = 0;
    int8_t     signed8  = 0;
    int16_t    signed16 = 0;
    int32_t    signed32 = 0;
    BOOST_CHECK_THROW( unsigned8 = safe_cast<uint8_t>(unsigned16);, metaassert_exception );
    BOOST_CHECK_NO_THROW( unsigned16 = safe_cast<uint16_t>(unsigned16); );
    BOOST_CHECK_NO_THROW( unsigned32 = safe_cast<uint32_t>(unsigned16); );
    BOOST_CHECK_THROW( signed8 = safe_cast<int8_t>(unsigned16);, metaassert_exception );
    BOOST_CHECK_THROW( signed16 = safe_cast<int16_t>(unsigned16);, metaassert_exception );
    BOOST_CHECK_NO_THROW( signed32 = safe_cast<int32_t>(unsigned16); );
}

BOOST_AUTO_TEST_CASE(rhs_unsigned32) {
    uint8_t  unsigned8  = 0;
    uint16_t unsigned16 = 0;
    uint32_t unsigned32 = 0;
    int8_t     signed8  = 0;
    int16_t    signed16 = 0;
    int32_t    signed32 = 0;
    BOOST_CHECK_THROW( unsigned8 = safe_cast<uint8_t>(unsigned32);, metaassert_exception );
    BOOST_CHECK_THROW( unsigned16 = safe_cast<uint16_t>(unsigned32);, metaassert_exception );
    BOOST_CHECK_NO_THROW( unsigned32 = safe_cast<uint32_t>(unsigned32); );
    BOOST_CHECK_THROW( signed8 = safe_cast<int8_t>(unsigned32);, metaassert_exception );
    BOOST_CHECK_THROW( signed16 = safe_cast<int16_t>(unsigned32);, metaassert_exception );
    BOOST_CHECK_THROW( signed32 = safe_cast<int32_t>(unsigned32);, metaassert_exception );
}

BOOST_AUTO_TEST_CASE(rhs_signed8) {
    uint8_t  unsigned8  = 0;
    uint16_t unsigned16 = 0;
    uint32_t unsigned32 = 0;
    int8_t     signed8  = 0;
    int16_t    signed16 = 0;
    int32_t    signed32 = 0;
    BOOST_CHECK_THROW( unsigned8 = safe_cast<uint8_t>(signed8);, metaassert_exception );
    BOOST_CHECK_THROW( unsigned16 = safe_cast<uint16_t>(signed8);, metaassert_exception );
    BOOST_CHECK_THROW( unsigned32 = safe_cast<uint32_t>(signed8);, metaassert_exception );
    BOOST_CHECK_NO_THROW( signed8 = safe_cast<int8_t>(signed8); );
    BOOST_CHECK_NO_THROW( signed16 = safe_cast<int16_t>(signed8); );
    BOOST_CHECK_NO_THROW( signed32 = safe_cast<int32_t>(signed8); );
}

BOOST_AUTO_TEST_CASE(rhs_signed16) {
    uint8_t  unsigned8  = 0;
    uint16_t unsigned16 = 0;
    uint32_t unsigned32 = 0;
    int8_t     signed8  = 0;
    int16_t    signed16 = 0;
    int32_t    signed32 = 0;
    BOOST_CHECK_THROW( unsigned8 = safe_cast<uint8_t>(signed16);, metaassert_exception );
    BOOST_CHECK_THROW( unsigned16 = safe_cast<uint16_t>(signed16);, metaassert_exception );
    BOOST_CHECK_THROW( unsigned32 = safe_cast<uint32_t>(signed16);, metaassert_exception );
    BOOST_CHECK_THROW( signed8 = safe_cast<int8_t>(signed16);, metaassert_exception );
    BOOST_CHECK_NO_THROW( signed16 = safe_cast<int16_t>(signed16); );
    BOOST_CHECK_NO_THROW( signed32 = safe_cast<int32_t>(signed16); );
}

BOOST_AUTO_TEST_CASE(rhs_signed32) {
    uint8_t  unsigned8  = 0;
    uint16_t unsigned16 = 0;
    uint32_t unsigned32 = 0;
    int8_t     signed8  = 0;
    int16_t    signed16 = 0;
    int32_t    signed32 = 0;
    BOOST_CHECK_THROW( unsigned8 = safe_cast<uint8_t>(signed32);, metaassert_exception );
    BOOST_CHECK_THROW( unsigned16 = safe_cast<uint16_t>(signed32);, metaassert_exception );
    BOOST_CHECK_THROW( unsigned32 = safe_cast<uint32_t>(signed32);, metaassert_exception );
    BOOST_CHECK_THROW( signed8 = safe_cast<int8_t>(signed32);, metaassert_exception );
    BOOST_CHECK_THROW( signed16 = safe_cast<int16_t>(signed32);, metaassert_exception );
    BOOST_CHECK_NO_THROW( signed32 = safe_cast<int32_t>(signed32); );
}

} // namespace anonymous
