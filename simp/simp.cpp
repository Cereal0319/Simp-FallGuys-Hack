
#include "simp.h"

bool FallGuys::__load(  ) {

	PROCESSENTRY32 PInfo; 
	PInfo.dwSize = sizeof( PInfo );

	HANDLE PSnapshot = CreateToolhelp32Snapshot( 
		TH32CS_SNAPPROCESS, NULL );

	for (
		Process32First( PSnapshot, &PInfo );
		Process32Next( PSnapshot, &PInfo );
		) {

		if ( (std::string)PInfo.szExeFile == 
			"FallGuys_client.exe" ) {

			this->pid = PInfo.th32ProcessID;

		}

	} CloseHandle( PSnapshot );

	if ( !this->pid )
		return 0;

	this->pHandle = OpenProcess( 
		PROCESS_ALL_ACCESS, false, this->pid );

	if ( !this->pHandle )
		return 0;

	MEMORY_BASIC_INFORMATION memInfo;

	for (
		static size_t address;
		VirtualQueryEx( this->pHandle, ( LPVOID )address, &memInfo, sizeof( memInfo ) );
		address += memInfo.RegionSize
		) {

		if ( memInfo.State != MEM_COMMIT )
			continue;

		std::vector< float >memory( memInfo.RegionSize );
		if ( !ReadProcessMemory( this->pHandle, ( LPVOID )address, &memory[ 0 ], memInfo.RegionSize, 0 ) )
			continue;

		size_t size = memInfo.RegionSize / sizeof( float );
		for ( size_t x = 0; x < size; x++ ) {
		
			if ( memory[ x ] == 9.5f ) //default speed value
				this->speed.push_back( address + ( x * sizeof( float ) ) );
		
		}

	} return true;

}

void FallGuys::__unload(  ) {

	this->setSpeed( 9.5f );
	delete( this );

}

void FallGuys::setSpeed( float speed ) {

	for ( size_t x = 0; x < this->speed.size(  ); x++ ) {
	
		WriteProcessMemory( this->pHandle, ( LPVOID )this->speed[ x ], 
			&speed, sizeof( speed ), NULL );
	
	}

}