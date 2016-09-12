//
// Created by aleter on 2016-09-07.
//

#include <utility>
#include <iostream>
#include "hello.h"


void hello(const char* name ,int  pair){
    std::cout << "Hello," ;
    
    for (int i = 0; i < pair; i++){
        std::cout << " " << name ;
    }
    std::cout << "!" << "\n";
   
    }




std::pair<const char *, int> parse_args (int argc, char* argv[]){
    if (argc == 1){
        const char * cp = "world";
        //The program itself is the first argument, argv[0], so argc is always at least 1.
        return std::make_pair(cp, 1);
    }// om inga argument har skickats med
    else if (argc == 2){
        
        return std::make_pair(argv[1] , 1 );
    }
    
    else if (argc == 3){
        if (argv[2] == (std::string("0")) ){
            return std::make_pair(argv[1],-1 );
        }
    
        else if (std::atol(argv[2])){
            // atol returnerar 0 om det inte går att göra om till en long int
            if (std::atol(argv[2]) < 0  ){
                std::cerr << "inga negativa tal" <<std::endl;
                return std:: make_pair(argv[1], -1);
            }
            else {
                return std::make_pair(argv[1], std::atoi (argv[2]));
            
            }
            
            
        }
        
        else{
            std::cerr << "inget giltigt heltal har angivits" << std::endl;
            return std::make_pair( argv[0], -1); // 5 : fel om andra argumentet går att göra om till  en long int
        }
    }
    else{
        std::cerr << " för många argument" << std::endl;
      return std::make_pair(argv[0],-1 ); // 10: fel om argc > 3
    }
    
    
}


