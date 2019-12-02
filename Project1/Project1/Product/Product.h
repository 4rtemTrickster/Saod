#pragma once


namespace task
{
#define PARTS_COUNT 6
#define MAX_PARTS_WITH_SUBPARTS_COUNT 2
#define MAX_SUBPARTS_COUNT 2
	
	class product
	{
	private:
		
		struct part
		{
			size_t id;
			size_t *subparts_arr_;
			size_t subparts_count;
		};

		part *parts_arr_;
		size_t parts_count;
		
	public:
		product();
		~product();

		size_t get_parts_count();
		size_t* get_subparts_status_at(size_t at);
		size_t get_subpart_id_at(size_t at);
	};
}