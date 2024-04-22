/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:26 by emohamed          #+#    #+#             */
/*   Updated: 2024/04/22 11:07:20 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

void check_isnumber(char **av){
    for(int check = 1; av[check]; check++){
        for(int i = 0; av[check][i]; i++){
            if (!isdigit(av[check][i])){
                std::cerr << "Error: bad input => " << av[check] << std::endl;
                exit(1);
            }
        }
    }
}

void printVec(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
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

void splitVector(std::vector<std::vector<int> >& vec, std::vector<int> remain_vector, std::vector<std::vector<int> > chain, std::vector<std::vector<int> > pend){
    
    if (vec.empty()) {
        return;
    }
   std::vector<std::vector<int> > newVec;
    for (std::vector<std::vector<int> >::iterator it = vec.begin(); it != vec.end(); ++it) {
        size_t mid = it->size() / 2;
        std::vector<int> vec1(it->begin(), it->begin() + mid);
        std::vector<int> vec2(it->begin() + mid, it->end());
        newVec.push_back(vec1);
        newVec.push_back(vec2);
    }
    vec = newVec;
    for(size_t i = 0; i < vec.size(); i++){
        if (i % 2 == 0) {
            chain.push_back(vec[i]);
        } else {
            pend.push_back(vec[i]);
        }
    }
        if (!remain_vector.empty()) {
            pend.push_back(remain_vector);
        }
    
    for (size_t i = 0; i < pend.size(); i++) {
        std::vector<std::vector<int> >::iterator it = std::lower_bound(chain.begin(), chain.end(), pend[i]);
        chain.insert(it, pend[i]);
    }
    vec = chain;
}

void Ford_J(std::vector<std::vector<int> >& main_vector)
{
    if (main_vector.size() == 1)
    {
        // std::cerr << "FORWARD RECUSION END\n";
        return; 
    }
    
    std::vector<std::vector<int> > new_vector;
    std::vector<int> remain_vector;
    
    if (main_vector.size() % 2 != 0) {
        remain_vector = main_vector[main_vector.size() - 1];
        main_vector.pop_back();
    }
    
    for (size_t i = 0; i < main_vector.size(); i += 2) {
            std::vector<int> pair = mergeVec(main_vector[i], main_vector[i + 1]);
            new_vector.push_back(pair);
    }
    
    main_vector = new_vector;
    
    Ford_J(main_vector);
    
    std::vector< std::vector<int> > pend;
    std::vector< std::vector<int> > chain;
    splitVector(main_vector, remain_vector, chain, pend);
}

int main(int ac, char **av){
    if(ac <= 2){
        std::cerr << "U need at least 2 elements" << std::endl;
        exit(1);
    }
    check_isnumber(av);
    
    std::vector<std::vector<int> > main_vector;
    
    for(int i = 1; i < ac; i++){
        std::vector<int> sub_vector;
        int num = std::stoi(av[i]);
        sub_vector.push_back(num);
        main_vector.push_back(sub_vector);
    }
    
    std::cout << RED << "---- Before : ----"  <<  RESET <<std::endl;
    Print_vec_of_vec(main_vector);
    Ford_J(main_vector);
    std::cout << std::endl;
    std::cout << GREEN << "---- After : ----"  <<  RESET <<std::endl;
    Print_vec_of_vec(main_vector);
    
    return 0;
}