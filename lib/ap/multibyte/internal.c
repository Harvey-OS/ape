/* 
 * This code was written by Rich Felker in 2010; no copyright is claimed.
 * This code is in the public domain. Attribution is appreciated but
 * unnecessary.
 */

#include "internal.h"
#include <stdint.h>

#define C(x) ( x<2 ? -1 : ( R(0x80,0xc0) | x ) )
#define D(x) C((x+16))
#define E(x) ( ( x==0 ? R(0xa0,0xc0) : \
                 x==0xd ? R(0x80,0xa0) : \
                 R(0x80,0xc0) ) \
             | ( R(0x80,0xc0) >> 6 ) \
             | x )
#define F(x) ( ( x>=5 ? 0 : \
                 x==0 ? R(0x90,0xc0) : \
                 x==4 ? R(0x80,0xa0) : \
                 R(0x80,0xc0) ) \
             | ( R(0x80,0xc0) >> 6 ) \
             | ( R(0x80,0xc0) >> 12 ) \
             | x )

const uint32_t bittab[] = {
	              C(0x2),C(0x3),C(0x4),C(0x5),C(0x6),C(0x7),
	C(0x8),C(0x9),C(0xa),C(0xb),C(0xc),C(0xd),C(0xe),C(0xf),
	D(0x0),D(0x1),D(0x2),D(0x3),D(0x4),D(0x5),D(0x6),D(0x7),
	D(0x8),D(0x9),D(0xa),D(0xb),D(0xc),D(0xd),D(0xe),D(0xf),
	E(0x0),E(0x1),E(0x2),E(0x3),E(0x4),E(0x5),E(0x6),E(0x7),
	E(0x8),E(0x9),E(0xa),E(0xb),E(0xc),E(0xd),E(0xe),E(0xf),
	F(0x0),F(0x1),F(0x2),F(0x3),F(0x4)
};
