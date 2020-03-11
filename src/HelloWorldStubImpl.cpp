#include "HelloWorldStubImpl.hpp"
using namespace std;
#include<iostream>
HelloWorldStubImpl::HelloWorldStubImpl() { cout<< "this is called";}
HelloWorldStubImpl::~HelloWorldStubImpl() { }

void HelloWorldStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,
	std::string _name, sayHelloReply_t _reply) {
	    std::stringstream messageStream;
	    messageStream << "Hello " << _name << "!";
	    std::cout << "sayHello('" << _name << "'): '" << messageStream.str() << "'\n";

    _reply(messageStream.str());
};
