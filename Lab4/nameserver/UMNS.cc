#include "UMNS.h"

UMNS::UMNS(){
	serverNameMap = std::unordered_map<std::string, int>();
}

void UMNS::insert(const HostName& hn, const IPAddress& ipa){
	serverNameMap.insert(std::pair<std::string, int>(hn, ipa));
}

bool UMNS::remove(const HostName& hn){
	if (serverNameMap.erase(hn) == 1){
		return true;
	} else {
		return false;
	}
}

IPAddress UMNS::lookup(const HostName& hn) const{
	auto pos = serverNameMap.find(hn);
	if (pos == serverNameMap.end()) {
    	return NON_EXISTING_ADDRESS;
	} else {
    	int value = pos->second;
    	return value;
	}
	return 0;
}