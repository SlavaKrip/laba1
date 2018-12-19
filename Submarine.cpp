#include "Submarine.hpp"

Submarine::Submarine(int speed, int people_cnt, const char* hodKach, const char *target, const char *material)
	:speed(speed), people_cnt(people_cnt), hodKach(hodKach), target(target), material(material){}
	Submarine::Submarine(const Submarine& k)
		:speed(k.speed), people_cnt(k.people_cnt), hodKach(k.hodKach), target(k.target), material(k.material){}
	int& Submarine::_speed(){ return speed;}
	int& Submarine::_people_cnt(){ return people_cnt; }
	std::string& Submarine::_target(){ return target; }
	std::string& Submarine::_material(){ return material; }
	std::string& Submarine::_hodKach(){ return hodKach; }

	std::istream& operator>>(std::istream& in, Submarine& k){
	   if(!(in >> k.speed >> k.people_cnt >> k.target >> k.material >> k.hodKach)) throw Exception("Error readig");
	   return in;
	}
	std::ostream& operator<<(std::ostream& out, const Submarine& k){
		out << k.speed << ' ' << k.people_cnt << ' ' << k.target << ' ' << k.material << ' ' << k.hodKach;
		return out;
	}
