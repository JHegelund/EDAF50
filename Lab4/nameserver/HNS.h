#ifndef HNS_H
#define HNS_H

#include <string>
#include <unordered_map>
#include "nameserverinterface.h"

using HostName = std::string;
using IPAddress = unsigned int;

class HNS : public NameServerInterface{
	public:
		HNS();
		void insert(const HostName&, const IPAddress&) const;
		bool remove(const HostName&);
		IPAddress lookup(const HostName&) const;
	private:
		std::vector<std::vector<std::string>> values;
		int hash(const IPAddress&);
};

#endif