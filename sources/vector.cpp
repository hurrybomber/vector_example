#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()//
{
	elements_ = nullptr;
	size_=0;
	capacity_ =0;
}

vector_t::vector_t(vector_t const & other)// copy
{
	 size_=other.size_;
    capacity_=other.capacity_;
    elements_ = new int[capacity_];
    for (std::size_t i = 0; i < size_; i++)
        elements_[i]=other.elements_[i];

}

vector_t & vector_t::operator =(vector_t const & other)
{
	if(elements_ != nullptr)
        delete [] elements_;
    size_=other.size_;
    capacity_=other.capacity_;
    elements_=new int[capacity_];
    for (std::size_t i = 0; i < size_; i++)
        elements_[i]=other.elements_[i];
    return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if ((size_ != other.size_)or(capacity_ != other.capacity_)) return 0;
	for (int i=0; i < size_; i++) 
	if (other.elements_[i] != elements_[i])  return 0;
	return 1;
}

vector_t::~vector_t()
{
	size_ = 0;
	capacity_ = 0;
	delete[] elements_;
}

std::size_t vector_t::size() const
{
   return size_;
}

std::size_t vector_t::capacity() const
{
 return capacity_;
}

void vector_t::push_back(int value)
{
}

void vector_t::pop_back()
{
	if (size_ == 0)
		return;
	size_ = size_ - 1;
	if (size_ * 4 <= capacity_) capacity_ = capacity_ / 2;
	int* elements_2 = new int[capacity_];
	for (int i = 0; i < size_; i++)
		elements_2[i] = elements_[i];
	delete[] elements_;
	elements_ = elements_2;
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	bool b = 1;
	
	if (rhs.size() != lhs.size()) return 1;
	for (int i=0; i < lhs.size(); i++) 
	if (rhs[i] == lhs[i])  b = 0;
	return b;
}
