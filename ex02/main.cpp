/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:26 by emohamed          #+#    #+#             */
/*   Updated: 2024/04/22 17:42:08 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


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

void splitDeque(std::deque<std::deque<int> >& deq, std::deque<int> remain_deque, std::deque<std::deque<int> > chain, std::deque<std::deque<int> > pend){
    
    if (deq.empty()) {
        return;
    }
   std::deque<std::deque<int> > newDeq;
    for (std::deque<std::deque<int> >::iterator it = deq.begin(); it != deq.end(); ++it) {
        size_t mid = it->size() / 2;
        std::deque<int> deq1(it->begin(), it->begin() + mid);
        std::deque<int> deq2(it->begin() + mid, it->end());
        newDeq.push_back(deq1);
        newDeq.push_back(deq2);
    }
    deq = newDeq;
    for(size_t i = 0; i < deq.size(); i++){
        if (i % 2 == 0) {
            chain.push_back(deq[i]);
        } else {
            pend.push_back(deq[i]);
        }
    }
        if (!remain_deque.empty()) {
            pend.push_back(remain_deque);
        }
    
    for (size_t i = 0; i < pend.size(); i++) {
        std::deque<std::deque<int> >::iterator it = std::lower_bound(chain.begin(), chain.end(), pend[i]);
        chain.insert(it, pend[i]);
    }
    deq = chain;
}

void Ford_J(std::vector<std::vector<int> >& main_vector)
{
    if (main_vector.size() == 1)
    {
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

void Ford_J_deque(std::deque<std::deque<int> >& main_deque)
{
    if (main_deque.size() == 1)
    {
        return; 
    }

    std::deque<std::deque<int> > new_deque;
    std::deque<int> remain_deque;
    
    if (main_deque.size() % 2 != 0) {
        remain_deque = main_deque[main_deque.size() - 1];
        main_deque.pop_back();
    }
    
    for (size_t i = 0; i < main_deque.size(); i += 2) {
            std::deque<int> pair = mergeDeque(main_deque[i], main_deque[i + 1]);
            new_deque.push_back(pair);
    }
    
    main_deque = new_deque;
    
    Ford_J_deque(main_deque);
    
    std::deque< std::deque<int> > pend;
    std::deque< std::deque<int> > chain;
    splitDeque(main_deque, remain_deque, chain, pend);
}

int main(int ac, char **av){
    if(ac <= 2){
        std::cerr << "U need at least 2 elements" << std::endl;
        exit(1);
    }
    check_isnumber(av);
    
    std::vector<std::vector<int> > main_vector;
    std::deque<std::deque<int> > main_deque;

    for(int i = 1; i < ac; i++){
        std::deque<int> sub_deque;
        int num = std::stoi(av[i]);
        sub_deque.push_back(num);
        main_deque.push_back(sub_deque);
    }
    
    for(int i = 1; i < ac; i++){
        std::vector<int> sub_vector;
        int num = std::stoi(av[i]);
        sub_vector.push_back(num);
        main_vector.push_back(sub_vector);
    }
    std::cout << RED << " ----> :  BEFORE : <---- "  <<  RESET <<std::endl;
    Print_vec_of_vec(main_vector);
    double start = static_cast<double>(std::clock()) / CLOCKS_PER_SEC;
    Ford_J(main_vector);
    double end = static_cast<double>(std::clock()) / CLOCKS_PER_SEC;
    double start_deque = static_cast<double>(std::clock()) / CLOCKS_PER_SEC;
    Ford_J_deque(main_deque);
    double end_deque = static_cast<double>(std::clock()) / CLOCKS_PER_SEC;
    double duration_deque = (end_deque - start_deque);
    double duration = (end - start);
    std::cout << std::endl;
    std::cout << GREEN << " ----> :  AFTER : <---- "  <<  RESET <<std::endl;
    Print_vec_of_vec(main_vector);
    std::cout << std::endl;
    std::cout  << YELLOW << "Time to process a range of " << main_vector.size() << " elements with std::vector : " << duration << " us\n";
    std::cout  << YELLOW << "Time to process a range of " << main_deque.size() << " elements with std::deque : " << duration_deque << " us\n";
    return 0;
}