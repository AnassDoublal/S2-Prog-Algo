#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <numeric>

std::string random_name(size_t size);

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size);

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(const std::vector<std::pair<std::string, float>>& robots_fixes);

float sum_vector(const std::vector<float>& vec);