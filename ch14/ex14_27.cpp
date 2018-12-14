#include "ex14_27.h"

/********************************************************
 * 			class - StrBlob
 * ****************************************************/

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs); 
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs)
{
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs)
{
	return rhs<lhs;
}

bool operator<=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs < rhs);
}

StrBlob& StrBlob::operator=(const StrBlob& rhs)
{
	data = std::make_shared<vector<string>>(*rhs.data);
	return *this;
}

StrBlob& StrBlob::operator=(StrBlob&& rhs) noexcept
{
	if(this != &rhs)
	{
		data = std::move(rhs.data);
		rhs.data = nullptr;
	}
	return *this;
}


//implementation functions in StrBlob;
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this,data->size());
}

/********************************************************
 * 			class - StrBlobPtr - operator_friend
 * ****************************************************/

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return rhs.curr > rhs.curr;
}

bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs < rhs);
}


