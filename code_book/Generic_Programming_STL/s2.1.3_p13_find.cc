template <class Iterator, class T>
Iterator find(Iterator first, iterator last, const T& value)
{
  while (first != last && *first != value)
    ++first;
  return first;
}