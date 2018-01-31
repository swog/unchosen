
class VMT
{
public:
	void* GetVirtual(void* instance, int index);
	void* HookVirtual(void* instance, int index, void* replacement);
};

extern VMT vmt;
