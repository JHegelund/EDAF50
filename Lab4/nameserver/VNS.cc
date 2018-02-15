#include "VNS.h"
#include <algorithm>
#include <iostream>

using namespace std;

VNS::VNS(){
	db = vector<std::pair<HostName, IPAddress>>();
}

void VNS::insert(const HostName& HN, const IPAddress& IPA){
	db.push_back(make_pair(HN, IPA));
}

bool VNS::remove(const HostName& HN){
	std::vector<std::pair<HostName, IPAddress>>::iterator it = std::find_if(db.begin(), db.end(), [&](std::pair<HostName, IPAddress> current) -> bool {
		return (current.first == HN);
	});
	if((it) != (db.end())){
		db.erase(it);
		return true;
	}
	return false;
}

IPAddress VNS::lookup(const HostName& HN) const {
	auto it = std::find_if(db.begin(), db.end(), [&](std::pair<HostName, IPAddress> current) mutable -> bool {
		return (current.first == HN);
	});	
	if((it) != (db.end())){
 		return (*it).second;
 	}
 	return NON_EXISTING_ADDRESS;
}
