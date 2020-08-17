
#include <windows.h>
#include <iostream>
#include <vector>
#include <TlHelp32.h>

struct FallGuys {

private:
	size_t pid;
	HANDLE pHandle;
	std::vector< size_t >speed;

public:
	bool __load(  );
	void __unload(  );

	void setSpeed( float speed );

};