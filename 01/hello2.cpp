//
// Created by danter on 2016-09-07.
//

#include <iostream>

void hello (std::pair<const char *, int> pair){
    std::cout << "Hello ";
      for (int i = 0; i < pair.second; i++)
        std::cout << pair.first << " ";
      std::cout << "\n";
    }



std::pair<const char *, int> parse_args (int argc, char * argv[]){
  
    if (argc == 1)
        //The program itself is the first argument, argv[0], so argc is always at least 1.
        std::cerr << "du e zigenare?" << std::endl;
        return std::make_pair(NULL, -1); // om inga argument har skickats med
    else if (argc == 2)
        return std::make_pair( argv[1] , 0 )
    else if (argc == 3)
        if (std::atol(argv[2]))   // atol returnerar 0 om det inte går att göra om till en long int
            return std::make_pair(argv[1], std::atol (argv[2]))
        else
            std::cerr << "inget giltigt heltal har angivits" << std::endl;
            return std::make_pair( NULL, -1); // 5 : fel om andra argumentet går att göra om till  en long int
    else
        std::cerr << " för många argument" << std::endl;
      return std::make_pair(NULL,-1 ); // 10: fel om argc > 3
    
    }
}


