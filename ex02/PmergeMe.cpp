#include "PmergeMe.hpp"

/********** CLASS **********/

PmergeMe::PmergeMe(std::vector<int> sequence) /*: elements(final)*/
{
        for(size_t i = 0; i < sequence.size(); i++)
        {
                stock1.push_back(sequence[i]);
                stock2.push_back(sequence[i]);
        }
        clock_t start, end;

        start = clock();
        sort_vector(stock1);
        end = clock();
        vector_time = ((static_cast<double>((end - start) * 1000000))/ (double)CLOCKS_PER_SEC);

        start = clock();
        sort_deque(stock2);
        end = clock();
        deque_time = ((static_cast<double>((end - start) * 1000000)) / (double)CLOCKS_PER_SEC);
}

/********** ACCESSORS **********/

std::vector<int> PmergeMe::getVector()const 
{
        return stock1;
}

std::deque<int> PmergeMe::getDeque()const 
{
        return stock2;
}

double PmergeMe::GetVectorTime() const 
{
        return(vector_time);
}

double PmergeMe::GetDequeTime() const 
{
        return(deque_time);
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
        (void)copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &src)
{
        (void)src; 
        return(*this);
}

PmergeMe::~PmergeMe() 
{
}

/********** ALGORITHM **********/

void PmergeMe::sort_vector(std::vector<int> &sequence)
{
        if(sequence.size() < 2)
                return;
        int mediane = sequence.size() / 2;
        std::vector<int> first (sequence.begin(), sequence.begin() + mediane);
        std::vector<int> second (sequence.begin() + mediane, sequence.end());

        sort_vector(first);
        sort_vector(second);

        size_t i = 0;
        size_t j = 0;
        size_t l = 0;
        while(i < first.size() && j < second.size())
        {
                if(first[i] < second[j])
                        sequence[l++] = first[i++];
                else
                        sequence[l++] = second[j++];
        }
        while(i < first.size())
                sequence[l++] = first[i++];
        while(j < second.size())
                sequence[l++] = second[j++];
}

void PmergeMe::sort_deque(std::deque<int> &sequence)
{
        if(sequence.size() < 2)
                return;
        int mediane = sequence.size() / 2;
        std::deque<int> first (sequence.begin(), sequence.begin() + mediane);
        std::deque<int> second (sequence.begin() + mediane, sequence.end());

        sort_deque(first);
        sort_deque(second);

        size_t i = 0;
        size_t j = 0;
        size_t l = 0;
        while(i < first.size() && j < second.size())
        {
                if(first[i] < second[j])
                        sequence[l++] = first[i++];
                else
                        sequence[l++] = second[j++];
        }
        while(i < first.size())
                sequence[l++] = first[i++];
        while(j < second.size())
                sequence[l++] = second[j++];
}