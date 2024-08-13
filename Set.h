#pragma once
//Abstrac class


class Set {

public:

	virtual void insert_elem(long long key_i) = 0; // Function which inserts concrete element in set.
	virtual bool search_elem(long long key_s)const = 0;// Function which searchs element by parametar key of element. 
	virtual void delete_elem(long long key_d) = 0; // Function which deletes concrete element by parametar key.
	virtual void delete_elem_scope(long long a, long long b) = 0;// Function which deletes all elements from set which are in segment of [a,b].
	virtual long long number_elem()const = 0; // Function which returns number of elements in set.

};