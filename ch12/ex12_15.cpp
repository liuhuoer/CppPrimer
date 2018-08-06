#include <iostream>
#include <string>
#include <memory>

using std::cout;using std::endl;using std::string;

struct destination
{
	string ip;
	size_t port;
	destination(string ip_,size_t port_):ip(ip_),port(port_){}
};

struct connection
{
	string ip;
	size_t port;
	connection(string ip_,size_t port_):ip(ip_),port(port_){}
};

connection connect(destination * pDest)
{
	std::shared_ptr<connection> pConn(new connection(pDest->ip,pDest->port));
	cout<<"connect():"<<pConn.use_count()<<endl;

	return *pConn; }

void disconnect(connection conn)
{
	cout<<"disconnect():"<<conn.ip<<" "<<conn.port<<endl;
}

void f(destination & d)
{
	connection conn=connect(&d);
	std::shared_ptr<connection> pConn(&conn,[](connection *p){disconnect(*p);});
	cout<<"f():"<<pConn.use_count()<<endl;
}

int main()
{
	destination dest("192.168.1.1",64);
	f(dest);

	return 0;
}
