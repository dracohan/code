#include "3.15_p107_String.h"
#include <iostream>

using namespace std;


int main() 
{
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
        theCnt = 0, itCnt =0, wdCnt = 0, notVowel = 0;
    String buf, the( "the" ), it( "it" );

    // invoke operator>> 
    while ( cin >> buf ) {
        ++wdCnt;

        //invoke operator<< 
        cout << buf << ' '; 
        if ( wdCnt%12 == 0 ) 
            cout << endl;

        if ( buf == the || buf == "The" ) 
            ++theCnt;
        else
            if ( buf == it || buf == "It" )
                ++itCnt;
        for ( int ix = 0; ix < buf.size(); ++ix )
        {
            switch ( buf[ ix ] )
            {
                case 'a': case 'A': ++aCnt; break;
                case 'e': case 'E': ++eCnt; break;
                case 'i': case 'I': ++iCnt; break;
                case 'o': case 'O': ++oCnt; break;
                case 'u': case 'U': ++uCnt; break;
                default: ++notVowel; break;
            }
        }
    }

    cout << "\n\n"
        << "Words read: " << wdCnt << "\n\n"
        << "the/The: "    << theCnt << '\n'
        << "it/It: "      << itCnt << "\n\n"
        << "non-vowel read: " << notVowel << "\n\n"
        << "a: " << aCnt << '\n'
        << "e: " << eCnt << '\n'
        << "i: " << iCnt << '\n'
        << "o: " << oCnt << '\n'
        << "u: " << uCnt << endl;

}
