#include "HNS.h"

HNS::HNS(){
	v = std::vector<std::vector<std::string>> v;
}

void HNS::insert(const HostName& hn, const IPAddress& ipa){
	v.insert(std::pair<std::string, int>(hn, ipa));
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