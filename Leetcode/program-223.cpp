#include <iostream>

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1, area2, area3 = 0, area, x, y;
        
        area1 = (C - A) * (D - B);
        area2 = (G - E) * (H - F);
        
        if(A < G && B < H && E < C && F < D)
        {
            // Overlap
            if(A < E)
                x = std::min(G - E, C - E);
            else
                x = std::min(G - A, C - A);
            
            if(B < F)
                y = std::min(D - F, H - F);
            else
                y = std::min(H - B, D - B);
            
            area3 = x * y;
            
            area = area1 + area2 - area3;
        }
        else
        {
            // No overlap
            area = area1 + area2;
        }
        
        return area;
    }
};

int main(void)
{
    Solution s;

    std::cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << std::endl;

    return 0;
}
