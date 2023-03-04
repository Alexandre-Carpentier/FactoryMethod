#include <iostream>

class Voltage {
public:
	// Factory method
	static Voltage* CreateVoltage(std::string const& type);
	virtual bool init() = 0;
};

class Agilent:public Voltage {
public:
	virtual bool init()
	{
		std::cout << "Init Agilent" << std::endl;
		return true;
	}
};

class Keitley :public Voltage {
public:
	virtual bool init()
	{
		std::cout << "Init Keitley" << std::endl;
		return true;
	}
};

// Factory method
Voltage* Voltage::CreateVoltage(std::string const &type)
{
	if (type == "Agilent") 
		return new Agilent;
	if (type == "Keitley")
		return new Keitley;

	return nullptr;
}

int main()
{
	Voltage* v = nullptr;
	v=v->CreateVoltage("Agilent"); // Call the factory method
	if (v)
	{
		v->init();

		delete(v);
	}
	return 0;
}