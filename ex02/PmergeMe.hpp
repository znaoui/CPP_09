#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <string>
# include <sstream>
# include <ctime>
# include <deque>

// +------------------------------------------------------------------------------+
//                               CLASS PmergeMe                                   |
// +------------------------------------------------------------------------------+


class PmergeMe
{
        private:
                std::vector<int> stock1;
                std::deque<int> stock2;
                double vector_time;
                double deque_time;
        public:
                PmergeMe(PmergeMe const &copy);
                PmergeMe& operator=(PmergeMe const &src);
                PmergeMe(std::vector<int> final);
                ~PmergeMe();

                void sort_deque(std::deque<int> &sequence);
                void sort_vector(std::vector<int> &sequence);
                std::vector<int> getVector()const;
                std::deque<int> getDeque() const;
                double GetVectorTime() const;
                double GetDequeTime() const;
};

#endif