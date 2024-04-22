/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:30 by emohamed          #+#    #+#             */
/*   Updated: 2024/04/22 12:14:34 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <ctime>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

void check_isnumber(char **av);
void Ford_J(std::vector<std::vector<int> >& main_vector);
void Ford_J_deque(std::deque<std::deque<int> >& main_deque);
void printDeque(std::deque<int> deq);
void Print_deq_of_deq(std::deque<std::deque<int> > deq);
void printVec(std::vector<int> vec);
void Print_vec_of_vec(std::vector<std::vector<int> > vec);
std::vector<int> mergeVec(std::vector<int> vec1, std::vector<int> vec2);
std::deque<int> mergeDeque(std::deque<int> deq1, std::deque<int> deq2);
