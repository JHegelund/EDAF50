#include "MNS.h"

MNS::MNS(){
	serverNameMap = std::map<std::string, int>();
}

void MNS::insert(const HostName& hn, const IPAddress& ipa){
	serverNameMap.insert(std::pair<std::string, int>(hn, ipa));
}

bool MNS::remove(const HostName& hn){
	if (serverNameMap.erase(hn) == 1){
		return true;
	} else {
		return false;
	}
}

IPAddress MNS::lookup(const HostName& hn) const{
	auto pos = serverNameMap.find(hn);
	if (pos == serverNameMap.end()) {
    	return NON_EXISTING_ADDRESS;
	} else {
    	int value = pos->second;
    	return value;
	}
	return 0;
}