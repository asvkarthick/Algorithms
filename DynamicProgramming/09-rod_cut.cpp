#include <iostream>

/*
    Algorithm:

    Given a rod of length n inches and a table of prices p[i] for i = 1, 2, ... n
    Determine the maximum revenue r[n] obtainable by cutting up the rod and selling
    the pieces. Note that if the price p[n] is large enough, an optimal solution
    may require no cutting at all
*/

int rod_cut(int *p, int *r, int n)
{
    int q = 0;

    q = p[n];
    for(int i = 1; i < n; i++)
        q = std::max(q, p[i] + r[n- i]);
    r[n] = q;

    return q;
}

int main(void)
{
    int p[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
    int optimal_revenue[11];

    optimal_revenue[0] = 0;

    for(int i = 0; i < 10; i++)
    {
        optimal_revenue[i + 1] = rod_cut(p, optimal_revenue, i + 1);
        std::cout << "Revenue[" << i + 1 << "] = " << optimal_revenue[i + 1] << std::endl;
    }

    return 0;
}
