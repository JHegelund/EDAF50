#ifndef HNS_H
#define HNS_H

#include <algorithm>
#include <string>
#include <functional>
#include "nameserverinterface.h"

using HostName = std::string;
using IPAddress = unsigned int;

class HNS : public NameServerInterface{
	public:
		HNS(int);
		void insert(const HostName&, const IPAddress&);
		bool remove(const HostName&);
		IPAddress lookup(const HostName&) const;
	private:
		std::vector<std::vector<std::pair<HostName, IPAddress>>> hashmap;
		size_t str_hash(const HostName&) const;
		int size;
};

#endif