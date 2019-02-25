#include<bits/stdc++.h>
using namespace std;

void LRUmissCount(int *pages, int max_cache_size, int length_of_pages)
{
    deque<int> dq;
    deque<int> ::iterator dqitr;
    int missCount = 0;
    for(int index=0; index<length_of_pages; index++)
    {
        if(dq.empty() || dq.size() != max_cache_size)
        {
            dq.push_front(pages[index]);
            missCount++;
        }
        else if(dq.size() == max_cache_size)
        {
            bool found = false;
            for(dqitr=dq.begin(); dqitr!=dq.end(); dqitr++)
            {
                if(*dqitr == pages[index])
                {
                    found = true;
                    break;
                }
            }

            if(found)
            {
                dq.erase(dqitr);
                dq.push_front(pages[index]);
            }
            else
            {
                dq.pop_back();
                dq.push_front(pages[index]);
                missCount++;
            }
            
        }
    }
    cout<<missCount<<endl;
}

int main()
{
    int pages1[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0};
    int pages2[] = {2,3,1,3,2,1,4,3,2};
    int size1 = 3, size2 = 2, pages1_count = 16, pages2_count = 9;
    LRUmissCount(pages1, size1, pages1_count);
    LRUmissCount(pages2, size2, pages2_count);
    return 0;
}