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
                x = C - E;
            else
                x = G - A;
            
            if(B < F)
                y = D - F;
            else
                y = H - B;
            
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
