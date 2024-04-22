/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergMe.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:32 by emohamed          #+#    #+#             */
/*   Updated: 2024/04/22 12:14:06 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void printDeque(std::deque<int> deq){
    for (size_t i = 0; i < deq.size(); i++)
    {
        std::cout <<  deq[i] <<   " ";
    }
}

void Print_deq_of_deq(std::deque<std::deque<int> > deq){
    for (size_t i = 0; i < deq.size(); i++)
    {
        printDeque(deq[i]);
    }
}
void printVec(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout <<  vec[i] <<   " ";
    }
}
void Print_vec_of_vec(std::vector<std::vector<int> > vec){
    for (size_t i = 0; i < vec.size(); i++)
    {
        printVec(vec[i]);
    }
}
std::vector<int> mergeVec(std::vector<int> vec1, std::vector<int> vec2)
{
    std::vector<int> new_vec;

    if (vec1.back() < vec2.back())
    {
        new_vec.insert(new_vec.end(), vec1.begin(), vec1.end());
        new_vec.insert(new_vec.end(), vec2.begin(), vec2.end());
    }
    else
    {
        new_vec.insert(new_vec.end(), vec2.begin(), vec2.end());
        new_vec.insert(new_vec.end(), vec1.begin(), vec1.end());
    }
    
    return new_vec;
}

std::deque<int> mergeDeque(std::deque<int> deq1, std::deque<int> deq2)
{
    std::deque<int> new_deq;

    if (deq1.back() < deq2.back())
    {
        new_deq.insert(new_deq.end(), deq1.begin(), deq1.end());
        new_deq.insert(new_deq.end(), deq2.begin(), deq2.end());
    }
    else
    {
        new_deq.insert(new_deq.end(), deq2.begin(), deq2.end());
        new_deq.insert(new_deq.end(), deq1.begin(), deq1.end());
    }
    
    return new_deq;
}

