/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:59:35 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/04 09:38:15 by emohamed         ###   ########.fr       */
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
            std::cerr << "Error: input.txt is not in the correct format" << std::endl;
            return 1;
        }
        if(it->first.size() != 11){
            std::cerr << "Error: input.txt is not in the correct format" << std::endl;
            return 1;
        }
        if(it->first[4] != '-' || it->first[7] != '-'){
            std::cerr << "Error: input.txt is not in the correct format" << std::endl;
            return 1;
        }
        for(size_t j = 0; j < it->first.length(); j++){
            if(j == '-' || j == ' '){
                j++;
            }
            if(isalpha(it->first[j])){
                std::cerr << "Error: input.txt is not in the correct format" << std::endl;
                return 1;
            }
        }
        for(size_t i = 0; i < it->second.length(); i++){
           if(it->second[i] == ' '){
               i++;
            if(isalpha(it->second[i]) || !isdigit(it->second[i])){
                std::cerr << "Error: input.txt is not in the correct" << std::endl;
                return 1;
            }
            if(atof(it->second.c_str() + i) == 0 || atof(it->second.c_str() + i) > 1000){
                std::cerr << "Error: input.txt is not in the correct format" << std::endl;
                return 1;
            }
           }
       }
        std::stringstream new_(it->first);
        std::string year, mounth, day;
        std::getline(new_, year, '-');
        std::getline(new_, mounth, '-');
        std::getline(new_, day, ' ');
        if(is_valid_date(year, mounth, day) == 0){
            std::cerr << "Error: Invalid Date" << std::endl;
            return 1;
        }
    }
    file2.close();
}
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
