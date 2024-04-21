/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:26 by emohamed          #+#    #+#             */
/*   Updated: 2024/04/21 15:44:07 by emohamed         ###   ########.fr       */
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
void printVec(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void pairElements(std::vector<std::vector<int> >& main_vector)
{
    if (main_vector.size() == 1)
    {
        std::cerr << "FORWARD RECUSION END\n";
        return; 
    }
    
    std::vector<std::vector<int> > new_vector;
    std::vector<int> remain_vector;
    
    if (main_vector.size() % 2 != 0) {
        remain_vector = main_vector[main_vector.size() - 1];
        main_vector.pop_back();
    }
    
    for (size_t i = 0; i < main_vector.size(); i += 2) {
        // if (i + 1 < main_vector.size()) { 
            std::vector<int> pair = mergeVec(main_vector[i], main_vector[i + 1]);
            // pair.push_back(main_vector[i][0]);
            // pair.push_back(main_vector[i + 1][0]);
            // std::sort(pair.begin(), pair.end());
            new_vector.push_back(pair);
        // } else {
        //       new_vector.push_back(main_vector[i]);
    
        // }
    }
    
    main_vector = new_vector;
    
    pairElements(main_vector);

    // step 2

    std::cerr << "REVERSE RECUSION START\n";
    printVec(remain_vector);
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
    
    pairElements(main_vector);
    
    for(std::vector<std::vector<int> >::iterator it = main_vector.begin(); it != main_vector.end(); it++){
        for(std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++){
            std::cout << *it2 << " ";
        }
    }
    
    return 0;
}