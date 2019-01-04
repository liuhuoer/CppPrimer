#ifndef EX14_32
#define EX14_32

class StrBlobPtr;

class StrBlobPtrPtr
{
public:
	StrBlobPtrPtr() = default;
//	StrBlobPtrPtr(StrBlobPtr* sbp) : sbpp(sbp) { } 
	StrBlobPtrPtr(StrBlobPtr sbp) : sbpp(&sbp) { } 

	StrBlobPtr& operator*() const;
	StrBlobPtr* operator->() const;
private:
	StrBlobPtr* sbpp = nullptr;
};

#endif
