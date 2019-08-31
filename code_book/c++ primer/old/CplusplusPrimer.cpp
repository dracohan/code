//���庯��ָ�����
typedef int ( *PFI2S ) ( const string &, const string & );

//��������
int lexicoCompare( cnost string &, const string & );
int sort( string*, string*, PFI2S = lexicoCompare);

//��������
void sort ( string *s1, sring *s2, PFI2S compare = lexicoCompare )
{
	//�ݹ��ֹͣ����
	if (s1 < s2 ) {
		string elem = *s1;
		string *low = *s1;
		string *high = s2 -1; 

		for (;;)
		{
			while (compare ( *++low, elem ) < 0 && low < s2 ) ;
			while (compare ( elem, *--high) < 0 && high > s1 );
			
			if ( low < high)
			{
				low->swap(*high);
			} 
			else
			{
				break;
			}
		} //end, for (;;)

		//put elem into correct location
		s1->swap(*high);
		sort( s1, high - 1, compare );
		sort( low + 1, s2, compare );

	} ///end, if (s1 < s2)
}    