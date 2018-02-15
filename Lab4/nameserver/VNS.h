#ifndef VNS_H
#define VNS_H

#include <string>
#include "nameserverinterface.h"

using HostName = std::string;
using IPAddress = unsigned int;

class VNS : public NameServerInterface {
public:
	VNS();
	void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;
};

#endif