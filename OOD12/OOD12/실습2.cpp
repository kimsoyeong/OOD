#include "pch.h"
#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

//여기 버블 소트 부분을 잘 이해해야 한다.
template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {
			//cur에 전위연산자를 사용함으로써 cur과 prev는 first와 frist다음의 것을 비교할 수 있게 된다.
			if (comp(*cur, *prev)) { //비교 함수 사용
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}
	}
}

//Fuctor인 compGreater를 구현하세요. 
struct compGreater { // Functor class
public:
	bool operator()(int a, int b) const {
		return a > b;
	}
};

//Fuctor인 compLess를 구현하세요.
struct compLess { // Functor class
public:
	bool operator()(int a, int b) const {
		return a < b;
	}
};

//클래스로 구현
/*class compGreater {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

class compLess {
public:
	bool operator()(int a, int b) {
		return a < b;
	}
};*/

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };

	std::cout << "오름차순 정렬" << std::endl;
	compLess compLess; //Functor 생성
	bubble_sort(values.begin(), values.end(), compLess);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;


	std::cout << "내림차순 정렬" << std::endl;
	compGreater compGreater; //Functor 생성
	bubble_sort(values.begin(), values.end(), compGreater);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	getchar();
}
