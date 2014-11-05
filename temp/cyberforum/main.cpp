#include <iostream>

using namespace std;

template<typename K, typename V>
class Entry
{
public:
	int n;
};

template<typename K, typename V>
class Map {
public:
    /**/
    void forEach(void(*func)(Entry<K, V>*));
    
    template<typename A> 
    void forEach(A& arg, void(*func)(Entry<K, V>*, A&)); 
    /**/
};

template<typename K, typename V>
void Map<K, V>::forEach(void(*func)(Entry<K, V>*)) {
    for (int i = 0; i < 5; i++) {
        //func(entrys->get(i));
    }
}
 
template<typename K, typename V>
template<typename A>
void Map<K, V>::forEach(A& arg, void(*func)(Entry<K, V>*, A&)) {
    for (int i = 0; i < 5; i++) {
        //func(entrys->get(i), arg);
    }
}

int main()
{
	cout << "test";
	return 0;
}
