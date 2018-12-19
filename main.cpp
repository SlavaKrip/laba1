#include "Ship.hpp"
#include <fstream>

using namespace std;

template<typename T>
void Menu(Keeper<T> &data){
	cout << "1. Добавить\n2 Удалить\n3 Редактировать\n4 Вывести\nОтмена\n";
	int a;
	T tmp;
	while(!(cin >> a));
	if(a == 1){
		cin >> tmp;
		data.Add(tmp);
	}else if (a == 2){
		cout << "Индекс: ";
		while(!(cin >> a));
		data.Remove(a);
	}else if (a == 3){
		cout << "Индекс: ";
		while(!(cin >> a));
		cin >> data[a];
	} else if (a == 4){
		for(int i = 0; i < data.Size(); ++i){
			cout << data[i] << '\n';
		}
	}
}

int main(){
	setlocale(LC_ALL, "");
	Ship ship;
	Kater k;
	Parus p;
	Submarine s;
	//загрузка из файла
	ifstream in("data");
	if(in){
		int size;
		in >> size;
		for(int i =0; i < size; ++i){
		   in >> k;
		   ship._kater().Add(k);
		}
		in >> size;
		for(int i =0; i < size; ++i){
		   in >> p;
		   ship._parus().Add(p);
		}
		in >> size;
		for(int i =0; i < size; ++i){
		   in >> s;
		   ship._submarine().Add(s);
		}
	}
	in.close();
	while(true){
	   	system("cls");
		cout << "1 Катер\n2 Парусник\n3 Подлодка\n4 Выход\n";
		int a;
		while(!(cin >> a));
		if(a == 1){
			try{
				Menu(ship._kater());
			}
			catch(const Exception& exc){
				cout << exc.what();
			}
		}else if (a == 2){
			try{
			Menu(ship._parus());
			}
			catch(const Exception& exc){
				cout << exc.what();
			}
		}else if (a == 3){
			try{
			Menu(ship._submarine());
			}
			catch(const Exception& exc){
				cout << exc.what();
			}
		}
		else{
		  break;
		}
		system("pause>>void");
	}

	/*запись в файл*/
	ofstream out("data");
		out << ship._kater().Size() << '\n';
		for(int i =0; i < ship._kater().Size(); ++i){
		   out << ship._kater()[i] << '\n';
		}
		out << ship._parus().Size() << '\n';
		for(int i =0; i < ship._parus().Size(); ++i){
		   out << ship._parus().Size() << '\n';
		}
		out << ship._submarine().Size() << '\n';
		for(int i =0; i < ship._submarine().Size(); ++i){
		   out << ship._submarine().Size() << '\n';
		}
	out.close();
}
