#include "HNS.h"

HNS::HNS(){
	values = std::vector<std::pair<int, std::vector>();
}

void HNS::insert(const HostName& hn, const IPAddress& ipa){
	values.insert(make_pair(hash(ipa), hn>));
}

bool HNS::remove(const HostName& hn){
	if (serverNameMap.erase(hn) == 1){
		return true;
	} else {
		return false;
	}
}

IPAddress HNS::lookup(const HostName& hn){
	auto pos = serverNameMap.find(hn);
	if (pos == serverNameMap.end()) {
    	return NON_EXISTING_ADDRESS;
	} else {
    	int value = pos->second;
    	return value;
	}
	return 0;
}