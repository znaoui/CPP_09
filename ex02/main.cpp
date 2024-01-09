#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
        if(argc < 2)
                return(std::cout << "Error: Number of Arguments is not valid\n", 1);

        std::vector<int> sequence;
        for (int i = 1; i < argc; ++i) 
        {
                std::istringstream iss(argv[i]);
                std::string arg = argv[i];
                size_t pos = arg.find_first_not_of("0123456789 ");
                int n; 
                if (!(iss >> n) || n < 0 || pos !=  std::string::npos)
                        return (std::cerr << "Error: Invalid input sequence" << std::endl, 1);
                sequence.push_back(n);
        }
        PmergeMe a(sequence);
        std::cout << "\033[1;31mBefore: \033[1;32m";
        for (size_t i = 1; i < argc; i++)
                std::cout << argv[i] << " ";
        std::cout << std::endl;
        std::cout << "\033[1;31mAfter for Vector: \033[1;32m";
        for (size_t i = 0; i < a.getVector().size(); ++i)
                std::cout << " " << a.getVector()[i];
        std::cout << std::endl;
        std::cout << "\033[1;31mAfter for Deque: \033[1;32m";
        for (size_t i = 0; i < a.getDeque().size(); ++i)
                std::cout << " " << a.getDeque()[i];
        std::cout << "\033[0m" << std::endl;
        std::cout << "Time to process a range of \033[1;31m" << a.getVector().size() << "\033[0m elements with std::vector: \033[1;31m" << a.GetVectorTime() << "\033[0m us" << std::endl;
        std::cout << "Time to process a range of \033[1;31m" << a.getVector().size() << "\033[0m elements with std::deque: \033[1;31m" << a.GetDequeTime() << "\033[0m us" << std::endl;
}