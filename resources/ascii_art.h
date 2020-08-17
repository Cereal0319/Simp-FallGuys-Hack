
#include <windows.h>
#include <iostream>
#include <vector>

namespace ascii_art {

    void logo(  ) {

        static std::vector< byte >logo = { '\n',
            32, 32, 32, 201, 205, 187, 194, 218, 194, 191, 218, 196, 191, '\n',
            32, 32, 32, 200, 205, 187, 179, 179, 179, 179, 197, 196, 217, '\n',
            32, 32, 32, 200, 205, 188, 193, 193, 193, 193, 179, '0', '.', '1', '\n'
        };

        HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
        for ( size_t x = 0; x < logo.size(  ); printf( "%c", logo[ x ] ), x++, Sleep( 10 ) ) {

            if ( x == 0 )
                SetConsoleTextAttribute( console, 7 );

            if ( x == 17 )
                SetConsoleTextAttribute( console, 4 );

            if ( x == logo.size(  ) - 8 )
                SetConsoleTextAttribute( console, 7 );

        }

    }

}