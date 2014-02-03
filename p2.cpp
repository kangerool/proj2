//meshen, glambeth
//Alice Shen, George Lambeth 
//EECS 280 W14 project 2
//p2.cpp

#include <iostream>
#include <stdlib.h>
#include "recursive.h"
#include "p2.h"



//Helper function for sum
static int sumHelper(list_t list, int currentSum) {
    bool cat = list_isEmpty(list_rest(list));
    if (cat == true) {
       currentSum = currentSum + list_first(list);
       return currentSum;
    }
    currentSum = currentSum + list_first(list);
    return sumHelper(list_rest(list), currentSum);
}

int sum(list_t list){
    /*
    //EFFECTS: returns the sum of each element in list
    //         one if the list is empty.
    */
    if (list_isEmpty(list) == true) {
       return 0;
    }
    return sumHelper(list, 0); //initialize the sum to 0
}

//Helper function for product
static int productHelper(list_t list, int result) {
	if (list_isEmpty(list) == true) {
		return result;
	}
	result *= list_first(list);
	return productHelper(list_rest(list), result);
    
    /* GL
    bool cat = list_isEmpty(list_rest(list));
    if (cat == true) {
       currentProduct = currentProduct + list_first(list);
       return currentProduct;
    }
    currentProduct = currentProduct + list_first(list);
    return sumHelper(list_rest(list), currentProduct);
    */
}

int product(list_t list) {
	int result = 1;
	return productHelper(list, result);
	
    /*
    //EFFECTS: returns the product of each element in list
    //         one if the list is empty.
    */
    
    /* GL
    if (list_isEmpty(list) == true) {
       return 1;
    }
    return productHelper(list, 1);
    */
}



static int accumulateHelper(list_t list, int (*fn)(int, int), int result) {
    if (list_isEmpty(list) == true) {
         return result;
    }
    return accumulateHelper(list_rest(list), fn, fn(result, list_first(list))); 
}

int accumulate(list_t list, int (*fn)(int, int), int identity) {
    /* 
    // REQUIRES: fn must be associative.  // EFFECTS: return identity if list is empty 
    // return fn(list_first(list), 
    // accumulate(list_rest(list), fn, identity)) 
    // otherwise. Be sure to make above code tail-recursive! 
    // 
    // For example, if you have the following function: 
    // 
    // int add(int x, int y); 
    // 
    // Then the following invocation returns the sum of all elements: 
    // 
    // accumulate(list, add, 0);                                                                   
    // 
    // The "identity" argument is typically the value for which 
    // fn(X, identity) == X, for any X. 
    */ 
   if (list_isEmpty(list) == true) {
         return identity;
    }
    return accumulate(list_rest(list), fn, fn(identity, list_first(list))); 
}

static list_t reverseHelper(list_t list, list_t result) {
	if (list_isEmpty(list) == true) {
		return result;
	}
	result = list_make(list_first(list), result);
	return reverseHelper(list_rest(list), result);
}

list_t reverse(list_t list) {
	return reverseHelper(list, list_make());
}



static list_t appendHelper(list_t listA, list_t listB) {
	if (list_isEmpty(listA) == true) {
		return listB;
	}
	listB = list_make(list_first(listA), listB);
	return appendHelper(list_rest(listA), listB);
}
list_t append(list_t listA, list_t listB) {
	return appendHelper(reverse(listA), listB);
}


/*
static list_t oddHelper(list_t list, list_t result) {
	if (list_isEmpty(list) == true) {
		return result;
	}
	if (abs(list_first(list)) % 2 == 1) {
		result = list_make(list_first(list), result);
	}
	return oddHelper(list_rest(list), result);
}
*/

bool isOdd(int x) {
	return (x % 2 == 1);
}
list_t filter_odd(list_t list) {
	return filter(list, isOdd);

	//return reverse(oddHelper(list, list_make()));
}

/*
list_t evenHelper(list_t list, list_t result) {
	if (list_isEmpty(list) == true) {
		return result;
	}
	if (abs(list_first(list)) % 2 == 0) {
		result = list_make(list_first(list), result);
	}
	return evenHelper(list_rest(list), result);
}
*/
static bool isEven(int x) {
	return (x % 2 == 0);
}
list_t filter_even(list_t list) {
	return filter(list, isEven);
	//return reverse(evenHelper(list, list_make()));
}




static list_t filterHelper(list_t list, list_t result, bool (*fn)(int)) {
	if (list_isEmpty(list) == true) {
		return result;
	}
	if (fn(list_first(list)) == true) {
		result = list_make(list_first(list), result);
	}
	return filterHelper(list_rest(list), result, fn);
}

list_t filter(list_t list, bool (*fn)(int)) {
	return reverse(filterHelper(list, list_make(), fn));
}




///
static list_t rotateOnce(list_t list) {
	list_t tempList = list_make(list_first(list), list_make());
	return append(list_rest(list), tempList);
}
list_t rotate(list_t list, unsigned int n ) { 
	if (n == 0) {
		return list;
	}
	list = rotateOnce(list);
	return rotate(list, n - 1);
}
///

static list_t insertHelper(list_t leftReversed, list_t right, list_t second, unsigned int count) {

    if (count == 0) {
        // assemble the result as <left + second + right>
        return append(append(reverse(leftReversed), second),right);
    }
    count --;
    leftReversed = list_make(list_first(right), leftReversed);
    right = list_rest(right);
    return insertHelper(leftReversed, right, second, count);
}



list_t insert_list(list_t first, list_t second, unsigned int n) {
    return insertHelper(list_make(), first, second, n);
}


///


list_t chop(list_t l, unsigned int n) {
    if (n == 0) {
        return l;
    }
    n--;
    return chop(list_rest(reverse(l)), n);
}


int fib(int n){
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fib(n-2) + fib(n - 1);
}// REQUIRES: n >= 0



///

static int tailFibHelper(int secondLast, int last, int count) {

    if (count == 1) {
        return last;
    }

    int lastNew = secondLast + last;
    int secondLastNew = last;
    count--;

    return tailFibHelper(secondLastNew, lastNew, count);
}

int fib_tail(int n) {

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    return tailFibHelper(0, 1, n);
}

 // REQUIRES: n >= 0



int tree_sum(tree_t tree) {
	if (tree_isEmpty(tree) == true) {
		return 0;
	}
	
    return tree_elt(tree) + tree_sum(tree_left(tree)) 
    						+ tree_sum(tree_right(tree));
}


list_t traversal(tree_t tree) {
	if (tree_isEmpty(tree) == true) {
		return list_make();
	}
	return append( traversal(tree_left(tree)), 
					list_make(tree_elt(tree), traversal(tree_right(tree))));
}


static bool covered_by(tree_t A, tree_t B) {
	if (tree_isEmpty(A) == true) {
		return true;
	}
	else if (tree_isEmpty(B) == true) {
		return false;
	} else if (tree_elt(A) != tree_elt(B)) {
		return false;
	}
	return covered_by(tree_left(A), tree_left(B)) 
		 & covered_by(tree_right(A), tree_right(B));
}

bool contained_by(tree_t A, tree_t B) {
	if (covered_by(A, B) == true) {
	return true;
	}
	else if (tree_isEmpty(B) == true) {
		return false;
	}
	tree_t temp1 = tree_right(B);
	tree_t temp2 = tree_left(B);         
	return covered_by(A, temp1) | covered_by(A,temp2);
}

tree_t insert_tree(int elt, tree_t tree) {
	if (tree_isEmpty(tree) == true) {
		return tree_make(elt, tree_make(), tree_make());
	}

	if (elt < tree_elt(tree)) {
		return tree_make(tree_elt(tree), 
						 insert_tree(elt, tree_left(tree)), 
						 tree_right(tree)					);
	}
	else {
		return tree_make(tree_elt(tree), 
						 tree_left(tree), 
						 insert_tree(elt, tree_right(tree)) );
	}

}
