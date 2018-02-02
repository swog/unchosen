
#ifndef CLIENT_H
#define CLIENT_H

class ClientClass;

class Client
{
public:
	ClientClass* GetAllClasses(void);
};

extern Client* client;

#endif