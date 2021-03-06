#include <iostream>
#include <vector>

/*
    Given a 2-D boolean array, find the largest square subarray of
    true values. The return value should be the side length of the
    largest square subarray
*/

int square_matrix(const std::vector<std::vector<int>>& v)
{
    int i, j, max = 0;
    int **cache;

    cache = new int*[v.size()];
    for(i = 0; i < v.size(); i++)
        cache[i] = new int[v[0].size()];

    for(i = 0; i < v.size(); i++)
    {
        for(j = 0; j < v[0].size(); j++)
        {
            if(i == 0 || j == 0)
            {
                if(v[i][j])
                    cache[i][j] = 1;
                else
                    cache[i][j] = 0;
            }
            else if(v[i][j])
            {
                cache[i][j] = 1 + std::min(std::min(cache[i][j - 1], cache[i - 1][j]), cache[i - 1][j - 1]);
            }
            if(cache[i][j] > max)
                max = cache[i][j];
        }
    }

    return max;                         
}

int main(void)
{
    std::vector<std::vector<int>> v1{ { 1, 0, 0, 0 },
                                      { 1, 1, 1, 1 },
                                      { 1, 1, 1, 1 },
                                      { 1, 1, 1, 1 }
                                    };
    std::vector<std::vector<int>> v2{ { 1, 1, 1, 1 },
                                      { 1, 1, 1, 1 },
                                      { 1, 1, 1, 1 },
                                      { 1, 1, 1, 1 }
                                    };
    std::vector<std::vector<int>> v3{ { 1, 1, 0, 0 },
                                      { 1, 1, 0, 0 },
                                      { 1, 1, 1, 0 },
                                      { 1, 1, 1, 0 }
                                    };
    std::vector<std::vector<int>> v4{ { 0, 0, 0, 0 },
                                      { 0, 0, 0, 0 },
                                      { 0, 0, 0, 0 },
                                      { 0, 0, 0, 0 }
                                    };
    std::vector<std::vector<int>> v5{ { 0, 0, 0, 0 },
                                      { 0, 1, 1, 0 },
                                      { 0, 1, 1, 0 },
                                      { 0, 0, 0, 0 }
                                    };

    std::cout << square_matrix(v1) << std::endl;
    std::cout << square_matrix(v2) << std::endl;
    std::cout << square_matrix(v3) << std::endl;
    std::cout << square_matrix(v4) << std::endl;
    std::cout << square_matrix(v5) << std::endl;
    
    return 0;
}
