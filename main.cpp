
#include "simp/simp.h"
#include "resources/ascii_art.h"

int main(  ) {

	ascii_art::logo(  );
	std::cout << std::endl << "   Loading...";

	FallGuys* simp = new FallGuys(  );
	if ( !simp->__load(  ) ) {

		printf( "Could not load simp!\n" );
		Sleep( 5000 ); return EXIT_SUCCESS;

	} std::cout << ", Loaded! Press delete to unload\n";

	simp->setSpeed( 13.f );
	
	for (;
	~GetAsyncKeyState( VK_DELETE )&0x8000;
	Sleep( 100 ) 
	);

	simp->__unload(  ); return EXIT_SUCCESS;

}