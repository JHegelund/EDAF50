#ifndef UMNS_H
#define UMNS_H

#include <string>
#include <unordered_map>
#include "nameserverinterface.h"

using HostName = std::string;
using IPAddress = unsigned int;

class UMNS : public NameServerInterface{
	public:
		UMNS();
		void insert(const HostName&, const IPAddress&);
		bool remove(const HostName&);
		IPAddress lookup(const HostName&);
	private:
		std::unordered_map<std::string, int> serverNameMap;
};

#endif