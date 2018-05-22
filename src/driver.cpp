/**
 * @file driver.cpp
 * @version 1.0
 * @date May, 20.
 * @author Daniel Guerra and Oziel Alves
 * @title ls::list Driver
 * @brief List Driver
 */

#include <iostream>
#include <cassert>
#include "../include/list.hpp"

using namespace ls;

int main(int argc, char const *argv[]){

/*-------------------------- Control variables ------------------------------*/

	List<int> l;
    List<int> l2(l);
    List<int> l3(std::move(l));
	List<int> l4;
    List<int>::iterator it;
    List<int>::const_iterator cit;
    int i;
	printf("\n\n");

/*------------------------End of control variables --------------------------*/ 
    
	// 1) Testing function "size"
    assert(l.size() == 0 && l2.size() == 0 && l3.size() == 0);

    // 2) Testing with empty lists: "empty"
    assert(l.empty() == true && l2.empty() == true && l3.empty() == true);

/*------------------- 3) Testing "push_front" consequences ------------------*/
    
	l.push_front(3);
    l2.push_front(3);
    l3.push_front(3);

	l4 = l2;

    assert(l.size() == 1 && l2.size() == 1 && l3.size() == 1);

    assert(l.empty() == false && l2.empty() == false && l3.empty() == false);
    
    assert(l.front() == 3 && l2.front() == 3 && l3.front() == 3);
    
    assert(l.back() == 3 && l2.back() == 3 && l3.back() == 3);

/*-------------------------- 4) Testing push_back() -------------------------*/
   
	l.push_back(10);
    l2.push_back(10);
    l3.push_back(10);
    
    assert(l.size() == 2 && l2.size() == 2 && l3.size() == 2 ); // size() to 'l'
    
    assert(l.empty() == false && l2.empty() == false && l3.empty() == false ); // empty() to 'l'
    
    assert(l.front() == 3 && l2.front() == 3 && l3.front() == 3); // front() to 'l'
    
    assert(l.back() == 10 && l2.back() == 10 && l3.back() == 10); // back() to 'l'

/*----------------------- 5) pop_front() consequences -----------------------*/
    
	l.pop_front();
    l2.pop_front();
    l3.pop_front();
    
    assert(l.size() == 1 && l2.size() == 1 && l3.size() == 1);
    
    assert(l.empty() == false && l2.empty() == false && l3.empty() == false);
    
    assert(l.front() == 10 && l2.front() == 10 && l3.front() == 10);
    
    assert(l.back() == 10 && l2.back() == 10 && l3.back() == 10);

    l.push_front(3);
    l2.push_front(3);
    l3.push_front(3);

/*----------------------- 6) pop_back() consequences ------------------------*/
    
	l.pop_back();
    l2.pop_back();
    l3.pop_back();
    
    assert(l.size() == 1 && l2.size() == 1 && l3.size() == 1); // size() to 'l'
   
    assert(l.empty() == false && l2.empty() == false && l3.empty() == false); // empty() to 'l'
   
    assert(l.front() == 3 && l2.front() == 3 && l3.front() == 3); // front() to 'l'
   
    assert(l.back() == 3 && l2.back() == 3 && l3.back() == 3); // back() to 'l'

/*------------------------ 7) clear() consequences --------------------------*/
    
	l.clear();
    l2.clear();
    l3.clear();
   
    assert(l.size() == 0 && l2.size() == 0 && l3.size() == 0); // size() to 'l'
    
    assert(l.empty() == true && l2.empty() == true && l3.empty() == true); // empty() to 'l'

/*----------------------- 8) push_back() and back() -------------------------*/
    
	for (i = 0; i < 10; i++) {
        
        l.push_back(i);
        l2.push_back(i);
        l3.push_back(i);
        
        assert(l.back() == i && l2.back() == i && l3.back() == i);
    }

/*----------------- 9) assign(), front() and pop_front(); -------------------*/
    
	l.assign(100);
    l2.assign(100);
    l3.assign(100);
    for (i = 0; i < 10; i++) {
        
        assert(l.front() == 100 && l2.front() == 100 && l3.front() == 100);

        l.pop_front();
        l2.pop_front();
        l3.pop_front();
    }
	
/*--------------- 10) size() and empty() (after pop_front) ------------------*/

    assert(l.size() == 0 && l2.size() == 0 && l3.size() == 0);
    
    assert(l.empty() == true && l2.empty() == true && l3.empty() == true);


/*---------------- 11) assign() with initializer list -----------------------*/
    
	l.assign({1, 2, 3, 4});
    l2.assign({1, 2, 3, 4, 5, 10});
    l3.assign({100,1, 2, 3, 4});

	assert(l.size() == 4 && l2.size() == 6 && l3.size() == 5);

	std::cout << "List l1:\n";
	for(auto itr = l.begin(); itr != l.end(); itr++){
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	

	std::cout << "Front1: " << l.front() << " and Back1: " << l.back() << "\n";
	
	l2.pop_front();
	std::cout << "Front2: " << l2.front() << " and Back2: " << l2.back() << "\n";

	l2.pop_back();
	std::cout << "Front2: " << l2.front() << " and Back2: " << l2.back() << "\n";

	std::cout << "List l2 after changes:\n";
	for(auto itr = l2.begin(); itr != l2.end(); itr++){
		std::cout << *itr << " ";
	}
	std::cout << "\n";
		
	l3.pop_back();
	l3.push_back(5);

	std::cout << "List l3:\n";
	for(auto itr = l3.begin(); itr != l3.end(); itr++){
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	

	l.clear();
	l2.clear();
	l3.clear();
	assert(l.size() == 0 && l2.size() == 0 && l3.size() == 0);    
    assert(l.empty() == true && l2.empty() == true && l3.empty() == true);
   
/*---------------------- Testing Constrcutors -------------------------------*/

	List<char> cha;
	cha.push_back('a');
	cha.push_back('b');
	cha.push_back('c');
	cha.push_back('d');
	cha.push_back('e');


	List<char> chu(cha);
	List<char> chi = chu;

	std::cout << "List chi:\n";
	for(auto itr = chi.begin(); itr != chi.end(); itr++){
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	
	std::cout << "List chu:\n";
	for(auto itr = chu.begin(); itr != chu.end(); itr++){
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	
	std::cout << "List cha:\n";
	for(auto itr = cha.begin(); itr != cha.end(); itr++){
		std::cout << *itr << " ";
	}
	std::cout << "\n";




	std::cout << ">>> Exiting with success...\n";

    return EXIT_SUCCESS;

}
