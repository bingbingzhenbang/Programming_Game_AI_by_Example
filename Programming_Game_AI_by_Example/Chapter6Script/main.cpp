#include <lua.hpp>

int main()
{
	lua_State *pl = luaL_newstate();
	lua_close(pl);
	return 0;
}