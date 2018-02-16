#include "HNS.h"

HNS::HNS(int s){
	hashmap = std::vector<std::vector<std::pair<HostName, IPAddress>>>(s);
	size = s;
}

void HNS::insert(const HostName& hn, const IPAddress& ipa){
	size_t index = str_hash(hn);
	hashmap[index].push_back(make_pair(hn, ipa));
}

bool HNS::remove(const HostName& hn){
	size_t index = str_hash(hn);
	auto &vec = hashmap[index];

	auto it = std::find_if(vec.begin(), vec.end(), [&](std::pair<HostName, IPAddress> current) -> bool {
		return (current.first == hn);
	});
	if(it != vec.end()){
		vec.erase(it);
		return true;
	} 
	return false;
}

IPAddress HNS::lookup(const HostName& hn) const{
	size_t index = str_hash(hn);
	auto &vec = hashmap[index];

	auto it = std::find_if(vec.begin(), vec.end(), [&](std::pair<HostName, IPAddress> current) -> bool {
		return (current.first == hn);
	});
	if(it != vec.end()){
		return (*it).second;
	}

	return NON_EXISTING_ADDRESS;
}

size_t HNS::str_hash(const HostName& hn) const{
	std::hash<HostName> hashIndex;
	return hashIndex(hn) % size;
}