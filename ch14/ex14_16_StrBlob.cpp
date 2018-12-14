#include "ex14_16_StrBlob.h"
/*
 * StrBlob
 * */

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs); 
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

/*
 * StrBlobPtr
 */
bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}


