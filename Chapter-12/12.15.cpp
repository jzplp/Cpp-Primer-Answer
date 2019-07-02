#include<memory>

struct destination;
struct connection;
connection connect(destination *); 
void disconnect(connection);

void f(destination &d)
{
	connection c = connect(&d);
	std::shared_ptr<connection> p(&c, [](connection *p){ disconnect(*p); });
}

