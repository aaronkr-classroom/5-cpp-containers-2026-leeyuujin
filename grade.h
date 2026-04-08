#pragma once
//grande.h

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"
#include <list>

using std::vector; //추가
using std::list

double grade(double, double, const vector<double>&);
double grade(double, double, double);
double grade(const Student_info&);

bool fgrande(const Student_info&);
vector<Student_info> extract_fails(vector<Student_info>&);
list<Student_info> extract_fails(list<Student_info>&);



#endif // !GUARD_grade_h
