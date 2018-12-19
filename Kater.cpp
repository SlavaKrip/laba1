#include "Kater.hpp"

Kater::Kater(int length, int weigth, int people_cnt, int max_speed, const char *time, const char *guns)
	:length(length), weigth(weigth), people_cnt(people_cnt), max_speed(max_speed), time(time), guns(guns){}
	Kater::Kater(const Kater& k)
	:length(k.length), weigth(k.weigth), people_cnt(k.people_cnt), max_speed(k.max_speed), time(k.time), guns(k.guns){}

	int& Kater::_length(){ return length; }
	int& Kater::_weigth(){ return weigth; }
	int& Kater::_people_cnt(){ return people_cnt; } 
	int& Kater::_max_speed(){ return max_speed; }
	std::string& Kater::_time(){ return time; }
	std::string& Kater::_guns(){ return guns; }

	std::istream& operator>>(std::istream& in, Kater& k){
		 if(!(in >> k.length >> k.weigth >> k.people_cnt >> k.max_speed >> k.time >> k.guns)) throw Exception("Error readig");
		 return in;
	}

	std::ostream& operator<<(std::ostream& out, const Kater& k){
		out << k.length << ' ' << k.weigth << ' ' << k.people_cnt << ' ' << k.max_speed << ' ' << k.time << ' ' << k.guns;
		return out;
	}
