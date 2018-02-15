#include "HNS.h"

HNS::HNS(int s){
	values = std::vector<std::pair<int, std::vector<IPAddress>();
	size=s;
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

IPAddress HNS::lookup(const HostName& hn) const{
	auto pos = serverNameMap.find(hn);
	if (pos == serverNameMap.end()) {
    	return NON_EXISTING_ADDRESS;
	} else {
    	int value = pos->second;
    	return value;
	}
	return 0;
}

int HNS::hash(const IPAddress& ipa){
	return hash<string>(ipa) % size;
}