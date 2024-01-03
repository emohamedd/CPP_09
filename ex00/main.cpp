/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:59:35 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/03 16:20:29 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
    // std::ifstream file;
    std::ifstream file2;
    if(argc != 2){
        std::cout << "Usage: ./bitcoin [input_file]" << std::endl;
        return 1;
    }

    file2.open(argv[1]);
    // file.open("data.csv");

    if(!file2.is_open()){
        std::cout << "Error opening input.txt" << std::endl;
        return 1;
    }
    // if(!file.is_open()){
    //     std::cout << "Error opening data.csv" << std::endl;
    //     return 1;
    // }

    std::string line2;
    std::string top2;
    std::getline(file2, top2);
    if(top2 != "date | value"){
        std::cout << "Error: input.txt is not in the correct format" << std::endl;
        return 1;
    }
    std::map<std::string, std::string> data2;
    while(std::getline(file2, line2)){
        std::stringstream ss(line2);
        std::string date;
        std::string price;
        std::getline(ss, date, '|');
        std::getline(ss, price, '|');
        data2[date] = price;
    }
    for(std::map<std::string, std::string>::iterator it = data2.begin(); it != data2.end(); ++it){

        int lenght = it->first.size();
        if(it->first[lenght - 1] != ' ' || it->second[0] != ' '){
            std::cout << "Error: input.txt is not in the correct format" << std::endl;
            return 1;
        }
        if(it->first.size() != 11){
            std::cout << "Error: input.txt is not in the correct format" << std::endl;
            return 1;
        }
        if(it->first[4] != '-' || it->first[7] != '-'){
            std::cout << "Error: input.txt is not in the correct format" << std::endl;
            return 1;
        }
       for(size_t i = 0; i < it->second.length(); i++){
           if(it->second[i] == ' '){
               i++;
            if(!isalnum(it->second[i])){
                std::cout << "Error: input.txt is not in the correct format" << std::endl;
                return 1;
            }
            if(atof(it->second.c_str() + i) == 0){
                std::cout << "Error: input.txt is not in the correct format" << std::endl;
                return 1;
            }
           }
       }
        
    }
    file2.close();
    // std::string line;
    // std::string top;
    // std::getline(file, top);
    // std::map<std::string, std::string> data;
    // while(std::getline(file, line)){
    //     std::stringstream ss(line);
    //     std::string date;
    //     std::string price;
    //     std::getline(ss, date, ',');
    //     std::getline(ss, price, ',');
    //     data.insert(std::make_pair(date, price));
    // }
    
    // file.close();
}