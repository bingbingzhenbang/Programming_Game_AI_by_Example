#include <lua.hpp>
#include <iostream>

int main()
{
	lua_State *pl = luaL_newstate();
	luaL_openlibs(pl);
	int ret = luaL_dofile(pl, "hello.lua");
	if (ret)
		std::cout << "Error!" << std::endl;
	lua_close(pl);
	return 0;
}