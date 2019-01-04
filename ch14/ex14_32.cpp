#include "ex14_30.cpp"
#include "ex14_32.h"

StrBlobPtr& StrBlobPtrPtr::operator*() const
{
	return *sbpp;
}

StrBlobPtr* StrBlobPtrPtr::operator->() const
{
	return sbpp;
}
