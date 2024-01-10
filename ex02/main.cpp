/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:26 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/10 15:06:43 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int check_isnumber(char **av){
    for(int check = 1; av[check]; check++){
        for(int i = 0; av[check][i]; i++){
            if (!isdigit(av[check][i])){
                std::cerr << "Error: bad input => " << av[check] << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

std::vector<std::vector<int> > pairing(std::vector<std::vector<int> > vec) {
    if (vec.size() == 1) {
        return vec;
    }
    
    if (vec.size() % 2 != 0){
        std::cerr << "Error: bad input => " << vec.size() << std::endl;
        exit(0);
    }
    std::vector<std::vector<int> > result;
    for (size_t i = 0; i < vec.size(); i += 2){
        std::vector<int> tmp;
        for (size_t j = 0; j < vec[i].size(); j++){
            tmp.push_back(vec[i][j]);
            tmp.push_back(vec[i + 1][j]);
        }
        sort(tmp.begin(), tmp.end());
        result.push_back(tmp);
    }
    return pairing(result);
}
int main(int ac, char **av){
    if(ac < 2){
        std::cerr << "U need at least 2 elements" << std::endl;
    }
        if (!check_isnumber(av))
            return 0;
        std::vector<std::vector<int> > main_v;
        for(int i = 1; i < ac; i++){
            std::vector<int> vectored;
            int num = std::atoi(av[i]);
            vectored.push_back(num);
            main_v.push_back(vectored);
        }
        std::vector<std::vector<int> > result = pairing(main_v);
        for(size_t i = 0; i < result.size(); i++){
            for(size_t j = 0; j < result[i].size(); j++){
                std::cout << result[i][j] << " ";
            }
        }
        std::cout << std::endl;
}