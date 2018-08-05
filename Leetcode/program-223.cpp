#include <iostream>

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1, area2, area3 = 0;
        
        area1 = (C - A) * (D - B);
        area2 = (G - E) * (H - F);
        if(C > E && H > B)
            area3 = (C - E) * (H - B);
        
        return area1 + area2 - area3;
    }
};
