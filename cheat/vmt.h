
class VMT
{
public:
	void* GetVirtual(void* instance, int index);
	void* HookVirtual(void* instance, int index, void* replacement);
	void* GetInterface(char* module, char* name);
	void* GetInterfaceVersion(char* module, char* prefix);
	
	template<class T>
	T Convert(void* data) { return (T*)data;
};

extern VMT vmt;
