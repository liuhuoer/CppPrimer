#include "disc_quote.h"
inline 
bool operator!=(const Disc_quote& lhs, const Disc_quote& rhs)
{ return (Quote(lhs) != Quote(rhs)) && (lhs.qty != rhs.qty) 
	&& (lhs.disc != rhs.disc);}

