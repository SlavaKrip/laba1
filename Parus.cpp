#include "Parus.hpp"

Parus::Parus(int length, int speed, int people_cnt, bool isMilitary, const char *type, const char *name)
	:length(length), speed(speed), people_cnt(people_cnt), type(type), isMilitary(isMilitary), name(name){}
	Parus::Parus(const Parus& k)
		:length(k.length), speed(k.speed), people_cnt(k.people_cnt), type(k.type), isMilitary(k.isMilitary), name(k.name){}
	int& Parus::_length(){ return length; }
	int& Parus::_speed(){return speed; }
	int& Parus::_people_cnt(){ return people_cnt; }
	bool& Parus::_isMilitary(){ return isMilitary; }
	std::string& Parus::_type(){ return type; }
	std::string& Parus::_name(){ return name; }

	std::istream& operator>>(std::istream& in, Parus& k){
	   if(!(in >> k.length >> k.speed >> k.people_cnt >> k.isMilitary >> k.type >> k.name)) throw Exception("Error readig");
	   return in;
	}
	std::ostream& operator<<(std::ostream& out, const Parus& k){
		out << k.length << ' ' << k.speed << ' ' << k.people_cnt << ' ' << k.isMilitary << ' ' << k.type << ' ' << k.name;
		return out;
	}
