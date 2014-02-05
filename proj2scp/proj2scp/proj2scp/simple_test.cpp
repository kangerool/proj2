#include <iostream>
#include "p2.h"

using namespace std;

void list_juggle() {
    list_t list (list_make());
    for (int i (1000); i--;) list = list_make(i, list);
    
    int count (0);
 
        list = reverse(list);
        cout << ++count << endl;
    }
}
bool tree_equal(tree_t t1, tree_t t2)
    // EFFECTS: returns true iff t1 == t2
{
    if (tree_isEmpty(t1) && tree_isEmpty(t2)) {
	return true;
    } else if (tree_isEmpty(t1) || tree_isEmpty(t2)) {
	return false;
    } else {
	return ((tree_elt(t1) == tree_elt(t2)) 
		&& tree_equal(tree_left(t1), tree_left(t2))
		&& tree_equal(tree_right(t1), tree_right(t2)));
    }
}
bool isPrime(int x)
    // EFFECTS: returns true if x is prime, false otherwise.
{
    const int limit = x/2;
    for (int i = 2; i<=limit; i++) {
	if ((x%i) == 0) {
	    return false;
	}
    }
    return true;
}

bool list_equal(list_t l1, list_t l2)
    // EFFECTS: returns true iff l1 == l2.
{
    if (list_isEmpty(l1) && list_isEmpty(l2)) {
	return true;
    } else if (list_isEmpty(l1) || list_isEmpty(l2)) {
	return false;
    } else if (list_first(l1) != list_first(l2)) {
	return false;
    } else {
	return list_equal(list_rest(l1), list_rest(l2));
    }    
}    


int add(int x, int y) {
	return x+y;
}
int mult(int x, int y) {
    return x*y;
}
int power(int base,  int power) {
	int result = 1;
	while (power > 0 ) {
	result = base* result;
	power--;
	}
	return result;
}
int pro(int a, int b) {
	return (a*b);
}


int main()
{
    list_juggle;
    int i;
    list_t listA;
    list_t listB;

    listA = list_make();
    listB = list_make();

    for (i = 5; i>0; --i) {
	listA = list_make(i, listA);
	listB = list_make(i+10, listB);
    }
    

    list_print(listA);
    cout << endl;
    cout<< sum(listA);
    cout << endl;
        cout << "empty sum  " << sum(list_make()) << endl;
    cout << "product  " << product(listA) << endl;
    	cout << "empty product  " << product(list_make()) << endl;
    cout << endl;   
    list_t listC = list_make(5, list_make());
    list_print(listC);
    cout << "one elm list acculm produc  " << accumulate(listC, mult,1) << endl;
    cout << "one elm list acculm add  " << accumulate(listC, add,0) << endl;
   listC = list_make(0, list_make());
    list_print(listC);
    cout << "one elm list acculm produc  " << accumulate(listC, mult,1) << endl;
    cout << "one elm list acculm add  " << accumulate(listC, add,0) << endl;

	//cout << accumulate(listA);
	cout << "acc A add " << accumulate(listA,add, 0 );
	    cout << endl; 
	    	cout << "acc A product " << accumulate(listA,pro, 1 );
	    cout << endl; 
	    
	    cout << "power (2,3) = " << power(2,3);
	cout << "  acc A power " << accumulate(listA, power, 1);
	    cout << endl; 
    cout << endl << endl;   
    
    
    list_print(listB);
    cout << endl;
	cout<< sum(listB);
    cout << endl;
    cout << product(listB);
    cout << endl;   
	cout << "acc B add " << accumulate(listB,add, 0 );
	    cout << endl; 
	    cout << "acc B product " << accumulate(listB,pro, 1 );
	    cout << endl; 
	cout << "acc B power " << accumulate(listB, power, 1);
	    cout << endl; 
	listB = list_make(0, listB);
	cout << "updated B " << endl;
	list_print(listB) ;
	cout<< endl << "sum B is  " << sum(listB);
    cout << endl;
    	cout << "acc B add " << accumulate(listB,add, 0 ) << endl;
    cout << product(listB);
    cout << endl;   
	cout << "acculm empty product " <<accumulate(list_make(), pro, 1);
	cout << endl<< "acculm empty sum " << accumulate(list_make(), add, 0);
	
	
    cout << endl << endl;   
    
    
    
    
    list_print(reverse(listA));
    cout << endl;
    list_print(append(listA, listB));
    cout << endl;
    
    //filters 
    cout << "now the filter test part begins! " << endl;
    int numbers[] = { 3, 20, 46, 43, 9, 17, 103, 102 };
    const int numSize = sizeof(numbers)/sizeof(int);
    int primes[] = { 3, 43, 17, 103 };
    const int primeSize = sizeof(primes)/sizeof(int);

    list_t listNums = list_make();
    list_t listPrimes = list_make();
    list_t candidate;


    for (int i = 0; i<numSize; i++) {
	listNums = list_make(numbers[numSize-i-1], listNums); 
    }

    for (int i = 0; i<primeSize; i++) {
	listPrimes = list_make(primes[primeSize-i-1], listPrimes); 
    }
	
    candidate = filter(listNums, isPrime);

    list_print(candidate);
    cout << endl;

    list_print(listPrimes);
    cout << endl;

    if (list_equal(candidate, listPrimes)) {
	cout << "Success!\n";
//	return 0;
    } else {
	cout << "Failed\n";
//	return -1;
    }
    cout << endl << "filter test, Official. ENDS " << endl;
    
    //Tree Test, Official
    cout << endl << "Tree Test, Official " << endl;
        tree_t start = tree_make(2,
			     tree_make(1, tree_make(), tree_make()),
			     tree_make(4, tree_make(), tree_make()));
    tree_t end = tree_make(2,
			   tree_make(1, tree_make(), tree_make()),
			   tree_make(4, 
				     tree_make(3, tree_make(), tree_make()),
				     tree_make()));

    tree_t candidate2 = insert_tree(3, start);

    tree_print(end);
    cout << endl;

    tree_print(candidate2);
    cout << endl;

    if (tree_equal(candidate2, end)) {
	cout << "Success!\n";
	return 0;
    } else {
	cout << "Failed\n";
	return -1;
    }
    
    cout << endl<< "Tree Test, Official ENDS " << endl;
    
    
}
