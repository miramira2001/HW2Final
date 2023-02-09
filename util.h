#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

template <typename T>
std::set<T> setIntersection(std::set<T>& set1, std::set<T>& set2)
{
std::set<T> result;
auto it1 = set1.begin();
while (it1 != set1.end())
{
if (set2.find(*it1) != set2.end())
{
result.insert(*it1);
}
++it1;
}
return result;
}

template <typename T>
std::set<T> setUnion(std::set<T>& set1, std::set<T>& set2)
{
std::set<T> result = set1;
auto it2 = set2.begin();
while (it2 != set2.end())
{
result.insert(*it2);
++it2;
}
return result;
}

std::string convToLower(std::string src);

std::setstd::string parseStringToWords(std::string line);

std::string ltrim(std::string s);

std::string rtrim(std::string s);

std::string trim(std::string s);