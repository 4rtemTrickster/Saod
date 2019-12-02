#include "Product.h"
#include  <iostream>

task::product::product()
{
	this->parts_count = PARTS_COUNT;
	this->parts_arr_ = static_cast<part*>(std::malloc(sizeof(part) * PARTS_COUNT));

	for (size_t i = 0,j = 0; i < PARTS_COUNT; i++, j++)
	{
		this->parts_arr_[i].id = i + 1;

		if (j < MAX_PARTS_WITH_SUBPARTS_COUNT)
		{
			this->parts_arr_[i].subparts_count = MAX_SUBPARTS_COUNT;
			this->parts_arr_[i].subparts_arr_ = static_cast<size_t*>(std::malloc(sizeof(size_t) * MAX_SUBPARTS_COUNT));
			this->parts_arr_[i].subparts_arr_[0] = 3;
			this->parts_arr_[i].subparts_arr_[1] = 4;
		}
		else
		{
			this->parts_arr_[i].subparts_count = 0;
			this->parts_arr_[i].subparts_arr_ = nullptr;
		}
	}
}

task::product::~product()
{
	for (size_t i = 0; i < PARTS_COUNT; i++)
		if(this->parts_arr_[i].subparts_arr_ != nullptr)
			std::free(this->parts_arr_[i].subparts_arr_);

	std::free(this->parts_arr_);
}

size_t task::product::get_parts_count()
{
	return this->parts_count;
}

size_t* task::product::get_subparts_status_at(size_t at)
{
	return this->parts_arr_[at].subparts_arr_;
}

size_t task::product::get_subpart_id_at(size_t at)
{
	return this->parts_arr_[at].id;
}
