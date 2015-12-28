//filter string
template<class InputIterator>
void filter_string(InputIterator first, InputIterator last, string filter_items = string("\",?."))
{
	for(; first != last, first++)
	{
		string::size_type pos = 0;
		while((pos = (*first).find_first_of(filter_items, pos)) != string::npos )
			(*first).erase(pos, 1);
	}
}

