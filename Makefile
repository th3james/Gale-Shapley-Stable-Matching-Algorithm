all:
	clang++ -std=c++14 pair.cpp opinionated_entity.cpp uni_student_pair_set.cpp -o pair
	./pair
