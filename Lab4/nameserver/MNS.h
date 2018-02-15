#ifndef MNS_H
#define MNS_H

#include <string>
#include <map>
#include "nameserverinterface.h"

using HostName = std::string;
using IPAddress = unsigned int;

class MNS : public nameserverinterface{
	public:
		MNS();

		void insert(const HostName&, const IPAddress&);
		bool remove(const HostName&);
		IPAddress lookup(const HostName&);
};

#endif